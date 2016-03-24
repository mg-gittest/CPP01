#pragma once

#include "chapter04.h"

namespace mg_cpp14 {

	class CHAPTER04_DLL Chapter04Add : public Chapter04
	{
	public:
		Chapter04Add(double add);

		virtual ~Chapter04Add();

		virtual double doStuff(double input) override final;
		
	private:
		const double add;
	};


}

