#include "stdafx.h"
#include "CppUnitTest.h"

#include <memory>

#include "../Chapter17/chapter17bitfield.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mg_cpp14;

namespace TestChapter17
{
	TEST_CLASS(BasicBitfield)
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
		void testBitFieldBasic() {

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

		template <size_t idx>
		void testBitFieldBool() {
			BitField<idx, 1> target;
			target = true;
			Assert::IsTrue(bool(target));
			target = false;
			Assert::IsFalse(bool(target));
		}

	public:

		TEST_METHOD(chapter17_bitfield_basic) {
			testBitFieldBool< 1>();
			testBitFieldBool< 3>();
			testBitFieldBool< 7>();
			testBitFieldBool< 8>();
			testBitFieldBool< 9>();
			testBitFieldBool<15>();
			testBitFieldBool<16>();
			testBitFieldBool<31>();
			testBitFieldBool<32>();
			testBitFieldBool<63>();

			testBitFieldBasic< 0, 64 >();
			testBitFieldBasic< 3,  2>();
			testBitFieldBasic< 5,  4>();
			testBitFieldBasic< 26, 9>();
			testBitFieldBasic< 49, 15>();
			testBitFieldBasic< 50, 13>();
			testBitFieldBasic< 50, 14 >();
			testBitFieldBasic< 0, 63 >();
			testBitFieldBasic< 1, 63>();
		}
	};

	// masks for different nibbles in a byte
	static uint8_t maskN8[8]{};

	// masks for different pairs in a byte
	static uint8_t maskP8[8]{};

	// masks for different nibbles in a 64bit field
	static uint64_t maskN64[64] { };

	// masks for different pairs in a byte
	static uint64_t maskP64[64] { };

	// initialise the masks
	struct MaskInitialiser {
		MaskInitialiser() {
			for (int idx = 0; idx < 8; ++idx) {
				maskN8[idx] = uint8_t(0b1111) << idx;
				maskP8[idx] = uint8_t(0b0011) << idx;
			}
			for (int idx = 0; idx < 64; ++idx) {
				maskN64[idx] = uint64_t(0b1111) << idx;
				maskP64[idx] = uint64_t(0b0011) << idx;
			}
		}
	} maskInit;

