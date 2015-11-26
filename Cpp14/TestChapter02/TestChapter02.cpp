#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Chapter02/chapter02.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mg_cpp14;

namespace TestChapter02
{		
	TEST_CLASS(TChapter02)
	{
	private:
	public:
		
		TEST_METHOD(TestCtor01)
		{
			Chapter02 target;

			Assert::AreEqual(2, target.getTwo());

		}

	};
}