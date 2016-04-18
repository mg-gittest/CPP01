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
				std::wstringstream msg;
				msg << std::dec << L"Index = " << index  << L", Bits = " << bits;
				msg << std::hex << L": "       << expect << L" != "      << actual;

				Assert::IsTrue(check);
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

	// masks for different nibbles in a byte
	static uint8_t maskN[5]
	{     0b00001111
		, 0b00011110
		, 0b00111100
		, 0b01111000
		, 0b11110000 
	};

	// masks for different pairs in a byte
	static uint8_t maskP[7]
	{     0b00000011
		, 0b00000110
		, 0b00001100
		, 0b00011000
		, 0b00110000
		, 0b01100000
		, 0b11000000
	};

	TEST_CLASS(UnitTest4)
	{

	private:
		union TargetNibbles {
			uint8_t byte;
			BitField<0, 4> nibble0;
			BitField<1, 4> nibble1;
			BitField<2, 4> nibble2;
			BitField<3, 4> nibble3;
			BitField<4, 4> nibble4;
		};

		union TargetPairs {
			uint8_t byte;
			BitField<0, 2> pair0;
			BitField<1, 2> pair1;
			BitField<2, 2> pair2;
			BitField<3, 2> pair3;
			BitField<4, 2> pair4;
			BitField<5, 2> pair5;
			BitField<6, 2> pair6;
		};


		// test reading of a single nibble bitfield from the target
		// as the code is identical for each nibble, apart from offsetting index it is templated on index
		template<size_t idx>
		void testReadNibble(const TargetNibbles& target, const BitField<idx, 4>& field) {

			uint8_t mask = maskN[idx];
			uint8_t expected = target.byte & mask;
			expected >>= idx;

			Assert::AreEqual(expected, uint8_t(field));
		}

		// test reading of each nibble bitfield from the target
		void testReadNibbles(const TargetNibbles& target) {
			testReadNibble(target, target.nibble0);
			testReadNibble(target, target.nibble1);
			testReadNibble(target, target.nibble2);
			testReadNibble(target, target.nibble3);
			testReadNibble(target, target.nibble4);
		}


		// test reading of a single pair bitfield from the target
		// as the code is identical for each pair, apart from offsetting index it is templated on index
		template<size_t idx>
		void testReadPair(const TargetPairs& target, const BitField<idx, 2>& field) {

			uint8_t mask = maskP[idx];
			uint8_t expected = target.byte & mask;
			expected >>= idx;

			Assert::AreEqual(expected, uint8_t(field));
		}

		// test reading of each possible pair
		void testReadPairs(const TargetPairs& target) {
			testReadPair(target, target.pair0);
			testReadPair(target, target.pair1);
			testReadPair(target, target.pair2);
			testReadPair(target, target.pair3);
			testReadPair(target, target.pair4);
			testReadPair(target, target.pair5);
			testReadPair(target, target.pair6);
		}

		// write a single pair, and confirm that no other bits are changed
		// as the code is identical for each pair, apart from offsetting index it is templated on index
		template<size_t idx>
		void testWritePair(TargetPairs& target, BitField<idx, 2>& field, const uint8_t val) {

			uint8_t mask = maskP[idx];
			uint8_t start = target.byte;

			field = val;

			uint8_t result = target.byte;
			uint8_t actual(field);

			Assert::AreEqual(val, actual);

			uint8_t changedBits = start ^ result;
			changedBits &= ~mask; // clear any changed in the field, we require others to be unchanged

			Assert::AreEqual(uint8_t(0), changedBits);

			// return to starting condition
			target.byte = start;
		}

		// test writing of each pair with all four possible values
		void testWritePairs(TargetPairs& target) {
			for (uint8_t val = 0; val < 4; val += 2) {
				testWritePair(target, target.pair0, val);
				testWritePair(target, target.pair1, val);
				testWritePair(target, target.pair2, val);
				testWritePair(target, target.pair3, val);
				testWritePair(target, target.pair4, val);
				testWritePair(target, target.pair5, val);
				testWritePair(target, target.pair6, val);
			}
		}


		// write a single nibble, and confirm that no other bits are changed
		// as the code is identical for each nibble, apart from offsetting index, so method is templated on index
		template<size_t idx>
		void testWriteNibble(TargetNibbles& target, BitField<idx, 4>& field, const uint8_t val) {

			const uint8_t mask = maskN[idx];
			const uint8_t start = target.byte;

			field = val;

			const uint8_t result = target.byte;
			const uint8_t actual(field);
			
			Assert::AreEqual(val, actual);
			
			uint8_t changedBits = start ^ result;
			changedBits &= ~mask; // clear any changed in the field, we require others to be unchanged

			Assert::AreEqual(uint8_t(0), changedBits);

			// return to starting condition
			target.byte = start;
		}

		// test writing of each nibble with all 16 possible values
		void testWriteNibbles(TargetNibbles& target) {
			for (uint8_t val = 0; val < 16; val += 5) {
				testWriteNibble(target, target.nibble0, val);
				testWriteNibble(target, target.nibble1, val);
				testWriteNibble(target, target.nibble2, val);
				testWriteNibble(target, target.nibble3, val);
				testWriteNibble(target, target.nibble4, val);
			}
		}

	public:
		TEST_METHOD(chapter17_bitfield_union_01) {
			// test read/write of nibbles
			TargetNibbles target{};

			uint8_t expected = 0;
			Assert::AreEqual(expected, target.byte);
			testReadNibbles(target);
			
			// now test some non-zero values
			for (uint8_t val = 0xbf; val > 0; val >>= 1) {
				target.byte = val;
				testReadNibbles(target);
				testWriteNibbles(target);
			}

		}

		TEST_METHOD(chapter17_bitfield_union_02) {
			// test read/write of pairs
			TargetPairs target {};

			uint8_t expected = 0;
			Assert::AreEqual(expected, target.byte);
			testReadPairs(target);
			testWritePairs(target);

			// now test some non-zero values
			for (uint8_t val = 0xbf; val > 0; val >>= 1) {
				target.byte = val;
				testReadPairs(target);
				testWritePairs(target);
			}
		}

	};
}