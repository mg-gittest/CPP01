// Clang02.cpp : Defines the exported functions for the static library.
//

#include "Clang02.h"

#include <string>

// This is an example of an exported variable
int nClang02=0;

// This is an example of an exported function.
int fnClang02(void)
{
    return 12;
}

class CClang02::Impl {
	const int val;
public:
	Impl(int _val) : val(_val * _val) {}
	int getVal() const { return val; }
	~Impl() {
		if (val > 0)
		{
		}
	}
};

// This is the constructor of a class that has been exported.
// see Clang02.h for the class definition
CClang02::CClang02(int val)
	: pImpl(new Impl(val))
{
    return;
}

int CClang02::getVal() const
{
	return pImpl->getVal();
}