	TEST_CLASS(UnitTest4)
	{

	private:
		using base_t = uint8_t;
		union TargetNibbles {
			base_t all_bits;
			BitField<0, 4> nibble0;
			BitField<1, 4> nibble1;
			BitField<2, 4> nibble2;
			BitField<3, 4> nibble3;
			BitField<4, 4> nibble4;
		};

		union TargetPairs {
			base_t all_bits;
			BitField<0, 2> pair0;
			BitField<1, 2> pair1;
			BitField<2, 2> pair2;
			BitField<3, 2> pair3;
			BitField<4, 2> pair4;
			BitField<5, 2> pair5;
			BitField<6, 2> pair6;
		};


		// cxheck reading of individual fields compared to all_bits
		template<size_t idx, size_t bits, typename Target, typename Base_t>
		void testRead(const Target& target, const BitField<idx, bits>& field, Base_t Mask[]) {

			Base_t mask = Mask[idx];
			Base_t expected = target.all_bits & mask;
			expected >>= idx;

			Assert::AreEqual(expected, Base_t(field));
		}


		// test reading of each nibble bitfield from the target
		void testReadNibbles(const TargetNibbles& target) {
			testRead(target, target.nibble0, maskN8);
			testRead(target, target.nibble1, maskN8);
			testRead(target, target.nibble2, maskN8);
			testRead(target, target.nibble3, maskN8);
			testRead(target, target.nibble4, maskN8);
		}

		// test reading of each possible pair
		void testReadPairs(const TargetPairs& target) {
			testRead(target, target.pair0, maskP8);
			testRead(target, target.pair1, maskP8);
			testRead(target, target.pair2, maskP8);
			testRead(target, target.pair3, maskP8);
			testRead(target, target.pair4, maskP8);
			testRead(target, target.pair5, maskP8);
			testRead(target, target.pair6, maskP8);
		}

		// write a single pair, and confirm that no other bits are changed
		// as the code is identical for each pair, apart from offsetting index it is templated on index
		template<size_t idx>
		void testWritePair(TargetPairs& target, BitField<idx, 2>& field, const base_t val) {

			base_t mask = maskP8[idx];
			base_t start = target.all_bits;

			field = val;

			base_t result = target.all_bits;
			base_t actual(field);

			Assert::AreEqual(val, actual);

			base_t changedBits = start ^ result;
			changedBits &= ~mask; // clear any changed in the field, we require others to be unchanged

			Assert::AreEqual(base_t(0), changedBits);

			// return to starting condition
			target.all_bits = start;
		}

		// test writing of each pair with all four possible values
		void testWritePairs(TargetPairs& target) {
			for (base_t val = 0; val < 4; val += 2) {
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
		void testWriteNibble(TargetNibbles& target, BitField<idx, 4>& field, const base_t val) {

			const base_t mask = maskN8[idx];
			const base_t start = target.all_bits;

			field = val;

			const base_t result = target.all_bits;
			const base_t actual(field);
			
			Assert::AreEqual(val, actual);
			
			base_t changedBits = start ^ result;
			changedBits &= ~mask; // clear any changed in the field, we require others to be unchanged

			Assert::AreEqual(base_t(0), changedBits);

			// return to starting condition
			target.all_bits = start;
		}

		// test writing of each nibble with all 16 possible values
		void testWriteNibbles(TargetNibbles& target) {
			for (base_t val = 0; val < 16; val += 5) {
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

			base_t expected = 0;
			Assert::AreEqual(expected, target.all_bits);
			testReadNibbles(target);
			
			// now test some non-zero values
			for (base_t val = 0xbf; val > 0; val >>= 1) {
				target.all_bits = val;
				testReadNibbles(target);
				testWriteNibbles(target);
			}

		}

		TEST_METHOD(chapter17_bitfield_union_02) {
			// test read/write of pairs
			TargetPairs target {};

			base_t expected = 0;
			Assert::AreEqual(expected, target.all_bits);
			testReadPairs(target);
			testWritePairs(target);

			// now test some non-zero values
			for (base_t val = 0xbf; val > 0; val >>= 1) {
				target.all_bits = val;
				testReadPairs(target);
				testWritePairs(target);
			}
		}

	};

	TEST_CLASS(UnitTest5)
	{

	private:
		using base_t = uint64_t;
		union TargetNibbles {
			base_t all_bits;
			BitField<50, 4> nibble0;
			BitField<51, 4> nibble1;
			BitField<52, 4> nibble2;
			BitField<53, 4> nibble3;
			BitField<54, 4> nibble4;
		};

		union TargetPairs {
			base_t all_bits;
			BitField<50, 2> pair0;
			BitField<51, 2> pair1;
			BitField<52, 2> pair2;
			BitField<53, 2> pair3;
			BitField<54, 2> pair4;
			BitField<55, 2> pair5;
			BitField<56, 2> pair6;
		};


		// test reading of a single nibble bitfield from the target
		// as the code is identical for each nibble, apart from offsetting index it is templated on index
		template<size_t idx>
		void testReadNibble(const TargetNibbles& target, const BitField<idx, 4>& field) {

			base_t mask = maskN64[idx];
			base_t expected = target.all_bits & mask;
			expected >>= idx;

			Assert::AreEqual(expected, base_t(field));
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

			base_t mask = maskP64[idx];
			base_t expected = target.all_bits & mask;
			expected >>= idx;

			Assert::AreEqual(expected, base_t(field));
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
		void testWritePair(TargetPairs& target, BitField<idx, 2>& field, const base_t val) {

			base_t mask = maskP64[idx];
			base_t start = target.all_bits;

			field = val;

			base_t result = target.all_bits;
			base_t actual(field);

			Assert::AreEqual(val, actual);

			base_t changedBits = start ^ result;
			changedBits &= ~mask; // clear any changed in the field, we require others to be unchanged

			Assert::AreEqual(base_t(0), changedBits);

			// return to starting condition
			target.all_bits = start;
		}

		// test writing of each pair with all four possible values
		void testWritePairs(TargetPairs& target) {
			for (base_t val = 0; val < 4; val += 2) {
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
		void testWriteNibble(TargetNibbles& target, BitField<idx, 4>& field, const base_t val) {

			const base_t mask = maskN64[idx];
			const base_t start = target.all_bits;

			field = val;

			const base_t result = target.all_bits;
			const base_t actual(field);

			Assert::AreEqual(val, actual);

			base_t changedBits = start ^ result;
			changedBits &= ~mask; // clear any changed in the field, we require others to be unchanged

			Assert::AreEqual(base_t(0), changedBits);

			// return to starting condition
			target.all_bits = start;
		}

		// test writing of each nibble with all 16 possible values
		void testWriteNibbles(TargetNibbles& target) {
			for (base_t val = 0; val < 16; val += 5) {
				testWriteNibble(target, target.nibble0, val);
				testWriteNibble(target, target.nibble1, val);
				testWriteNibble(target, target.nibble2, val);
				testWriteNibble(target, target.nibble3, val);
				testWriteNibble(target, target.nibble4, val);
			}
		}

	public:
		TEST_METHOD(chapter17_bitfield_union_03) {
			// test read/write of nibbles
			TargetNibbles target{};

			base_t expected = 0;
			Assert::AreEqual(expected, target.all_bits);
			testReadNibbles(target);

			// now test some non-zero values
			for (base_t val = 0xbf; val > 0; val >>= 1) {
				target.all_bits = val;
				testReadNibbles(target);
				testWriteNibbles(target);
			}

		}

		TEST_METHOD(chapter17_bitfield_union_04) {
			// test read/write of pairs
			TargetPairs target{};

			base_t expected = 0;
			Assert::AreEqual(expected, target.all_bits);
			testReadPairs(target);
			testWritePairs(target);

			// now test some non-zero values
			for (base_t val = 0xbf; val > 0; val >>= 1) {
				target.all_bits = val;
				testReadPairs(target);
				testWritePairs(target);
			}
		}

	};
}