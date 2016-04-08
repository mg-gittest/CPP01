#include "stdafx.h"
#include "CppUnitTest.h"

#include <memory>

#include "../Chapter16/chapter16array.h"
#include "../Chapter16/chapter16list.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mg_cpp14;

namespace TestChapter16
{
	using tgtPtr = Chapter16*;

	TEST_CLASS(UnitTest1)
	{
	private:
		const double tolerance = 1.0E-12;
		const double first = 1.23;
		const double second = 4.56;
		const double third = 7.89;
		const double fourth = 1.45;
		const double extra = 9.75;
		
		void checkIndex(Chapter16* target, const double expect, const size_t idx) {
			const double actual = target->get(idx);
			Assert::AreEqual(expect, actual, tolerance);
		}

		void checkIsNan(Chapter16* target, const size_t idx) {
			const double actual = target->get(idx);
			Assert::IsTrue(isnan(actual));
		}

		void loadFourList(Chapter16* target) {
			target->insertFirst(fourth);
			target->insertFirst(third);
			target->insertFirst(second);
			target->insertFirst(first);
		}

		void loadFourArray(Chapter16* target) {
			target->set(0, first);
			target->set(1, second);
			target->set(2, third);
			target->set(3, fourth);
		}

	public:

		TEST_METHOD(chapter16_list_default)
		{
			Chapter16* target = new Chapter16list();
			loadFourList(target);

			int expected = 2;
			Assert::AreEqual(expected, target->getBaseVal());
			checkIndex(target, first, 0);
			checkIndex(target, second, 1);
			checkIndex(target, third, 2);
			checkIndex(target, fourth, 3);
		}

		TEST_METHOD(chapter16_list_copy)
		{
			int inner = 11;
			Chapter16* target = nullptr;
			{
				Chapter16list one(inner);		
				loadFourList(&one);

				target = new Chapter16list(one);
			}

			Assert::AreEqual(inner, target->getBaseVal());
			checkIndex(target, first,  0);
			checkIndex(target, second, 1);
			checkIndex(target, third,  2);
			checkIndex(target, fourth, 3);
		}

		TEST_METHOD(chapter16_list_move)
		{
			int inner = 12;
			Chapter16* target = nullptr;
			{
				Chapter16list one(inner);
				loadFourList(&one);

				target = new Chapter16list(std::move(one));
			}

			Assert::AreEqual(inner, target->getBaseVal());
			checkIndex(target, first,  0);
			checkIndex(target, second, 1);
			checkIndex(target, third,  2);
			checkIndex(target, fourth, 3);
		}

		TEST_METHOD(chapter16_list_remove_second) {
			Chapter16* target = new Chapter16list();
			loadFourList(target);

			target->removeSecond();

			checkIndex(target, first, 0);
			checkIndex(target, third, 1);
			checkIndex(target, fourth, 2);
		}


		TEST_METHOD(chapter16_list_remove_third) {
			Chapter16* target = new Chapter16list();
			loadFourList(target);

			target->removeThird();

			checkIndex(target, first, 0);
			checkIndex(target, second, 1);
			checkIndex(target, fourth, 2);
		}

		TEST_METHOD(chapter16_list_insert_second)
		{
			Chapter16* target = new Chapter16list();
			loadFourList(target);

			target->insertSecond(extra);

			checkIndex(target, first, 0);
			checkIndex(target, extra, 1);
			checkIndex(target, second, 2);
			checkIndex(target, third, 3);
			checkIndex(target, fourth, 4);
		}

		TEST_METHOD(chapter16_array_default)
		{
			Chapter16* target = new Chapter16array();
			for (size_t idx = 0; idx < 10; ++idx) {
				checkIsNan(target, idx);
			}

			loadFourArray(target);

			checkIndex(target, first, 0);
			checkIndex(target, second, 1);
			checkIndex(target, third, 2);
			checkIndex(target, fourth, 3);

			const int expected = 1;
			Assert::AreEqual(expected, target->getBaseVal());
		}

		TEST_METHOD(chapter16_array_copy)
		{
			const int inner = 14;
			Chapter16* target = nullptr;
			{
				Chapter16array one(inner);
				loadFourArray(&one);

				target = new Chapter16array(one);
			}

			Assert::AreEqual(inner, target->getBaseVal());
			checkIndex(target, first, 0);
			checkIndex(target, second, 1);
			checkIndex(target, third, 2);
			checkIndex(target, fourth, 3);
		}

		TEST_METHOD(chapter16_array_move)
		{
			const int inner = 15;
			Chapter16* target = nullptr;
			{
				Chapter16array one(inner);
				loadFourArray(&one);

				target = new Chapter16array(std::move(one));
			}

			Assert::AreEqual(inner, target->getBaseVal());
			checkIndex(target, first, 0);
			checkIndex(target, second, 1);
			checkIndex(target, third, 2);
			checkIndex(target, fourth, 3);
		}

		TEST_METHOD(chapter16_array_remove_second) {
			Chapter16* target = new Chapter16array();
			loadFourArray(target);

			target->removeSecond();

			checkIndex(target, first, 0);
			checkIsNan(target, 1);
			checkIndex(target, third, 2);
			checkIndex(target, fourth, 3);
		}


		TEST_METHOD(chapter16_array_remove_third) {
			Chapter16* target = new Chapter16array();
			loadFourArray(target);

			target->removeThird();

			checkIndex(target, first, 0);
			checkIndex(target, second, 1);
			checkIsNan(target, 2);
			checkIndex(target, fourth, 3);
		}

		TEST_METHOD(chapter16_array_insert_second)
		{
			Chapter16* target = new Chapter16array();
			loadFourArray(target);

			target->insertSecond(extra);

			checkIndex(target, first, 0);
			checkIndex(target, extra, 1);
			checkIndex(target, third, 2);
			checkIndex(target, fourth, 3);
		}
	};
}