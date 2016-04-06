#pragma once

#include "chapter16.h"

namespace mg_cpp14 {

	class CHAPTER16_DLL Chapter16list : public Chapter16
	{
	public:
		// default ctor
		Chapter16list();

		// ctor
		Chapter16list(int baseVal);

		// copy ctor
		Chapter16list(const Chapter16list& that);

		// move ctor
		Chapter16list(Chapter16list&& that);

		// virtual dtor
		virtual ~Chapter16list();

		// inserts val in first position in data, return true on success
		virtual bool insertFirst(double val) override;

		// inserts val in second position in data, return true on success
		virtual bool insertSecond(double val) override;

		// remove data at second position, return true on success
		virtual bool removeSecond() override;

		// remove data at third position, return true on success
		virtual bool removeThird() override;

		// return value at given position, or NAN if no data there
		virtual double get(size_t idx) override;

		// fetch a value stored in base class
		virtual int getBaseVal() const override;

	private:
		struct Data;
		Data*  pData;
	};


}
