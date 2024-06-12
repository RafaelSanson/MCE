#pragma once

#ifdef MCE_PLATFORM_WINDOWS
	#ifdef MCE_BUILD_DLL 
		#define MCE_API __declspec(dllexport)
	#else
		#define MCE_API __declspec(dllimport)
	#endif
#else
	#error MCE can only build for Windows platform
#endif