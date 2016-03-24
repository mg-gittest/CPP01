#include "stdafx.h"

#include "chapter04add.h"

namespace mg_cpp14 {

	Chapter04Add::Chapter04Add(double add) : add(add)
	{
	}

	Chapter04Add::~Chapter04Add()
	{
	}

	double Chapter04Add::doStuff(double input)
	{
		return add + input;
	}
}