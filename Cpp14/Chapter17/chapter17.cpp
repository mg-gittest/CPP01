// Chapter17.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"



#include "chapter17.h"
#include "chapter17_protected.h"

namespace mg_cpp14 {

	Chapter17::Chapter17(int baseval)
		: bdata(new BData(baseval))
	{
	}

	Chapter17::~Chapter17() {
		delete bdata;
	}

}

