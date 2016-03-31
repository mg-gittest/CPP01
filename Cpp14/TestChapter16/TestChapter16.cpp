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
		}

		TEST_METHOD(chapter16_array_default)
		{
			Chapter16* target = new Chapter16array();
			insertFirst(target);
			checkIndex(target, first, 0);
			insertSecond(target);
			checkIndex(target, second, 1);
		}

	};
}