#include "stdafx.h"

#include "chapter17unMap.h"
#include "chapter17_protected.h"

#include <cmath> // for NAN
#include <unordered_map>

namespace mg_cpp14 {
	
	struct Chapter17unMap::Data {
		std::unordered_map<size_t, double> unMap;
		Data();
		Data(const Data& that);
		Data(Data&& that) = delete;
	};

	Chapter17unMap::Data::Data()
	{
	}

	Chapter17unMap::Data::Data(const Data& that)
		: unMap(that.unMap)
	{
		auto thatp = &that.unMap;
		auto thisp = &(this->unMap);
		bool check = thisp == thatp;
		if (check) {}
	}

	Chapter17unMap::Chapter17unMap()
		: Chapter17unMap(1)
	{
	}

	Chapter17unMap::Chapter17unMap(int baseVal)
		: Chapter17(baseVal), pData(new Chapter17unMap::Data() )
	{
	}

	Chapter17unMap::Chapter17unMap(const Chapter17unMap & that)
		: Chapter17(that.getBaseVal())
		 ,pData(new Chapter17unMap::Data(*(that.pData)))
	{
		auto thatp = that.pData;
		auto thisp = this->pData;
		bool check = thisp == thatp;
		if (check) {}
	}

	Chapter17unMap::Chapter17unMap(Chapter17unMap && that)
		: Chapter17(that.getBaseVal()), pData(that.pData)
	{
		auto thatp = that.pData;
		auto thisp = this->pData;
		bool check = thisp == thatp;
		if (check) {}
		that.pData = nullptr;
	}

	Chapter17unMap::~Chapter17unMap()
	{
		delete pData;
	}

	double Chapter17unMap::get(const size_t idx)
	{
		auto it = pData->unMap.find(idx);
		if (it == pData->unMap.end()) {
			return NAN;
		}
		else { 
			return it->second; 
		}
	}

	double Chapter17unMap::set(const size_t idx, const double val)
	{
		return pData->unMap[idx] = val;
	}

	int Chapter17unMap::getBaseVal() const
	{
		return bdata->base_val;
	}

	size_t Chapter17unMap::size() const
	{
		return pData->unMap.size();
	}

	
}