#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>

namespace Mipor {
	
	class MIPOR_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define MP_CORE_TRACE(...) ::Mipor::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MP_CORE_INFO(...)  ::Mipor::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MP_CORE_WARN(...)  ::Mipor::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MP_CORE_ERROR(...) ::Mipor::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MP_CORE_FATAL(...) ::Mipor::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Core log macros
#define MP_TRACE(...)      ::Mipor::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MP_INFO(...)       ::Mipor::Log::GetClientLogger()->info(__VA_ARGS__)
#define MP_WARN(...)       ::Mipor::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MP_ERROR(...)      ::Mipor::Log::GetClientLogger()->error(__VA_ARGS__)
#define MP_FATAL(...)      ::Mipor::Log::GetClientLogger()->fatal(__VA_ARGS__)
