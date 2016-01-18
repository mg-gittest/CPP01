#pragma once

#if !defined(MG_CPP14_CHAPTER01)
#define MG_CPP14_CHAPTER01

#include "decl_chapter01.h"

namespace mg_cpp14 {

	class CHAPTER01_DLL Chapter01
	{
	public:
		Chapter01();

		~Chapter01();

		int calcSum(const int max);

		Chapter01* getThis();

		auto getThisToo() -> decltype(this);

		template<typename X, typename Y>
		auto multiply(const X& x, const Y& y)
		{
			return (x * y);
		};

		template<typename X, typename Y>
		auto multiplyTrail(const X& x, const Y& y) -> decltype(x * y)
		{
			return (x * y);
		};


	private:

	};

}

#endif