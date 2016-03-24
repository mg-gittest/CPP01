#include "stdafx.h"

#include "chapter04mult.h"

namespace mg_cpp14 {

	Chapter04Mult::Chapter04Mult(double mult) : mult(mult)
	{
	}

	Chapter04Mult::~Chapter04Mult()
	{
	}

	double Chapter04Mult::doStuff(double input)
	{
		return mult * input;
	}
}