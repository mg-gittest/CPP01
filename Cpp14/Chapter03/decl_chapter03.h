#pragma once

#if !defined(CHAPTER03_DLL)
	#if defined(CHAPTER03_EXPORTS)
		#define CHAPTER03_DLL __declspec(dllexport)
		#define TEMPLATE_EXPIMP
	#else
		#define CHAPTER03_DLL __declspec(dllimport)
		#define TEMPLATE_EXPIMP extern
	#endif
#endif