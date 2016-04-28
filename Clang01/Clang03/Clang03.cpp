// Clang03.cpp : Defines the exported functions for the DLL application.
//

#include "Clang03.h"

// This is an example of an exported variable
Clang03_API int nClang03=-1;

// This is an example of an exported function.
Clang03_API int fnClang03(void)
{
    return 17;
}


class CClang03::Impl {
	const int val;
public:
	Impl(int _val) : val(_val > 0 ? _val / 2 : -1) {}
	int getVal() const { return val; }
};

// This is the constructor of a class that has been exported.
// see Clang03.h for the class definition
CClang03::CClang03(int val)
	:pImpl(new Impl(val))
{
    return;
}

CClang03::~CClang03()
{
	delete pImpl;
}

int CClang03::getVal() const
{
	return pImpl->getVal();
}

CClang03D::CClang03D(int val)
	: CClang03(val)
{
	i = 1;
}

CClang03D::~CClang03D()
{
	if (i > 0) {}
}
