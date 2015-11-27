#pragma once

#if !defined(MG_CPP14_CHAPTER02_IMP)
#define MG_CPP14_CHAPTER02_IMP

#include "chapter02.h"

namespace mg_cpp14 {

	class Chapter02imp : public Chapter02
	{
	public:
		CHAPTER02_DLL Chapter02imp();

		CHAPTER02_DLL virtual ~Chapter02imp();

		virtual const std::vector<long> & getVec();

		virtual void incVec1();

		virtual void incVec2();

	private:
		std::vector<long> vec;
	};



}

#endif