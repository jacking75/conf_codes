#pragma once

#include <boost/log/expressions.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup.hpp>

#define INFO  BOOST_LOG_SEV(my_logger::get(), boost::log::trivial::info)
#define WARN  BOOST_LOG_SEV(my_logger::get(), boost::log::trivial::warning)
#define ERROR BOOST_LOG_SEV(my_logger::get(), boost::log::trivial::error)

#define SYS_LOGFILE             "/var/log/example.log"

//Narrow-char thread-safe logger.
typedef boost::log::sources::severity_logger_mt<boost::log::trivial::severity_level> logger_t;

//declares a global logger with a custom initialization
BOOST_LOG_GLOBAL_LOGGER(my_logger, logger_t)