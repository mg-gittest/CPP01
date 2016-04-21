#pragma once

#include "decl_chapter17.h"
#include "chapter17bitfield.h"

#include <iosfwd>

namespace mg_cpp14 {

	class CHAPTER17_DLL oBitStream {
	public:
		// dtor
		virtual ~oBitStream();

		// ctor needing underlying ostream to write to
		oBitStream(std::ostream& os);

		// delete copy ctor
		oBitStream(const oBitStream& that) = delete;

		// delete move ctor
		oBitStream(oBitStream&& that) = delete;

		// flush as many complete bytes as available, partially written byte will remain in buffer
		std::ostream& flush();

		// return the number of bits that can be accepted before buffer overflows
		size_t spaceBits() const;

		// extract a given number of least significant bits from a value
		// adding to current buffer write position
		oBitStream& output(size_t bits, size_t value);

		// inserter for any BitField
		template <size_t Index, size_t Bits>
		oBitStream& operator<< (const BitField<Index, Bits>& bitfield) {
			size_t value(BitField<Index, Bits>::type(bitfield));
			return output(Bits, value);
		}

	private:
		// private implementaton  structure
		struct Impl;
		// pointer to on heap implementation object
		Impl* pImpl;
	};

	}
