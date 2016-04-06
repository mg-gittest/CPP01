// Chapter16.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"



#include "chapter16.h"
#include "chapter16_protected.h"

namespace mg_cpp14 {
		
	Chapter16::Chapter16(int baseval)
		: bdata(new BData(baseval))
	{
	}

	Chapter16::~Chapter16() {
		delete bdata;
	}

}

