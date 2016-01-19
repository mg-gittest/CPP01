#include "stdafx.h"
#include "CppUnitTest.h"
#include <streambuf>
#include <codecvt>
#include <functional>

#include "../Chapter02/chapter02imp.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mg_cpp14;

namespace TestChapter02
{		

	inline std::wstring ToString(const Chapter02imp& tf) {
		return tf.toString();
	}

	TEST_CLASS(TChapter02)
	{
	private:
		// run an increment vector test with pointer to member function
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

		void testInc2(std::function<void(Chapter02&)> pmf) {
			auto ptr = std::make_unique<Chapter02imp>();
			//auto ptr = new Chapter02imp();
			auto before = ptr->getVec();

			// unique_ptr does not override pointer to member function
			pmf(*ptr); // so need to deref and then use ref instead of ptr

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

		TEST_METHOD(incVec_for_each)
		{
			testInc(&Chapter02::incVec_for_each);
			testInc2(&Chapter02::incVec_for_each);
		}

		TEST_METHOD(incVec_for)
		{
			testInc(&Chapter02::incVec_for);
			testInc2(&Chapter02::incVec_for);
		}
		
		TEST_METHOD(tuples)
		{
			typedef std::tuple<int, float, const char *> TPL;


			TPL tplTemp1(1, 3.14f, "one");
			TPL tplTemp2(2, 3.14f, "two");
			TPL tplTemp3(3, 3.14f, "thr");
			
			auto target1 = std::make_pair(std::get<0>(tplTemp1), std::get<1>(tplTemp1));			

			Chapter02imp f1(1, 2.0f, "hi");
			auto tp = f1.asTuple();

			std::pair<double, Chapter02imp> target2(std::piecewise_construct, std::make_tuple(1.1), tp);
			
			Assert::AreEqual(f1, target2.second);
		}

	};



}