#pragma once


#ifdef SN_PLATFORM_WINDOWS
	#ifdef SN_BUILD_DLL
		#define Snoow_API __declspec(dllexport)
	#else
		#define Snoow_API __declspec(dllimport)
	#endif // Snoow_API
#else 
	#error Error!
#endif // SN_PLATFORM_WINDOWS
