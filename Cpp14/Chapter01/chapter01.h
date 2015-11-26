#pragma once

#ifndef MG_CPP14_CHAPTER01
#define MG_CPP14_CHAPTER01

#if defined(CHAPTER01_BUILD)
	#define DLLEXPORT __declspec(dllexport)
#else
	#define DLLEXPORT __declspec(dllimport)
#endif

namespace mg_cpp14 {

	class DLLEXPORT Chapter01
	{
	public:
		Chapter01();

		~Chapter01();

		int getOne();
	private:
		int one;

	};

}

#endif