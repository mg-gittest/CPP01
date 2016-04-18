#include "stdafx.h"
#include "CppUnitTest.h"

#include <memory>

#include "../Chapter17/chapter17bitfield.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mg_cpp14;

namespace TestChapter17
{
	TEST_CLASS(UnitTest3)
	{
	private:
		//template<size_t num>
		//const void checkSize(const size_t expected) {
		//	Assert::AreEqual(expected, sizeof(MinimumTypeHelper<num>::type));
		//}

		// calculate largest unsigned for a given size of bits
		const size_t calcLimit(const size_t bits) {
			if (bits >= 64) {
				return 0xFFFFFFFFFFFFFFFF;
			}
			size_t limit = 1u;
			limit <<= bits;
			--limit;
			return limit;
		}

		// test for expect == actual, build context message from index and bits if fail
		void doCheck(size_t index, size_t bits, size_t expect, size_t actual) {
			bool check = expect == actual;
			if (!check) {
				std::wstring msg;
				msg += L"Index = " + std::to_wstring(index);
				msg += L", Bits = " + std::to_wstring(bits);
				msg += L": " + std::to_wstring(expect);
				msg += L" != " + std::to_wstring(actual);

				Assert::IsTrue(check, msg.c_str());
			}
		}

		template <size_t Index, size_t Bits>
		void testBitFieldOne() {

			BitField<Index, Bits> target;
			using TT = decltype(target)::type;

			const size_t limit = calcLimit(Bits);
			const size_t mask = limit;
			TT expect = 0;
			do {
				// set next bit up
				expect <<= 1;
				++expect;
				target = expect;   // assignement operator
				TT actual(target); // type conversion

				doCheck(Bits, Index, expect, actual);

			} while (expect < limit);

			// clear bottom bit
			expect = limit & ~(0x01);
			while (expect > 0) {
				target = expect;   // assignement operator
				TT actual(target); // type conversion

				doCheck(Bits, Index, expect, actual);
				
				expect <<= 1; // clear bottom set bit
				expect &= limit; // mask to limit
			}

			int8_t val = -1L;
			target = val;
			TT actual(target); // type conversion

			expect = TT(val) & mask;

			doCheck(Bits, Index, expect, actual);

		}

	public:

		TEST_METHOD(chapter17_bitfield_3_1) {
			const size_t Index = 3;
			const size_t Bits = 1;

			BitField<Index, Bits> target;
			target = true;
			Assert::IsTrue(bool(target));
			target = false;
			Assert::IsFalse(bool(target));
		}

		TEST_METHOD(chapter17_bitfield_3_2) {
			const size_t index = 3;
			const size_t bits = 2;
			testBitFieldOne<index, bits>();
		}

		TEST_METHOD(chapter17_bitfield_5_4) {
			const size_t index = 5;
			const size_t bits = 4;
			testBitFieldOne<index, bits>();
		}

		TEST_METHOD(chapter17_bitfield_26_9) {
			const size_t index = 26;
			const size_t bits = 9;
			testBitFieldOne<index, bits>();
		}

		TEST_METHOD(chapter17_bitfield_49_15) {
			const size_t index = 49;
			const size_t bits = 15;
			testBitFieldOne<index, bits>();
		}

		TEST_METHOD(chapter17_bitfield_50_13) {
			const size_t index = 50;
			const size_t bits = 13;
			testBitFieldOne<index, bits>();
		}

		TEST_METHOD(chapter17_bitfield_50_14) {
			const size_t index = 50;
			const size_t bits = 14;
			testBitFieldOne<index, bits>();
		}

		TEST_METHOD(chapter17_bitfield_0_64) {
			const size_t index = 0;
			const size_t bits = 64;
			testBitFieldOne<index, bits>();
		}

		TEST_METHOD(chapter17_bitfield_0_63) {
			const size_t index = 0;
			const size_t bits = 63;
			testBitFieldOne<index, bits>();
		}

		TEST_METHOD(chapter17_bitfield_1_63) {
			const size_t index = 1;
			const size_t bits = 63;
			testBitFieldOne<index, bits>();
		}

		//TEST_METHOD(chapter17_bitfield_50_15) {
		// correctly fails to compile as 65 bits needed
		//	testBitFieldOne<50, 15>();
		//}

	};
}