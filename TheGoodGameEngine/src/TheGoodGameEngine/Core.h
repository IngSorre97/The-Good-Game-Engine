#pragma once

#ifdef TGGE_PLATFORM_WINDOWS
	#ifdef TGGE_BUILD_DLL
		#define TGGE_API __declspec(dllexport)
	#else
		#define TGGE_API __declspec(dllimport)
	#endif
#else
	#error The Good Game Engine support is limited to Windows!
#endif

#define BIT(x) (1 << x)