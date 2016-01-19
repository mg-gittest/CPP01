// Chapter02.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"


#include "chapter02.h"

#include <sstream>
#include <codecvt>
#include <tuple>

namespace mg_cpp14 {
	Chapter02::Chapter02()
	{
	}
	Chapter02::~Chapter02()
	{
	}

	Chapter02::Chapter02(int a, float b, const char * c) {
		i = a;
		f = b;
		msg = c;
	}

	bool Chapter02::equalTo(const Chapter02& rhs) const {
		return i == rhs.i
			&& f == rhs.f
			&& msg == rhs.msg;
	}

	std::wstring Chapter02::toString() const {
		std::wstringstream ret;
		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
		std::wstring wmsg = converter.from_bytes(msg);

		ret << L"Foo{" << std::to_wstring(i)
			<< L"," << std::to_wstring(f)
			<< L"," << wmsg
			<< L"}"
			;

		return ret.str();
	}

}

