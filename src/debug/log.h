#pragma once
#include <color.h>

#define GT_LOG_INFO(logMsg) std::cout << dye::green("INFO: " logMsg) << std::endl;
#define GT_LOG_WARNING(logMsg) std::cout << dye::yellow("WARNING: " logMsg) << std::endl;
#define GT_LOG_ERROR(logMsg) std::cout << dye::red("ERROR: " logMsg) << std::endl;
#define GT_LOG_FATAL(logMsg) std::cout << dye::white_on_red("FATAL: " logMsg) << std::endl;
