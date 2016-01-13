#pragma once

#if !defined(MG_CPP14_CHAPTER02_IMP)
#define MG_CPP14_CHAPTER02_IMP

#include "chapter02.h"

#include <tuple>

namespace mg_cpp14 {

	class Chapter02imp : public Chapter02
	{
	public:
		CHAPTER02_DLL Chapter02imp();

		CHAPTER02_DLL virtual ~Chapter02imp();

		CHAPTER02_DLL Chapter02imp(std::tuple<int, float>);

		CHAPTER02_DLL Chapter02imp(int, float);

		virtual const std::vector<long> & getVec();

		virtual void incVec_for_each();

		virtual void incVec_for();

	private:
		std::vector<long> vec;
	};



}

#endif