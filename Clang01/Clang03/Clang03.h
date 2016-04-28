#pragma once

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the Clang03_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// Clang03_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef Clang03_EXPORTS
#define Clang03_API __declspec(dllexport)
#else
#define Clang03_API __declspec(dllimport)
#endif

// This is an example of a class exported from the Clang03.dll
class Clang03_API CClang03
{
	class Impl; // hidden implementation details
	Impl* pImpl; // manages the implementation
public:
    CClang03(int val);
	virtual ~CClang03();
	int getVal() const;
};

// This is an example of an exported variable
extern Clang03_API int nClang03;

// This is an example of an exported function.
Clang03_API int fnClang03(void);
