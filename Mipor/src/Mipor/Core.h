#pragma once

#ifdef MP_PLATFORM_WINDOWS
	#ifdef MIPOR_BUILD_DLL
		#define MIPOR_API __declspec(dllexport)
	#else
		#define MIPOR_API __declspec(dllimport)
	#endif
#else 
	#error Mipor only supports Windows!
#endif