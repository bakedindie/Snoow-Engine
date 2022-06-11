#pragma once



//Defining the API import and export

#ifdef SN_PLATFORM_WINDOWS
	#ifdef SN_BUILD_DLL
		#define Snoow_API __declspec(dllexport)
	#else
		#define Snoow_API __declspec(dllimport)
	#endif // Snoow_API
#else 
	#error Error!
#endif // SN_PLATFORM_WINDOWS

//defining LOG macros

#define SN_CORE_TRACE(...) Snoow::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SN_CORE_INFO(...) Snoow::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SN_CORE_WARN(...) Snoow::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SN_CORE_ERROR(...) Snoow::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SN_CORE_CRITICAL(...) Snoow::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define SN_TRACE(...) Snoow::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SN_INFO(...) Snoow::Log::GetClientLogger()->info(__VA_ARGS__)
#define SN_WARN(...) Snoow::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SN_ERROR(...) Snoow::Log::GetClientLogger()->error(__VA_ARGS__)
#define SN_CRITICAL(...) Snoow::Log::GetClientLogger()->critical(__VA_ARGS__)

#define Event_Dispatch(X) _window->Eventhandler(X)


#ifdef SN_ENABLE_ASSERTS
	#define SN_ASSERT(X, ...) {if(!(X)) {SN_ERROR("Assertion Failed : {0}", __VA_ARG__); __debugbreak();}}
	#define SN_CORE_ASSERT(X, ...) {if(!(X)) {SN_CORE_ERROR("Assertion Failed : {0}", __VA_ARG__); __debugbreak();}}
#else
#define SN_ASSERT(X, ...)
#define SN_CORE_ASSERT(X, ...)
#endif