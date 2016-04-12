#include "stdafx.h"

#include "chapter17regMap.h"
#include "chapter17_protected.h"

#include <cmath> // for NAN
#include <map>

namespace mg_cpp14 {

	struct Chapter17regMap::Data {
		std::map<size_t, double> regMap;
		Data();
		Data(const Data& that);
		Data(Data&& that) = delete;
	};

	Chapter17regMap::Data::Data()
	{
	}

	Chapter17regMap::Data::Data(const Data& that)
		: regMap(that.regMap)
	{
		auto thatp = &that.regMap;
		auto thisp = &(this->regMap);
		bool check = thisp == thatp;
		if (check) {}
	}

	Chapter17regMap::Chapter17regMap()
		: Chapter17regMap(1)
	{
	}

	Chapter17regMap::Chapter17regMap(int baseVal)
		: Chapter17(baseVal), pData(new Chapter17regMap::Data() )
	{
	}

	Chapter17regMap::Chapter17regMap(const Chapter17regMap & that)
		: Chapter17(that.getBaseVal())
		 ,pData(new Chapter17regMap::Data(*(that.pData)))
	{
		auto thatp = that.pData;
		auto thisp = this->pData;
		bool check = thisp == thatp;
		if (check) {}
	}

	Chapter17regMap::Chapter17regMap(Chapter17regMap && that)
		: Chapter17(that.getBaseVal()), pData(that.pData)
	{
		auto thatp = that.pData;
		auto thisp = this->pData;
		bool check = thisp == thatp;
		if (check) {}
		that.pData = nullptr;
	}

	Chapter17regMap::~Chapter17regMap()
	{
		delete pData;
	}

	double Chapter17regMap::get(const size_t key)
	{
		auto it = pData->regMap.find(key);
		if (it == pData->regMap.end()) {
			return NAN;
		}
		else {
			return it->second;
		}
	}

	double Chapter17regMap::set(const size_t key, const double val)
	{
		return pData->regMap[key] = val;
	}

	int Chapter17regMap::getBaseVal() const
	{
		return bdata->base_val;
	}

	size_t Chapter17regMap::size() const
	{
		return pData->regMap.size();
	}


}