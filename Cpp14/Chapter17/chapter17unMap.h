#pragma once

#include "chapter17.h"

namespace mg_cpp14 {

	// implements map properties using hidden unordered map
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

		// return value for key, or NAN if no data there
		virtual double get(const size_t idx) override;

		// set value for key, if key not present return NAN, else return previous value
		virtual double set(const size_t key, const double val) override;

		// fetch a value stored in base class
		virtual int getBaseVal() const override;

		// fetch the size of the underlying map
		virtual size_t size() const override;

	private:
		// PIMPL pattern, definition of struct in cpp file
		struct Impl;
		Impl* pData;
	};


}
