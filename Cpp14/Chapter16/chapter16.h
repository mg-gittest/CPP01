#pragma once

#if !defined(MG_CPP14_CHAPTER16)
#define MG_CPP14_CHAPTER16

#include "decl_chapter16.h"

#include <string>
#include <functional>

namespace mg_cpp14 {

	class CHAPTER16_DLL Chapter16
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
		Chapter16();

		virtual ~Chapter16();

	};

	namespace wchar_conv {

		CHAPTER16_DLL int doThings();

	}

	namespace str_switch {

		CHAPTER16_DLL int doStrSwitch(const std::string& str);
	}

}

#endif