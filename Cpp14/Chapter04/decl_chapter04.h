#pragma once

#if !defined(CHAPTER04_DLL)
	#if defined(CHAPTER04_EXPORTS)
		#define CHAPTER04_DLL __declspec(dllexport)
		#define TEMPLATE_EXPIMP
	#else
		#define CHAPTER04_DLL __declspec(dllimport)
		#define TEMPLATE_EXPIMP extern
	#endif
#endif