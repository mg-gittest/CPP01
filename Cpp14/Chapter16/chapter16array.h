#pragma once

#include "chapter16.h"

namespace mg_cpp14 {
	
	// main class declaration
	class CHAPTER16_DLL Chapter16array : public Chapter16
	{
	public:
		// default ctor
		Chapter16array();

		// ctor
		Chapter16array(int baseVal);

		// copy ctor
		Chapter16array(const Chapter16array& that);

		// move ctor
		Chapter16array(Chapter16array&& that);

		// virtual dtor
		virtual ~Chapter16array();

		// inserts val in first position in data, return true on success
		virtual bool insertFirst(double val) override;

		// inserts val in second position in data, return true on success
		virtual bool insertSecond(double val) override;

		// remove data at second position, return true on success
		virtual bool removeSecond() override;

		// remove data at third position, return true on success
		virtual bool removeThird() override;

		// return value at given position, or NAN if no data there
		virtual double get(const size_t idx) override;

		// set value at index, if index out of range return NAN, else return 0.0
		virtual double set(const size_t idx, const double val) override;

		// fetch a value stored in base class
		virtual int getBaseVal() const override;

	private:
		// PIMPL pattern, definition of struct in cpp file
		struct Data;
		Data* pData;		
	};


}
