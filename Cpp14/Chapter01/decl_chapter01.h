#pragma once

#if !defined(CHAPTER01_DLL)
	#if defined(CHAPTER01_EXPORTS)
		#define CHAPTER01_DLL __declspec(dllexport)
	#else
		#define CHAPTER01_DLL __declspec(dllimport)
	#endif
#endif