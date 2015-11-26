// Chapter01.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "chapter01.h"

namespace mg_cpp14 {
	Chapter01::Chapter01()
	{
	}

	Chapter01::~Chapter01()
	{
	}

	int Chapter01::calcSum(const int max) {

		std::vector<int> vec;

		for (int idx = 1; idx <= max; ++idx) {
			vec.push_back(idx);
		}

		int ret = 0;

		for (decltype(vec)::iterator iter = vec.begin(); iter != vec.end(); ++iter) {
			ret += *iter;
		}

		return ret;

	}
	Chapter01 * Chapter01::getThis()
	{
		return this;
	}
}
