#pragma once

#if !defined(CHAPTER02_DLL)
	#if defined(CHAPTER02_EXPORTS)
		#define CHAPTER02_DLL __declspec(dllexport)
		#define TEMPLATE_EXPIMP
	#else
		#define CHAPTER02_DLL __declspec(dllimport)
		#define TEMPLATE_EXPIMP extern
	#endif
#endif