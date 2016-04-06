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
		const double tolerance = 1.0E-12;
		const double first  = 1.23;
		const double second = 4.56;

		void insertFirst(Chapter16* target) {
			target->insertFirst(first);
		}

		void insertSecond(Chapter16* target) {
			target->insertSecond(second);
		}

		void checkIndex(Chapter16* target, const double expect, const size_t idx) {
			const double actual = target->get(idx);
			Assert::AreEqual(expect, actual, tolerance);
		}

	public:
		TEST_METHOD(chapter16_list_default)
		{
			Chapter16* target = new Chapter16list();
			insertFirst(target);
			checkIndex(target, first, 0);
			insertSecond(target);
			checkIndex(target, second, 1);
			int expected = 2;
			Assert::AreEqual(expected, target->getBaseVal());
		}

		TEST_METHOD(chapter16_list_copy)
		{
			int inner = 11;
			Chapter16* target = nullptr;
			{
				Chapter16list one(inner);
				target = new Chapter16list(one);
			}
			Assert::AreEqual(inner, target->getBaseVal());
		}

		TEST_METHOD(chapter16_list_move)
		{
			int inner = 12;
			Chapter16* target = nullptr;
			{
				Chapter16list one(inner);
				target = new Chapter16list(std::move(one));
			}
			Assert::AreEqual(inner, target->getBaseVal());
		}

		TEST_METHOD(chapter16_array_default)
		{
			Chapter16* target = new Chapter16array();
			insertFirst(target);
			checkIndex(target, first, 0);
			insertSecond(target);
			checkIndex(target, second, 1);
			int expected = 1;
			Assert::AreEqual(expected, target->getBaseVal());
		}

		TEST_METHOD(chapter16_array_copy)
		{
			int inner = 14;
			Chapter16* target = nullptr;
			{
				Chapter16array one(inner);
				target = new Chapter16array(one);
			}
			Assert::AreEqual(inner, target->getBaseVal());
		}

		TEST_METHOD(chapter16_array_move)
		{
			int inner = 15;
			Chapter16* target = nullptr;
			{
				Chapter16array one(inner);
				target = new Chapter16array(std::move(one));
			}
			Assert::AreEqual(inner, target->getBaseVal());
		}


	};
}