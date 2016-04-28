#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Clang01/Clang01.h"
#include "../Clang02/Clang02.h"
#include "../Clang03/Clang03.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestClang01
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Clang01)
		{
			int actual = 0;
			if (nClang01 > 0) {
				actual = fnClang01();
			}

			int expected = 42;

			Assert::AreEqual(expected, actual);

			CClang01 target(expected);
			actual = target.getVal();

			Assert::AreEqual(expected, actual);

		}

		TEST_METHOD(Clang02)
		{
			int actual = 0;
			if (nClang02 == 0) {
				actual = fnClang02();
			}

			int expected = 12;

			Assert::AreEqual(expected, actual);

			CClang02 target(expected);
			expected *= expected;

			actual = target.getVal();
			
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Clang03)
		{
			int actual = 0;
			if (nClang03 < 0) {
				actual = fnClang03();
			}

			int expected = 17;

			Assert::AreEqual(expected, actual);

			CClang03 target(expected);
			expected /= 2;

			actual = target.getVal();

			Assert::AreEqual(expected, actual);
		}
	};
}