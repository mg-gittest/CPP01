#include "stdafx.h"

#include "chapter16array.h"


#include <cmath> // for NAN
#include <array>

namespace mg_cpp14 {

	const int max_count = 10;

	struct Chapter16array::Data {
		std::array<double, max_count> ara;
	};
	
	Chapter16array::Chapter16array()
		: pData(new Chapter16array::Data() )
	{
		const double tmpNan = NAN;
		for (size_t idx = 0; idx < max_count; ++idx) {
			pData->ara[idx] = tmpNan;
		}
	}

	Chapter16array::Chapter16array(const Chapter16array & that)
		: pData(that.pData)
	{
	}

	Chapter16array::Chapter16array(Chapter16array && that)
		: pData(std::move(that.pData))
	{
	}

	Chapter16array::~Chapter16array()
	{
		delete pData;
	}

	bool Chapter16array::insertFirst(double val)
	{
		pData->ara[0] = val;
		return true;
	}

	bool Chapter16array::insertSecond(double val)
	{
		pData->ara[1] = val;
		return true;
	}

	bool Chapter16array::removeSecond()
	{
		pData->ara[1] = NAN;
		return true;
	}

	bool Chapter16array::removeThird()
	{
		pData->ara[3] = NAN;
		return true;
	}

	double Chapter16array::get(size_t idx)
	{
		if (max_count > idx) {
			return pData->ara[idx];
		}
		return NAN;
	}
}