#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Chapter02/chapter02imp.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mg_cpp14;

namespace TestChapter02
{		
	TEST_CLASS(TChapter02)
	{
	private:
		// run an increment vector test with selected member function
		void testInc(void (Chapter02::* pmf)())
		{
			auto ptr = std::make_unique<Chapter02imp>();

			auto before = ptr->getVec();

			//(ptr->*pmf)(); // unique_ptr does not override pointer to member function
			((*ptr).*pmf)(); // so need to deref and then use .*  instead of ->*

			auto after = ptr->getVec();

			Assert::AreEqual(before.size(), after.size());

			for (size_t idx = 0; idx < before.size(); ++idx) {
				int low = before[idx];
				int hi = after[idx];
				Assert::AreEqual(low + 1, hi);
			}
		}

	public:
		
		TEST_METHOD(TestCtor01)
		{
			std::unique_ptr<Chapter02> target = std::make_unique<Chapter02imp>();
		}

		TEST_METHOD(incVec1)
		{
			testInc(&Chapter02::incVec1);
		}

		TEST_METHOD(incVec2)
		{
			testInc(&Chapter02::incVec2);
		}

	};
}