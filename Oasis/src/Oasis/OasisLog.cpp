#include "OasisLog.h"


namespace Oasis {
	
	std::shared_ptr<spdlog::logger>	OasisLog::s_CoreLogger;
	std::shared_ptr<spdlog::logger> OasisLog::s_ClientLogger;

	void OasisLog::init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("OASIS");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}