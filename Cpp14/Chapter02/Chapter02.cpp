// Chapter02.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"


#include "chapter02.h"

namespace mg_cpp14 {

	struct Chapter02::Data {
		std::vector<long> vec;
	};
	
	Chapter02::Chapter02() : data(new Data())
	{
		
		for (long idx = 0; idx <= 5; ++idx) {
			data->vec.push_back(idx);
		}
	}

	Chapter02::~Chapter02()
	{
		delete data;
	}

	const std::vector<long>& Chapter02::getVec()
	{
		return data->vec;
	}

	void Chapter02::incVec()
	{
		auto& vec = data->vec;
		std::for_each(vec.begin(), vec.end(), [](long& val) { ++val; });
	}


}

