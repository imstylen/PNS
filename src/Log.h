#pragma once

#include "spdlog/spdlog.h"

class Log
{
public:

	void LogExamples();
    
};

#define PNS_LOG(...) ::spdlog::info(__VA_ARGS__)
