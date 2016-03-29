#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>

#include "../Chapter04/chapter04add.h"
#include "../Chapter04/chapter04mult.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mg_cpp14;

namespace TestChapter04
{
	TEST_CLASS(UnitTest1)
	{
	private:
		const double tolerance = 1.0E-12;

	public:

		TEST_METHOD(chapter04AddOne)
		{
			const double fixed = 1.3;
			std::unique_ptr<Chapter04> target = std::make_unique<Chapter04Add>(fixed);

			double input = 3.2;
			double expected = input + fixed;

			double actual = target->doStuff(input);

			Assert::AreEqual(expected, actual, tolerance);

		}

		TEST_METHOD(chapter04AddTwo)
		{
			const double fixed = -1.3;
			std::unique_ptr<Chapter04> target = std::make_unique<Chapter04Add>(fixed);

			double input = -3.2;
			double expected = input + fixed;

			double actual = target->doStuff(input);

			Assert::AreEqual(expected, actual, tolerance);

		}

		TEST_METHOD(chapter04MultOne)
		{
			const double fixed = 1.3;
			std::unique_ptr<Chapter04> target = std::make_unique<Chapter04Mult>(fixed);

			double input = 3.2;
			double expected = input * fixed;

			double actual = target->doStuff(input);

			Assert::AreEqual(expected, actual, tolerance);

		}

		TEST_METHOD(chapter04MultTwo)
		{
			const double fixed = -1.3;
			std::unique_ptr<Chapter04> target = std::make_unique<Chapter04Mult>(fixed);

			double input = -3.2;
			double expected = input * fixed;

			double actual = target->doStuff(input);

			Assert::AreEqual(expected, actual, tolerance);

		}


	};
}