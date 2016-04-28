#pragma once

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the Clang01_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// Clang01_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef Clang01_EXPORTS
#define Clang01_API __declspec(dllexport)
#else
#define Clang01_API __declspec(dllimport)
#endif

#include <memory>

// This is an example of a class exported from the Clang01.dll
class Clang01_API CClang01
{
	class Impl;
	Impl* pImpl; // need raw pointer to avoid DLL export/import problems
public:
    CClang01(int val);
	virtual ~CClang01();
	int getVal() const;
};

// This is an example of an exported variable
extern Clang01_API int nClang01;

// This is an example of an exported function.
Clang01_API int fnClang01(void);
