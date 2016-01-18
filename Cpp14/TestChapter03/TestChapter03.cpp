#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Chapter03/chapter03imp.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mg_cpp14;

namespace TestChapter03
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(wchar_conv)
		{
			// TODO: Your test code here
			mg_cpp14::wchar_conv::doThings();
		}

		TEST_METHOD(str_switch)
		{
			auto lookup = std::map<const std::string, int>();
			lookup["one"] = 1;
			lookup["two"] = 2;
			lookup["three"] = 3;
			lookup["four"] = 4;
			lookup["five"] = 0;

			for (auto val : lookup) {
				auto expected = val.second;
				auto key = val.first;
				auto actual = str_switch::doStrSwitch(key);

				Assert::AreEqual(expected, actual);
			}
		}

		TEST_METHOD(lambda_store)
		{
			Chapter03imp target;
			auto first = target.get_lambda();

			Assert::AreEqual(1, first( 1));
			Assert::AreEqual(1, first(-1));

			double db = -1.0;
			Assert::IsFalse(target.call_lamda(db));
			db = 1.0;
			Assert::IsFalse(target.call_lamda(db));

			target.set_lambda([](double d) { return d > 0.0; });
			
			db = -1.0;
			Assert::AreEqual(db > 0.0, target.call_lamda(db));
			db = 1.0;
			Assert::AreEqual(db > 0.0, target.call_lamda(db));
		}
			
	};
}