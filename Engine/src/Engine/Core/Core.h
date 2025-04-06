#pragma once

#define ENABLE_ASSERTS

#ifdef WINDOWS
	#ifdef BUILD_DLL
		#define API __declspec(dllexport)
	#else
		#define API __declspec(dllimport)
	#endif
#else
	#error Only supports windows!
#endif

#define CORE_TRACE(...) ::Engine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CORE_INFO(...) ::Engine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CORE_WARN(...) ::Engine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CORE_ERROR(...) ::Engine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CORE_FATAL(...) ::Engine::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define CLIENT_TRACE(...) ::Engine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CLIENT_INFO(...) ::Engine::Log::GetClientLogger()->info(__VA_ARGS__)
#define CLIENT_WARN(...) ::Engine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CLIENT_ERROR(...) ::Engine::Log::GetClientLogger()->error(__VA_ARGS__)
#define CLIENT_FATAL(...) ::Engine::Log::GetClientLogger()->critical(__VA_ARGS__)

#ifdef ENABLE_ASSERTS
	#define CORE_ASSERT_COND(cond, ...) { if (!(cond)) { CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ASSERT_COND(cond, ...) { if (!(cond)) { CLIENT_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define CORE_ASSERT_COND(cond, ...)
	#define ASSERT_COND(cond, ...)
#endif

#define BIT(x) (1 << x)

#define BIND_FUNCTION_EVENT(x) std::bind(&x, this, std::placeholders::_1)
