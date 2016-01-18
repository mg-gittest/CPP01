// Chapter03.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"


#include "chapter03.h"

namespace mg_cpp14 {
	Chapter03::Chapter03()
	{
		// default to a method that returns false
		set_lambda([](double) { return false; });
	}
	Chapter03::~Chapter03()
	{
	}

	std::function<int(int)> Chapter03::get_lambda() const
	{
		return [](int i) { return abs(i); };
	}

	void Chapter03::set_lambda(const std::function<bool(double)>& lambda)
	{
		_stored_lambda = lambda;
	}
	bool Chapter03::call_lamda(double dd)
	{
		return _stored_lambda(dd);
	}
}

