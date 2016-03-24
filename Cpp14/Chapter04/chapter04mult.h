#pragma once

#include "chapter04.h"

namespace mg_cpp14 {

	class CHAPTER04_DLL Chapter04Mult : public Chapter04
	{
	public:
		Chapter04Mult(double mult);
				
		virtual ~Chapter04Mult();

		virtual double doStuff(double input) override final;

	private:
		const double mult;
	};


}
