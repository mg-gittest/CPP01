#pragma once

#include "chapter17.h"

namespace mg_cpp14 {

	// implements map properties using hidden regular map
	class CHAPTER17_DLL Chapter17regMap : public Chapter17
	{
	public:
		// default ctor
		Chapter17regMap();

		// ctor
		Chapter17regMap(int baseVal);

		// copy ctor
		Chapter17regMap(const Chapter17regMap& that);

		// move ctor
		Chapter17regMap(Chapter17regMap&& that);

		// virtual dtor
		virtual ~Chapter17regMap();

		// return value for key, or NAN if no data there
		virtual double get(const size_t key) override;

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
