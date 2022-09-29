#pragma once


#ifdef OS_PLATFORM_WINDOWS
	#ifdef OASIS_BUILD_DLL
		#define OASIS_API __declspec(dllexport)
	#else
		#define OASIS_API __declspec(dllimport)
	#endif // OASIS_BUILD_DL
#else
	#error Oasis Supports Only Windows!
#endif // HZ_PLATFORM_WINDOWS
