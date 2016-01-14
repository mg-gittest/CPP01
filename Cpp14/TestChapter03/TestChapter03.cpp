#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Chapter03/chapter03imp.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestChapter03
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Chapter3Test01)
		{
			// TODO: Your test code here
			mg_cpp14::doThings();
		}

	};
}