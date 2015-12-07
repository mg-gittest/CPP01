#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Chapter01/chapter01.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mg_cpp14;

namespace TestChapter01
{		
	TEST_CLASS(TChapter01)
	{
	private:
		
	public:
		
		TEST_METHOD(multiplyInt)
		{
			Chapter01 target;

			int a = 7;
			int b = 9;
			int expect = a * b;

			Assert::AreEqual(expect, target.multiply(a, b));
			Assert::AreEqual(expect, target.multiply(b, a));
		}

		TEST_METHOD(multiplyLong)
		{
			Chapter01 target;

			long a = 700L;
			long b = 900L;
			long expect = a * b;

			Assert::AreEqual(expect, target.multiply(a, b));
			Assert::AreEqual(expect, target.multiply(b, a));
		}

		TEST_METHOD(multiplyLongDouble)
		{
			Chapter01 target;

			double a = 700.14157;
			long   b = 985L;
			double expect = a * b;
			double tolerance = 0.000001;

			Assert::AreEqual(expect, target.multiply(a, b), tolerance);
			Assert::AreEqual(expect, target.multiply(b, a), tolerance);
		}

		TEST_METHOD(multiplyTrailDouble)
		{
			Chapter01 target;

			double a = 700.0;
			double b = 900.7;
			double expect = a * b;
			double tolerance = 0.0001;

			Assert::AreEqual(expect, target.multiplyTrail(a, b), tolerance);
			Assert::AreEqual(expect, target.multiplyTrail(b, a), tolerance);
		}

		TEST_METHOD(calcSum)
		{
			Chapter01 target;

			int expect = 0;
			for (int val = 1; val <= 5; ++val) {
				expect += val;
				Assert::AreEqual(expect, target.calcSum(val));
			}
		}

		TEST_METHOD(getThis)
		{
			Chapter01 target;

			Chapter01* expect = &target;
			Chapter01* actual = target.getThis();

			Assert::IsTrue(expect == actual);
		}

		TEST_METHOD(nextAfterUp)
		{
			float tolerance = 0.00000001f;

			float x = 0.699999988f;
			float expect = 0.700000048f;
			float y = 1.0f;

			float actual = nextafterf(x, y);

			Assert::AreEqual(expect, actual, tolerance);

		}

		TEST_METHOD(nextAfterDown)
		{
			float tolerance = 0.00000001f;

			float expect = 0.699999988f;
			float x = 0.700000048f;
			float y = 0.0f;

			float actual = nextafterf(x, y);

			Assert::AreEqual(expect, actual, tolerance);

		}
	};

}