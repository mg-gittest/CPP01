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
	public:
		
		TEST_METHOD(TestCtor01)
		{
			Chapter02 * target = new Chapter02imp();
			delete target;
		}

		TEST_METHOD(incVec1)
		{
			Chapter02 * target = new Chapter02imp();

			auto before = target->getVec();

			target->incVec1();

			auto after = target->getVec();

			Assert::AreEqual(before.size(), after.size());

			for (size_t idx = 0; idx < before.size(); ++idx) {
				int low = before[idx];
				int hi = after[idx];
				Assert::AreEqual(low + 1, hi);
			}
			
			delete target;

		}

		TEST_METHOD(incVec2)
		{
			Chapter02 * target = new Chapter02imp();

			auto before = target->getVec();

			target->incVec2();

			auto after = target->getVec();

			Assert::AreEqual(before.size(), after.size());

			for (size_t idx = 0; idx < before.size(); ++idx) {
				int low = before[idx];
				int hi = after[idx];
				Assert::AreEqual(low + 1, hi);
			}

			delete target;

		}

	};
}