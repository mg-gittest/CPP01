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

	Chapter02imp::~Chapter02imp()
	{
	}

	const std::vector<long>& Chapter02imp::getVec()
	{
		return vec;
	}

	void Chapter02imp::incVec_for_each()
	{
		std::for_each(vec.begin(), vec.end(), [](long& val) { ++val; });
	}

	void Chapter02imp::incVec_for()
	{
		for (long& val : vec) {
			++val;
		}
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

