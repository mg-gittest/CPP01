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
		
		TEST_METHOD(TestCtor01)
		{
			// TODO: Your test code here
			Chapter01 target;

			Assert::AreEqual(0, target.getOne());
		}

	};
}