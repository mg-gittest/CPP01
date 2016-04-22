#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Chapter17/chapter17bitstream.h"

#include <sstream>
#include <cstdlib>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mg_cpp14;

namespace TestChapter17
{
	TEST_CLASS(BasicBitstream)
	{
	private:
		using char_t = std::ostream::char_type;

		// build a 64 bit random(ish) number
		size_t randVal() {
			size_t val = rand();
			val <<= 15;
			val += rand();
			val <<= 15;
			val += rand();
			val <<= 15;
			val += rand();
			val <<= 15;
			val += rand();
			return val;
		}
		
		void validateStreamString(std::ostringstream& outStream, const std::string& expect) {
			Assert::IsTrue(outStream.good());
			std::string actual = outStream.str();
			Assert::AreEqual(expect, actual);
		}

		void validateStreamBytes(const std::ostringstream& outStream, const char* const expected, const size_t count) {
			// extract the input, then examine each entry
			std::istringstream result(outStream.str());

			char actual, expect;
			for (size_t idx = 0; idx < count; ++idx) {
				expect = expected[idx];
				result >> actual;
				Assert::AreEqual(expect, actual);
			}
		}

		void validateStreamBytes(const std::ostringstream& outStream, const size_t expected, std::wostringstream& msg) {
			// extract the input, then examine each entry
			std::istringstream result(outStream.str());

			uint8_t actual, expect;
			for (size_t idx = 0; idx < 8; idx += 8) {
				expect = (expected >> idx) & 0xFF;
				result >> actual;
				if (expect != actual) {					
					msg << L"\n expected: " << std::hex << expected;
					msg << L"\n idx: "     << std::hex << idx;
					msg << L"\n expect: "  << std::hex << expect;
					msg << L"\n actual: "  << std::hex << actual;
					Assert::AreEqual(expect, actual, msg.str().c_str());
				}
			}
		}

		// output chosen number of bits, limited by remaining
		// return new remainder after bits have been output
		size_t outputBits(oBitStream& target, const size_t remaining, size_t bits, size_t& value) {
			if (bits > remaining) {
				bits = remaining;
			}
			target.output(bits, value);
			value >>= bits;			
			return remaining - bits;
		}

	public:

		TEST_METHOD(chapter17_bitstream_output_03) {
			
			srand(15); // make test repeatable
			for (int loop = 0; loop < 1024; ++loop) {
				std::ostringstream outStream;
				oBitStream target(outStream);
				
				const size_t expected = randVal();
				size_t value = expected;
				//size_t remaining = 8 * sizeof(value);
				size_t remaining = 8;

				std::wostringstream msg;
				msg << L"\n loop: " << loop << L"\n bits: ";
				while (remaining > 0) {
					size_t bits = 1 + (rand() % 8);
					msg << bits << L", ";
					remaining = outputBits(target, remaining, bits, value);
				}

				target.flush();
				validateStreamBytes(outStream, expected, msg);
			}

		}

		TEST_METHOD(chapter17_bitstream_output_00) {
			std::ostringstream outStream;


			char val[]{ 0x10, 0x32, 0x54, 0x76, 0x00 };
			size_t idx = 0;
			outStream.put(val[idx++]);
			outStream.put(val[idx++]);
			outStream.put(val[idx++]);
			outStream.put(val[idx++]);

			std::string exp(val);
			std::string actual = outStream.str();

			Assert::AreEqual(exp, actual);
		}		
		
		TEST_METHOD(chapter17_bitstream_output_01) {
			std::ostringstream outStream;
			oBitStream target(outStream);

			size_t value = 0xFEDCBA76543210;
			target.output(32, value);
			target.output(32, value);
			target.output(1, value);
			while (value > 0) {
				value >>= 1;
				target.output(1, value);
			}
			target.output(1, 0xFF);
			target.flush();

			std::istringstream result(outStream.str());

			char expect[]{ 0x10, 0x32, 0x54, 0x76, 0x10, 0x32, 0x54, 0x76, 0x10, 0x32, 0x54 };

			validateStreamBytes(outStream, expect, sizeof(expect));

		}	
		
		TEST_METHOD(chapter17_bitstream_output_02) {

			std::ostringstream outStream;
			oBitStream target(outStream);

			size_t idx = 0;
			size_t bits[]{ 1,2,3,4,5,6,7,8,9,10,11 };
			
			const size_t expected = 0xFEDCBA9876543210;
			size_t value = expected;
			size_t remaining = 8 * sizeof(value);

			while (remaining > 0) {
				remaining = outputBits(target, remaining, bits[idx++], value);
			}

			target.flush();
			std::wostringstream msg;
			validateStreamBytes(outStream, expected, msg);

		}


		TEST_METHOD(chapter17_bitstream_ctor) {
			std::ostringstream outStream;
			oBitStream target(outStream);

			std::string expect;
			validateStreamString(outStream, expect);

			Assert::AreEqual(size_t(128), target.spaceBits());
		}
	};
}