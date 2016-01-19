// Chapter01.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "chapter01.h"
#include <type_traits>

namespace mg_cpp14 {
	Chapter01::Chapter01()
	{	
	}

	Chapter01::~Chapter01()
	{
	}

	int Chapter01::calcSum(const int max) {

		std::vector<int> vec(max);

		for (int idx = 1; idx <= max; ++idx) {
			vec.push_back(idx);
		}

		int ret = 0;

		for (decltype(vec)::iterator iter = vec.begin(); iter != vec.end(); ++iter) {
			ret += *iter;
		}

		int ret2 = 0;

		for (auto val : vec) {
			ret2 += val;
		}

		if (ret != ret2) {
			throw "wobbly";
		}

		return ret;

	}

	Chapter01 * Chapter01::getThis()
	{
		return this;
	}

	auto Chapter01::getThisToo() -> Chapter01*
	{ 
		return this; 
	}

	struct NoCompile {
		std::string _s;
		decltype(_s.begin()) begin() { return _s.begin(); } // now compiles in VS 2015, VS2012 was broken
	};

	template <typename, typename = true_type>
	struct is_comparable : public false_type
	{};

	/*
	template <typename T>
	struct is_comparable<T,
		typename is_convertible<decltype(declval<T>() > declval<T>()),
		bool>::type> : public true_type
	{};
		gives compiler error on VC2015 14.0.24720
	chapter01.cpp(68) : error C2146 : syntax error : missing '>' before identifier 'is_convertible'
	chapter01.cpp(68) : error C2947 : expecting '>' to terminate template - argument - list, found '<'
	chapter01.cpp(68) : error C2988 : unrecognizable template declaration / definition
	chapter01.cpp(68) : error C2059 : syntax error : 'decltype'
	chapter01.cpp(80) : error C2143 : syntax error : missing ';' before '}'
	*/
	
	/*
	template <typename T>
	T&& declval2() throw();
		above gives warning about declared, but undefined template declval2

	template <typename T>
	typename std::is_convertible<decltype(declval2<T>() > declval2<T>()), bool >::type tt;
		gives compiler error on VC2015 14.0.24720
	chapter01.cpp(85): error C2399: variable templates are not supported in this release
	*/

}
