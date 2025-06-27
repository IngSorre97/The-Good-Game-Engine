#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace tgge
{
	class TGGE_API Log
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

// Core Log macros
#define TGGE_CORE_TRACE(...) :: tgge::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TGGE_CORE_INFO(...)  :: tgge::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TGGE_CORE_WARN(...)  :: tgge::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TGGE_CORE_ERROR(...) :: tgge::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TGGE_CORE_FATAL(...) :: tgge::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log macros
#define TGGE_CLIENT_TRACE(...) :: tgge::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TGGE_CLIENT_INFO(...)  :: tgge::Log::GetClientLogger()->info(__VA_ARGS__)
#define TGGE_CLIENT_WARN(...)  :: tgge::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TGGE_CLIENT_ERROR(...) :: tgge::Log::GetClientLogger()->error(__VA_ARGS__)
#define TGGE_CLIENT_FATAL(...) :: tgge::Log::GetClientLogger()->fatal(__VA_ARGS__)
