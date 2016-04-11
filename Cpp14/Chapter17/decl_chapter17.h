#pragma once

#if !defined(CHAPTER17_DLL)
	#if defined(CHAPTER17_EXPORTS)
		#define CHAPTER17_DLL __declspec(dllexport)
		#define CHAPTER17_TEMPLATE_EXPIMP
	#else
		#define CHAPTER17_DLL __declspec(dllimport)
		#define CHAPTER17_TEMPLATE_EXPIMP extern
	#endif
#endif