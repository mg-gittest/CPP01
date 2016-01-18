#pragma once

#if !defined(MG_CPP14_CHAPTER03)
#define MG_CPP14_CHAPTER03

#include "decl_chapter03.h"

#include <string>
#include <functional>

#include "chapter03imp.h"

namespace mg_cpp14 {

	class CHAPTER03_DLL Chapter03
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
		Chapter03();

		virtual ~Chapter03();

	};

	namespace wchar_conv {

		CHAPTER03_DLL int doThings();

	}

	namespace str_switch {

		CHAPTER03_DLL int doStrSwitch(const std::string& str);
	}
	
}

#endif