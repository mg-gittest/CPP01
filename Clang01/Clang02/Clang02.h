#pragma once

#include <memory>

// This is an example of a class exported from the Clang02.lib
class CClang02
{
	class Impl; // hidden implementation details
	std::shared_ptr<Impl> pImpl; // can use smart pointer as static linkage
public:
    CClang02(int val);
	int getVal() const;
};

// This is an example of an exported variable
extern int nClang02;

// This is an example of an exported function.
int fnClang02(void);
