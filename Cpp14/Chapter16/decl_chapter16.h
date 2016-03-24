#pragma once

#if !defined(CHAPTER16_DLL)
	#if defined(CHAPTER16_EXPORTS)
		#define CHAPTER16_DLL __declspec(dllexport)
		#define TEMPLATE_EXPIMP
	#else
		#define CHAPTER16_DLL __declspec(dllimport)
		#define TEMPLATE_EXPIMP extern
	#endif
#endif