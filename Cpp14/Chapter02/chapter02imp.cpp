// Chapter02.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include <iostream>
#include <utility>
#include <tuple>


#include "chapter02imp.h"

namespace mg_cpp14 {

	Chapter02imp::Chapter02imp()
	{
		for (long idx = 0; idx <= 5; ++idx) {
			vec.push_back(idx);
		}
	}

	Chapter02imp::Chapter02imp(int a, float b, const char * c)
		: Chapter02(a,b,c)
	{
	}

	Chapter02imp::~Chapter02imp()
	{
	}

	const std::vector<long>& Chapter02imp::getVec()
	{
		return vec;
	}

	void Chapter02imp::incVec_for_each()
	{
		std::for_each(vec.begin(), vec.end(), [](auto& val) { ++val; });
	}

	void Chapter02imp::incVec_for()
	{
		for (auto& val : vec) {
			++val;
		}
	}

	bool Chapter02imp::operator==(const Chapter02 & rhs) const
	{
		return equalTo(rhs);
	}

	Chapter02imp::Chapter02imp(std::tuple<int, float>)
	{
		std::cout << "Constructed from a tuple" << std::endl;
	}

	Chapter02imp::Chapter02imp(int, float)
	{
		std::cout << "Constructed from an int and a float" << std::endl;
	}
	
}

