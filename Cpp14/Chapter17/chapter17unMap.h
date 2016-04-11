#pragma once

#include "chapter17.h"

namespace mg_cpp14 {

	// main class declaration
	class CHAPTER17_DLL Chapter17unMap : public Chapter17
	{
	public:
		// default ctor
		Chapter17unMap();

		// ctor
		Chapter17unMap(int baseVal);

		// copy ctor
		Chapter17unMap(const Chapter17unMap& that);

		// move ctor
		Chapter17unMap(Chapter17unMap&& that);

		// virtual dtor
		virtual ~Chapter17unMap();

		// return value at given position, or NAN if no data there
		virtual double get(const size_t idx) override;

		// set value at index, if index out of range return NAN, else return 0.0
		virtual double set(const size_t idx, const double val) override;

		// fetch a value stored in base class
		virtual int getBaseVal() const override;

		// fetch the size of the underlying map
		virtual size_t size() const override;

	private:
		struct Data;
		Data* pData;
	};


}
