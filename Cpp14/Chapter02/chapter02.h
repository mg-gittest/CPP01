#pragma once

#if !defined(MG_CPP14_CHAPTER02)
#define MG_CPP14_CHAPTER02

#include "decl_chapter02.h"


namespace mg_cpp14 {

	class CHAPTER02_DLL Chapter02
	{
	public:
		Chapter02();

		virtual ~Chapter02();

		virtual const std::vector<long> & getVec() = 0;

		virtual void incVec_for_each() = 0;
		
		virtual void incVec_for() = 0;
		

	};
	
	
}

#endif