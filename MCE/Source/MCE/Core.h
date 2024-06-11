#pragma once

#ifdef MCE_BUILD_DLL 
	#define MCE_API __declspec(dllexport)
#else
	#define MCE_API __declspec(dllimport)
#endif
