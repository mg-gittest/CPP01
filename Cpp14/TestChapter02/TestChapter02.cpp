#include "stdafx.h"
#include "CppUnitTest.h"
#include <streambuf>
#include <codecvt>

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

		TEST_METHOD(incVec_for_each)
		{
			testInc(&Chapter02::incVec_for_each);
		}

		TEST_METHOD(incVec_for)
		{
			testInc(&Chapter02::incVec_for);
		}

		class Foo {
			int i;
			float f;
			const char * msg;

		public:
			Foo(int a, float b, const char * c) {
				i = a;
				f = b;
				msg = c;
			}

			auto asTuple() const {
				return std::make_tuple(i, f, msg);
			}

			bool erica(const Foo& rhs) const {
				return i   == rhs.i
					&& f   == rhs.f
					&& msg == rhs.msg;
			}

			std::wstring toString() const {
				std::wstringstream ret;
				std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
				std::wstring wmsg = converter.from_bytes(msg);

				ret << L"Foo{" << std::to_wstring(i)
					<< L"," << std::to_wstring(f)
					<< L"," << wmsg
					<< L"}"
					;
				
				return ret.str();
			}
		};
		

		TEST_METHOD(tuples)
		{
			typedef std::tuple<int, float, const char *> TPL;


			TPL tplTemp1(1, 3.14f, "one");
			TPL tplTemp2(2, 3.14f, "two");
			TPL tplTemp3(3, 3.14f, "thr");
			
			auto target1 = std::make_pair(std::get<0>(tplTemp1), std::get<1>(tplTemp1));			

			Foo f1(1, 2.0f, "hi");
			auto tp = f1.asTuple();

			std::pair<double, Foo> target2(std::piecewise_construct, std::make_tuple(1.1), tp);
			
			Assert::AreEqual(f1, target2.second);
		}

	};

	typedef TestChapter02::TChapter02::Foo TF;

	bool operator==(const TF& lhs, const TF& rhs) {
		return lhs.erica(rhs);
	}

	inline std::wstring ToString(const TF& tf) { 
		return tf.toString(); 
	}
}