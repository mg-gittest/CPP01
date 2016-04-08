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
		Data(Data&& that) = delete;
	};
	
	Chapter16array::Data::Data()
	{
		ara.fill(NAN);
	}

	Chapter16array::Data::Data(const Data& that)
		: ara(that.ara)
	{
		auto thatp = &that.ara;
		auto thisp = &(this->ara);
		bool check = thisp == thatp;
		if (check) {}
	}

	Chapter16array::Chapter16array()
		: Chapter16array(1)
	{
	}

	Chapter16array::Chapter16array(int baseVal)
		: Chapter16(baseVal), pData(new Chapter16array::Data() )
	{
	}

	Chapter16array::Chapter16array(const Chapter16array & that)
		: Chapter16(that.getBaseVal())
		 ,pData(new Chapter16array::Data(*(that.pData)))
	{
		auto thatp = that.pData;
		auto thisp = this->pData;
		bool check = thisp == thatp;
		if (check) {}
	}

	Chapter16array::Chapter16array(Chapter16array && that)
		: Chapter16(that.getBaseVal()), pData(that.pData)
	{
		auto thatp = that.pData;
		auto thisp = this->pData;
		bool check = thisp == thatp;
		if (check) {}
		that.pData = nullptr;
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
		pData->ara[2] = NAN;
		return true;
	}

	double Chapter16array::get(const size_t idx)
	{
		if (max_count > idx) {
			return pData->ara[idx];
		}
		return NAN;
	}

	double Chapter16array::set(const size_t idx, const double val)
	{
		if (max_count > idx) {
			pData->ara[idx] = val;
			return 0.0;
		}
		return NAN;
	}

	int Chapter16array::getBaseVal() const
	{
		return bdata->base_val;
	}
}