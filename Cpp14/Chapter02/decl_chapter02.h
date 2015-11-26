#pragma once

#if !defined(CHAPTER02_DLL)
	#if defined(CHAPTER02_BUILD)
		#define CHAPTER02_DLL __declspec(dllexport)
	#else
		#define CHAPTER02_DLL __declspec(dllimport)
	#endif
#endif