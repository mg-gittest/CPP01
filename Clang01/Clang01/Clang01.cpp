// Clang01.cpp : Defines the exported functions for the DLL application.
//

#include "Clang01.h"

// This is an example of an exported variable
Clang01_API int nClang01=1;

// This is an example of an exported function.
Clang01_API int fnClang01(void)
{
    return 42;
}

class CClang01::Impl {
	const int val;
public:
	Impl(int _val) : val(_val) {}
	int getVal() const { return val;  }
};

// This is the constructor of a class that has been exported.
// see Clang01.h for the class definition
CClang01::CClang01(int val)
	: pImpl( new Impl(val))
{
    return;
}

CClang01::~CClang01()
{
	delete pImpl;
}

int CClang01::getVal() const
{
	return pImpl->getVal();
}
