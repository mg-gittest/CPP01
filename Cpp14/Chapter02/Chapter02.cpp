// Chapter02.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"


#include "chapter02.h"

namespace mg_cpp14 {
	Chapter02::Chapter02()
	{
		for (int idx = 0; idx <= 5; ++idx) {
			vec.push_back(idx);
		}
	}

	Chapter02::~Chapter02()
	{
	}

	const std::vector<long>& Chapter02::getVec()
	{
		return vec;
	}

	void Chapter02::incVec()
	{
		std::for_each(vec.begin(), vec.end(), [](long& val) { ++val; });
	}


}

