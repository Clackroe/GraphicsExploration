
#include "Log.hpp"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

namespace Explore {

static std::shared_ptr<spdlog::logger> _engineLogger;
static std::shared_ptr<spdlog::logger> _appLogger;

spdlog::logger* Log::GetEngineLogger()
{
    return _engineLogger.get();
}

spdlog::logger* Log::GetAppLogger()
{
    return _appLogger.get();
}

void Log::Init()
{

    std::vector<spdlog::sink_ptr> logSinks;
    logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("ExploreEngine.log", true));

    logSinks[0]->set_pattern("%^[%T] %n: %v%$");
    logSinks[1]->set_pattern("[%T] [%l] %n: %v");

    _engineLogger = std::make_shared<spdlog::logger>("Engine", begin(logSinks), end(logSinks));

    spdlog::register_logger(_engineLogger);
    _engineLogger->set_level(spdlog::level::trace);
    _engineLogger->flush_on(spdlog::level::trace);

    std::vector<spdlog::sink_ptr> logSinksApp;
    logSinksApp.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    logSinksApp.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("ExploreEngineApp.log", true));

    logSinksApp[0]->set_pattern("%^[%T] %n: %v%$");
    logSinksApp[1]->set_pattern("[%T] [%l] %n: %v");

    _appLogger = std::make_shared<spdlog::logger>("App", begin(logSinksApp), end(logSinksApp));

    spdlog::register_logger(_appLogger);
    _appLogger->set_level(spdlog::level::trace);
    _appLogger->flush_on(spdlog::level::trace);
}
void Log::Shutdown()
{
    _engineLogger.reset();
    _appLogger.reset();
}

}
