#pragma once

#include "decl_chapter04.h"

#include <string>
#include <functional>

namespace mg_cpp14 {

	class CHAPTER04_DLL Chapter04
	{
	private:

	public:
		virtual double doStuff(double input) = 0;

	public:
		Chapter04();

		virtual ~Chapter04();

	};

}
