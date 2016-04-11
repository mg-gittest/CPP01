#pragma once

#include "decl_chapter17.h"

namespace mg_cpp14 {

	class CHAPTER17_DLL Chapter17
	{

	public:

		// virtual dtor
		virtual ~Chapter17();

		// return value at given position, or NAN if no data there
		virtual double get(const size_t idx) = 0;

		// set value at index, if index out of range return NAN, else return 0.0
		virtual double set(const size_t idx, const double val) = 0;

		// fetch a value stored in base class
		virtual int getBaseVal() const = 0;

		// fetch the size of the underlying map
		virtual size_t size() const = 0;

	protected:
		// protected data structure, defined in chapter17_protected.h
		struct BData;
		BData* bdata;

		// ctor for derived classes
		Chapter17(int baseval);
	};

}
