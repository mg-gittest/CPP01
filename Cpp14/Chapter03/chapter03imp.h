#pragma once

#if !defined(MG_CPP14_CHAPTER03_IMP)
#define MG_CPP14_CHAPTER03_IMP

#include "chapter03.h"

namespace mg_cpp14 {

	class Chapter03imp : public Chapter03
	{
	public:
		CHAPTER03_DLL Chapter03imp();

		CHAPTER03_DLL virtual ~Chapter03imp();
		
	private:
		
	};

	CHAPTER03_DLL int doThings();

}

#endif