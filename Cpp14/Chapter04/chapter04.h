#pragma once

#if !defined(MG_CPP14_CHAPTER04)
#define MG_CPP14_CHAPTER04

#include "decl_chapter04.h"

#include <string>
#include <functional>

namespace mg_cpp14 {

	class CHAPTER04_DLL Chapter04
	{
	private:
		#pragma warning( push )
		#pragma warning( disable : 4251) 
		// class 'XXX' needs to have dll-interface to be used by clients of class
		std::function<bool(double)> _stored_lambda;
		#pragma warning(pop)
	public:

		std::function<int(int)> get_lambda() const;

		void set_lambda(const std::function<bool(double)>& lambda);

		bool call_lamda(double dd);

	public:
		Chapter04();

		virtual ~Chapter04();

	};

	namespace wchar_conv {

		CHAPTER04_DLL int doThings();

	}

	namespace str_switch {

		CHAPTER04_DLL int doStrSwitch(const std::string& str);
	}
	
}

#endif