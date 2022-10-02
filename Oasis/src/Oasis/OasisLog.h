#pragma once
#include "Core.h"
#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Oasis{


	class OASIS_API OasisLog
	{

	public:
		static void init();
		static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger;}
		static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};


}

//CORE LOG MACROS

#define HZ_CORE_TRACE(...) ::Oasis::OasisLog::getCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)  ::Oasis::OasisLog::getCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)  ::Oasis::OasisLog::getCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...) ::Oasis::OasisLog::getCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...) ::Oasis::OasisLog::getCoreLogger()->fatal(__VA_ARGS__)

//Client LOG MACROS

#define HZ_CLIENT_TRACE(...)  ::Oasis::OasisLog::getClientLogger()->trace(__VA_ARGS__)
#define HZ_CLIENT_INFO(...)	  ::Oasis::OasisLog::getClientLogger()->info(__VA_ARGS__)
#define HZ_CLIENT_WARN(...)	  ::Oasis::OasisLog::getClientLogger()->warn(__VA_ARGS__)
#define HZ_CLIENT_ERROR(...)  ::Oasis::OasisLog::getClientLogger()->error(__VA_ARGS__)
#define HZ_CLIENT_FATAL(...)  ::Oasis::OasisLog::getClientLogger()->fatal(__VA_ARGS__)