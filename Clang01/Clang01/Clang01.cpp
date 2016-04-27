// Clang01.cpp : Defines the exported functions for the DLL application.
//

#include "Clang01.h"

// This is an example of an exported variable
Clang01_API int nClang01=0;

// This is an example of an exported function.
Clang01_API int fnClang01(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see Clang01.h for the class definition
CClang01::CClang01()
{
    return;
}
