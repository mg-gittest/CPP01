#include "stdafx.h"
#include "CppUnitTest.h"

#include <memory>

#include "../Chapter17/chapter17bitfield.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mg_cpp14;

#include <type_traits>
#include <string>
#include <cmath>

namespace TestChapter17
{
	TEST_CLASS(UnitTest1)
	{
	private:
		template<size_t num>
		const void checkSize(const size_t expected) {
			Assert::AreEqual(expected, sizeof(MinimumTypeHelper<num>::type));
		}

		const size_t calcLimit(const size_t bits) {
			#pragma warning(push)
			#pragma warning(disable : 4244)
			return size_t(std::floor(std::pow(2.0, bits)));
			#pragma warning(pop)
		}

		template <size_t Index, size_t Bits>
		void testBitFieldOne(std::wstring msg) {
			BitField<Index, Bits> target;
			using TT = decltype(target)::type;

			TT expect = 0;
			
			const size_t Limit = calcLimit(Bits);
			while (expect < Limit) {
				target = expect;
				TT actual(target);

				bool check = expect == actual;
				if (!check) {
					msg += std::to_wstring(expect) + L" != " + std::to_wstring(actual);
				}
				Assert::IsTrue(check, msg.c_str());
				++expect;
			}
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
			testBitFieldOne<3, 2>(L"Index = 3, Bits = 2: ");
		}

		TEST_METHOD(chapter17_bitfield_5_4) {
			testBitFieldOne<5, 4>(L"Index = 5, Bits = 4: ");
		}

		TEST_METHOD(chapter17_bitfield_26_9) {
			testBitFieldOne<26, 6>(L"Index = 26, Bits = 9: ");
		}
		//	const size_t Index = 26;
		//	const size_t Bits = 9;
		//	const size_t Limit = calcLimit(Bits);

		//	BitField<Index, Bits> target;
		//	using T = decltype(target)::type;

		//	T expect = 0;
		//	std::wstring msg;
		//	while (expect < Limit) {
		//		target = expect;
		//		T actual(target);

		//		bool check = expect == actual;
		//		if (!check) {
		//			msg = std::to_wstring(expect) + L" != " + std::to_wstring(actual);
		//		}
		//		Assert::IsTrue(check, msg.c_str());
		//		++expect;
		//	}
		//}

		TEST_METHOD(chapter17_sizeof_mintype0)
		{
			bool isVoid = std::is_void< MinimumTypeHelper<0>::type >::value;
			Assert::IsTrue(isVoid);
		}

		TEST_METHOD(chapter17_sizeof_mintype_1_8)
		{
			size_t expected(1);
			checkSize<1>(expected);
			checkSize<2>(expected);
			checkSize<3>(expected);
			checkSize<4>(expected);
			checkSize<5>(expected);
			checkSize<6>(expected);
			checkSize<7>(expected);
			checkSize<8>(expected);
		}

		TEST_METHOD(chapter17_sizeof_mintype_9_16)
		{
			size_t expected(2);
			checkSize< 9>(expected);
			checkSize<10>(expected);
			checkSize<11>(expected);
			checkSize<12>(expected);
			checkSize<13>(expected);
			checkSize<14>(expected);
			checkSize<15>(expected);
			checkSize<16>(expected);
		}

		TEST_METHOD(chapter17_sizeof_mintype_17_32)
		{
			size_t expected(4);
			checkSize<17>(expected);
			checkSize<18>(expected);
			checkSize<19>(expected);
			checkSize<20>(expected);
			checkSize<21>(expected);
			checkSize<22>(expected);
			checkSize<23>(expected);
			checkSize<24>(expected);
			checkSize<25>(expected);
			checkSize<26>(expected);
			checkSize<27>(expected);
			checkSize<28>(expected);
			checkSize<29>(expected);
			checkSize<30>(expected);
			checkSize<31>(expected);
			checkSize<32>(expected);
		}

		TEST_METHOD(chapter17_sizeof_mintype_33_64)
		{
			size_t expected(8);
			checkSize<33>(expected);
			checkSize<34>(expected);
			checkSize<35>(expected);
			checkSize<36>(expected);
			checkSize<37>(expected);
			checkSize<38>(expected);
			checkSize<39>(expected);
			checkSize<40>(expected);
			checkSize<41>(expected);
			checkSize<42>(expected);
			checkSize<43>(expected);
			checkSize<44>(expected);
			checkSize<45>(expected);
			checkSize<46>(expected);
			checkSize<47>(expected);
			checkSize<48>(expected);
			checkSize<49>(expected);
			checkSize<50>(expected);
			checkSize<51>(expected);
			checkSize<52>(expected);
			checkSize<53>(expected);
			checkSize<54>(expected);
			checkSize<55>(expected);
			checkSize<56>(expected);
			checkSize<57>(expected);
			checkSize<58>(expected);
			checkSize<59>(expected);
			checkSize<60>(expected);
			checkSize<61>(expected);
			checkSize<62>(expected);
			checkSize<63>(expected);
			checkSize<64>(expected);
		}

	};
}