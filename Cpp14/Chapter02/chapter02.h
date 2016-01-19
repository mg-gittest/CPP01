#pragma once

#if !defined(MG_CPP14_CHAPTER02)
#define MG_CPP14_CHAPTER02

#include "decl_chapter02.h"

#include <tuple>

namespace mg_cpp14 {

	class CHAPTER02_DLL Chapter02
	{
	public:
		Chapter02();

		virtual ~Chapter02();

		virtual const std::vector<long> & getVec() = 0;

		virtual void incVec_for_each() = 0;
		
		virtual void incVec_for() = 0;
		
	private:
		int i;
		float f;
		const char * msg;

	public:
		Chapter02(int a, float b, const char * c);

		auto asTuple() const {
			return std::make_tuple(i, f, msg);
		}

		bool equalTo(const Chapter02& rhs) const;

		std::wstring toString() const;

	};
	
	
}

#endif