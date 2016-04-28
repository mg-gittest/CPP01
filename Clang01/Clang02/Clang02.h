#pragma once

// This is an example of a class exported from the Clang02.lib
class CClang02
{
	class Impl; // hidden implementation details
	Impl* pImpl; // manages the implementation
public:
    CClang02(int val);
	virtual ~CClang02();
	int getVal() const;
};

// This is an example of an exported variable
extern int nClang02;

// This is an example of an exported function.
int fnClang02(void);
