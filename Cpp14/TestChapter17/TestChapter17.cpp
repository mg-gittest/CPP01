#include "stdafx.h"
#include "CppUnitTest.h"

#include <memory>

#include "../Chapter17/chapter17unMap.h"
#include "../Chapter17/chapter17regMap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mg_cpp14;

namespace TestChapter17
{
	using tgtPtr = Chapter17*;

	TEST_CLASS(UnitTest1)
	{
	private:
		const double tolerance = 1.0E-12;
		const size_t k1 = 1;
		const size_t k2 = 2;
		const size_t k3 = 3;
		const size_t k4 = 4;
		const double v1 = 1.23;
		const double v2 = 2.34;
		const double v3 = 3.45;
		const double v4 = 4.56;

		void loadFour(Chapter17* target) {
			target->set(k1, v1);
			target->set(k2, v2);
			target->set(k3, v3);
			target->set(k4, v4);
		}

		void checkValue(Chapter17* target, const size_t key, const double expect) {
			double actual = target->get(key);
			Assert::AreEqual(expect, actual, tolerance);
		}
	public:

		TEST_METHOD(chapter17_un_map_default)
		{
			tgtPtr target = new Chapter17unMap();

			const double actual = target->get(k1);
			Assert::IsTrue(isnan(actual));
		}

		TEST_METHOD(chapter17_un_map_load4)
		{
			tgtPtr target = new Chapter17unMap();

			size_t actual = target->size();
			Assert::AreEqual(size_t(0), actual );

			loadFour(target);

			actual = target->size();
			Assert::AreEqual(size_t(4), actual);

			checkValue(target, k1, v1);
			checkValue(target, k2, v2);
			checkValue(target, k3, v3);
			checkValue(target, k4, v4);

		}

		TEST_METHOD(chapter17_un_map_copy) {
			int inner = 3;
			tgtPtr target = nullptr;
			{
				Chapter17unMap one(inner);
				loadFour(&one);

				target = new Chapter17unMap(one);
			}

			size_t actual = target->size();
			Assert::AreEqual(size_t(4), actual);

			checkValue(target, k1, v1);
			checkValue(target, k2, v2);
			checkValue(target, k3, v3);
			checkValue(target, k4, v4);
		}

		TEST_METHOD(chapter17_un_map_move) {
			int inner = 3;
			tgtPtr target = nullptr;
			{
				Chapter17unMap one(inner);
				loadFour(&one);

				target = new Chapter17unMap(std::move(one));
			}

			size_t actual = target->size();
			Assert::AreEqual(size_t(4), actual);

			checkValue(target, k1, v1);
			checkValue(target, k2, v2);
			checkValue(target, k3, v3);
			checkValue(target, k4, v4);
		}


		TEST_METHOD(chapter17_reg_map_default)
		{
			tgtPtr target = new Chapter17regMap();

			const double actual = target->get(k1);
			Assert::IsTrue(isnan(actual));
		}

		TEST_METHOD(chapter17_reg_map_load4)
		{
			tgtPtr target = new Chapter17regMap();

			size_t actual = target->size();
			Assert::AreEqual(size_t(0), actual);

			loadFour(target);

			actual = target->size();
			Assert::AreEqual(size_t(4), actual);

			checkValue(target, k1, v1);
			checkValue(target, k2, v2);
			checkValue(target, k3, v3);
			checkValue(target, k4, v4);

		}

		TEST_METHOD(chapter17_reg_map_copy) {
			int inner = 3;
			tgtPtr target = nullptr;
			{
				Chapter17regMap one(inner);
				loadFour(&one);

				target = new Chapter17regMap(one);
			}

			size_t actual = target->size();
			Assert::AreEqual(size_t(4), actual);

			checkValue(target, k1, v1);
			checkValue(target, k2, v2);
			checkValue(target, k3, v3);
			checkValue(target, k4, v4);
		}

		TEST_METHOD(chapter17_reg_map_move) {
			const int inner = 3;
			tgtPtr target = nullptr;
			{
				Chapter17regMap one(inner);
				loadFour(&one);

				target = new Chapter17regMap(std::move(one));
			}

			Assert::AreEqual(inner, target->getBaseVal());
			size_t actual = target->size();
			Assert::AreEqual(size_t(4), actual);

			checkValue(target, k1, v1);
			checkValue(target, k2, v2);
			checkValue(target, k3, v3);
			checkValue(target, k4, v4);
		}

		TEST_METHOD(chapter17_2darray) {
			int val[3][4] = {};

			int* p11 = &(val[0][1]);
			int* p12 = &(val[1][1]);
			int* p13 = &(val[2][1]);

			ptrdiff_t d12 = reinterpret_cast<char*>(p12) - reinterpret_cast<char*>(p11);
			ptrdiff_t d23 = reinterpret_cast<char*>(p13) - reinterpret_cast<char*>(p12);
			
			Assert::IsTrue(d12 == d23);
		}


	};
}