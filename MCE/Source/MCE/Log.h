#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace MCE {
	class MCE_API Log
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

/* Core log macros */
#define MCE_CORE_TRACE(...)		::MCE::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MCE_CORE_INFO(...)		::MCE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MCE_CORE_WARN(...)		::MCE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MCE_CORE_ERROR(...)		::MCE::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MCE_CORE_FATAL(...)		::MCE::Log::GetCoreLogger()->fatal(__VA_ARGS__)

/* Client log macros */
#define MCE_TRACE(...)			::MCE::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MCE_INFO(...)			::MCE::Log::GetClientLogger()->info(__VA_ARGS__)
#define MCE_WARN(...)			::MCE::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MCE_ERROR(...)			::MCE::Log::GetClientLogger()->error(__VA_ARGS__)
#define MCE_FATAL(...)			::MCE::Log::GetClientLogger()->fatal(__VA_ARGS__)