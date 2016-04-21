#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Chapter17/chapter17bitstream.h"

#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mg_cpp14;

namespace TestChapter17
{
	TEST_CLASS(BasicBitstream)
	{
	private:
		using char_t = std::ostream::char_type;

		void validateOutStream(std::ostringstream& outStream, const char_t* pExpect) {
			Assert::IsTrue(outStream.good());
			const char_t* pData = outStream.str().data();
			
			Assert::AreEqual(*pExpect, *pData);
		}
		
		void validateOutStream(std::ostringstream& outStream, const std::string& expect) {
			Assert::IsTrue(outStream.good());
			std::string actual = outStream.str();
			Assert::AreEqual(expect, actual);
		}

	public:

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

			char val[]{ 0x10, 0x32, 0x54, 0x76, 0x10, 0x32, 0x54, 0x76, 0x10, 0x32, 0x54 };

			char tmp;
			size_t idx = 0;
			while (idx < sizeof(val)) {
				char exp = val[idx++];
				result >> tmp;
				Assert::AreEqual(exp, tmp);
			}
		
		}

		TEST_METHOD(chapter17_bitstream_ctor) {
			std::ostringstream outStream;
			oBitStream target(outStream);

			std::string expect;
			validateOutStream(outStream, expect);

			Assert::AreEqual(size_t(128), target.spaceBits());
		}
	};
}