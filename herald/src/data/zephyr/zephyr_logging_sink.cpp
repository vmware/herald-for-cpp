//  Copyright 2021 Herald Project Contributors
//  SPDX-License-Identifier: Apache-2.0
//

#include "herald/data/zephyr/zephyr_logging_sink.h"

#include <logging/log.h>

#include <string>

namespace herald {

// THE BELOW IS DONE IN EXACTLY ONE HERALD FILE
LOG_MODULE_REGISTER(heraldlogger, HERALD_LOG_LEVEL);

namespace data {

void
ZephyrLoggingSink::log(const std::string& subsystem,const std::string& category,
  SensorLoggerLevel level, const std::string& message)
{
  // TODO be more specific? Filter here or in Zephyr?
  std::string finalMessage = subsystem + "," + category + "," + message;
  switch (level) {
    case SensorLoggerLevel::debug:
      LOG_DBG("%s",log_strdup(finalMessage.c_str()));
      break;
    case SensorLoggerLevel::fault:
      LOG_ERR("%s",log_strdup(finalMessage.c_str()));
      break;
    default:
      LOG_INF("%s",log_strdup(finalMessage.c_str()));
      break;
  }
}

}
}