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

		}

		TEST_METHOD(vectorInc)
		{
			Chapter02 target;

			auto before = target.getVec();

			target.incVec();

			auto after = target.getVec();

			Assert::AreEqual(before.size(), after.size());

			for (size_t idx = 0; idx < before.size(); ++idx) {
				int low = before[idx];
				int hi = after[idx];
				Assert::AreEqual(low + 1, hi);
			}
		}

	};
}