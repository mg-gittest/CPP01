#include "stdafx.h"
#include "chapter17bitstream.h"
#include <ostream>

namespace mg_cpp14 {

	// fetch the type
	using out_t = std::ostream::char_type;

	// number of bits is each chunk of output
	const size_t bitsPerOut = sizeof(out_t) * 8;

	// array of masks for fetching low number of bits
	static out_t maskLow[2 + bitsPerOut]; // index is number of bits set

	// initialise the masks
	static struct MaskInitialiser {
		MaskInitialiser() {
			maskLow[0] = 0b0;
			for (int idx = 0; idx <= bitsPerOut; ++idx) {
				maskLow[idx + 1]  = 1 + (maskLow[idx] << 1);
			}
		}
	} maskInit;


	// TODO: template on char_t of underlying stream
	struct oBitStream::Impl {

	public:
		// ctor
		Impl(std::ostream & os) : out(os) {}

		// write the least significant bits of value to the output buffer
		// return number of bits remaining in the current buffer entry
		size_t output(size_t bits, size_t value);

		// return the number of bits that can be accepted before buffer overflows
		size_t spaceBits() const;

		// flush as many complete entries as available, partially written entry will remain in buffer
		std::ostream&  flush();


	private:

		// underlying stream
		std::ostream& out;

		// buffer size
		static const size_t buflen = 16;

		// circular buffer
		out_t buffer[buflen]{};

		// index of out_t currently being written
		size_t writeIdx = 0;

		// number of bits remaining in current byte
		size_t writeBitsRemain = bitsPerOut;

		// index of next byte to read when flushing to the output stream
		// if (read == write) then need to wait for more bits before we can flush more to underlying stream
		size_t readIdx = 0;

		// output requested number of bits to current write entry in buffer
		// return number of bits written
		size_t outputBits(size_t bits, out_t mask, size_t value);

		// advance the write Idx, flush if appropriate
		// return number of write bits available in current write location
		size_t advanceWrite();
	};

	// dtor
	oBitStream::~oBitStream()
	{
		delete pImpl;
	}

	// ctor
	oBitStream::oBitStream(std::ostream & os)
		: pImpl( new Impl(os) )
	{
	}

	oBitStream& oBitStream::output(size_t bits, size_t value)
	{
		if (bits > 0) {
			pImpl->output(bits, value);
		}
		return *this;
	}

	std::ostream& oBitStream::flush()
	{
		return pImpl->flush();
	}

	size_t oBitStream::spaceBits() const
	{
		return pImpl->spaceBits();
	}


	size_t oBitStream::Impl::output(size_t bits, size_t value)
	{
		while (writeBitsRemain <= bits) {
			// need to write over multiple buffer entries
			// write remaining space in current write location
			out_t mask = maskLow[writeBitsRemain];
			const size_t bitsWritten = outputBits(writeBitsRemain, mask, value);
			bits -= bitsWritten;
			value >>= bitsWritten;
			writeBitsRemain -= bitsWritten;
			if (writeBitsRemain <= 0) {
				writeBitsRemain = advanceWrite();				
			}
		}
		if (bits > 0) {
			out_t mask = maskLow[bits];
			const size_t bitsWritten = outputBits(bits, mask, value);
			writeBitsRemain -= bitsWritten;
		}
		return writeBitsRemain;
	}


	size_t oBitStream::Impl::outputBits(size_t bits, out_t mask, size_t value)
	{
		const size_t shift = bitsPerOut - writeBitsRemain;
		out_t temp = buffer[writeIdx];
		temp &= ~(mask << shift); // clear relevant bits
		temp |= (value & mask) << shift; // set relevant bits from value

		buffer[writeIdx] = temp;

		return bits;

	}

	size_t oBitStream::Impl::spaceBits() const
	{
		size_t space = writeBitsRemain;
		if (readIdx < writeIdx) {
			space += bitsPerOut * (writeIdx - readIdx);
		}
		else {
			space += bitsPerOut * (readIdx + buflen - writeIdx - 1);
		}
		return space;
	}

	std::ostream& oBitStream::Impl::flush()
	{
		out_t val;
		while (readIdx != writeIdx) {
			// there is at least one entry ready to transfer to underlying stream
			if (readIdx < writeIdx) {
				// transfer one value to the underlying stream
				val = buffer[readIdx++];
				out.put(val);
			} else {
				// writeIdx has wrapped, so need to read to end of buffer
				if (readIdx < buflen) {
					// not reached end of buffer 
					// transfer one value to the underlying stream
					val = buffer[readIdx++];
					out.put(val);
				}
				else {
					// reached end of buffer, so wrap
					readIdx = 0;
				}
			}
		}
		// all complete entries transfered from buffer, so flush underlying stream


		return out.flush();
	}

	size_t oBitStream::Impl::advanceWrite()
	{
		if (writeIdx >= buflen - 1) {
			// we are about to wrap
			if (readIdx == 0) {
				// the buffer is now full
				flush();
			}
			writeIdx = 0;
		}
		else {
			if (writeIdx == readIdx - 1) {
				// the buffer is now full
				flush();
			}
			++writeIdx;
		}
		return bitsPerOut;
	}

}
