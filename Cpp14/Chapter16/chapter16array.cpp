#include "stdafx.h"

#include "chapter16array.h"
#include "chapter16_protected.h"

#include <cmath> // for NAN
#include <array>

namespace mg_cpp14 {

	const int max_count = 10;

	struct Chapter16array::Data {
		std::array<double, max_count> ara;
		Data();
		Data(const Data& that);
		Data(Data&& that);
	};
	
	Chapter16array::Data::Data()
	{
		ara.fill(NAN);
	}

	Chapter16array::Data::Data(const Data& that)
		: ara(that.ara)
	{
	}

	Chapter16array::Data::Data(Data && that)
		: ara(std::move(that.ara))
	{
		const size_t count = std::count_if(that.ara.begin(), that.ara.end(), [](double d) { return isnan(d); });
	}


	Chapter16array::Chapter16array()
		: Chapter16(1), pData(new Chapter16array::Data())
	{
	}

	Chapter16array::Chapter16array(int baseVal)
		: Chapter16(baseVal), pData(new Chapter16array::Data() )
	{

	}

	Chapter16array::Chapter16array(const Chapter16array & that)
		: Chapter16(that.getBaseVal()), pData(that.pData)
	{
	}

	Chapter16array::Chapter16array(Chapter16array && that)
		: Chapter16(that.getBaseVal()), pData(std::move(that.pData))
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
	int Chapter16array::getBaseVal() const
	{
		return bdata->base_val;
	}
}