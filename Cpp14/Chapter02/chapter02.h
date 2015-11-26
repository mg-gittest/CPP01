#pragma once

#if !defined(MG_CPP14_CHAPTER02)
#define MG_CPP14_CHAPTER02

#include "decl_chapter02.h"

namespace mg_cpp14 {

	class CHAPTER02_DLL Chapter02
	{
	public:
		Chapter02();

		~Chapter02();

		const std::vector<long> & getVec();

		void incVec();

	private:
		std::vector<long> vec;
	};

}

#endif