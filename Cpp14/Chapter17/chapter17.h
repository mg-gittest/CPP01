#pragma once

#include "decl_chapter17.h"

namespace mg_cpp14 {

	class CHAPTER17_DLL Chapter17
	{

	public:

		// virtual dtor
		virtual ~Chapter17();

		// return value for key, or NAN if no data there
		virtual double get(const size_t key) = 0;

		// set value for key, if key not present return NAN, else return previous value
		virtual double set(const size_t key, const double val) = 0;

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
