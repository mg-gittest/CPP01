#include "stdafx.h"

#include "chapter16list.h"
#include "chapter16_protected.h"

#include <forward_list>

namespace mg_cpp14 {

	struct Chapter16list::Data {
		std::forward_list<double> list;
		
		Data() = default;

		Data(const Data& that)
			: list(that.list)
		{
		}

		Data(Data&& that) = delete;
	};
	
	Chapter16list::Chapter16list()
		: Chapter16(2), pData(new Data())
	{
	}

	Chapter16list::Chapter16list(int baseVal)
		: Chapter16(baseVal), pData(new Data())
	{		
	}

	Chapter16list::Chapter16list(const Chapter16list & that)
		: Chapter16(that.getBaseVal()), pData(new Data(*(that.pData)))
	{
	}

	Chapter16list::Chapter16list(Chapter16list && that)
		: Chapter16(that.getBaseVal()), pData(that.pData)
	{
		that.pData = nullptr;
	}

	Chapter16list::~Chapter16list()
	{
		delete pData;
	}

	bool Chapter16list::insertFirst(double val)
	{
		// alterative --- 
		// pData->list.push_front(val);
		pData->list.insert_after(pData->list.before_begin(), val);
		return true;
	}

	bool Chapter16list::insertSecond(double val)
	{
		pData->list.insert_after(pData->list.begin(), val);
		return true;
	}

	bool Chapter16list::removeSecond()
	{
		auto it = pData->list.erase_after(pData->list.begin());
		return it != pData->list.end();;
	}

	bool Chapter16list::removeThird()
	{
		auto it = pData->list.begin();
		++it;
		it = pData->list.erase_after(it);
		return it != pData->list.end();
	}

	double Chapter16list::get(size_t idx)
	{
		auto it = pData->list.begin();
		while (0 < idx-- && it != pData->list.end()) {
			++it;
		}
		return it != pData->list.end() ? *it : NAN;
	}

	int Chapter16list::getBaseVal() const
	{
		return bdata->base_val;
	}
}