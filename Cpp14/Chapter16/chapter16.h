#pragma once

#if !defined(MG_CPP14_CHAPTER16)
#define MG_CPP14_CHAPTER16

#include "decl_chapter16.h"

namespace mg_cpp14 {

	class CHAPTER16_DLL Chapter16
	{

	public:
		// virtual dtor
		virtual ~Chapter16();

		// inserts val in first position in data, return true on success
		virtual bool insertFirst(double val) = 0;

		// inserts val in second position in data, return true on success
		virtual bool insertSecond(double val) = 0;

		// remove data at second position, return true on success
		virtual bool removeSecond() = 0;

		// remove data at third position, return true on success
		virtual bool removeThird() = 0;

		// return value at given position, or NAN if no data there
		virtual double get(size_t idx) = 0;

	};

}

#endif