/**
 * @file logger.h
 * @brief: application event logger utility.
 *
 * Application starts off by initializing the logger by calling logger_open() 
 * with the path of the log file and the debug level. If the log file is not
 * specified, the logs are written to stdout. If the log file open fails, 
 * logger_open() returns with error.
 * It then logs events using print_log() with the desired log level.
 * While exiting, the application closes the logger by calling logger_close().
 *
 * @author Parvathi Bhogaraju (vbhogara@andrew.cmu.edu).
 */
#ifndef LOGGER_H
#define LOGGER_H

#include <stdlib.h>
#include <string.h>

/**
 * Log levels
 */
enum {
    ERROR = 0,
    INFO,      /* 1 */
    DEBUG      /* 2 */
};

/*** logger utility APIs for application ***/
/**
 * @brief  Application initializes the logger by calling this function
 * @param level  Log level configured by the application
 * @param filepath Path of the log file
 * @param aname Application name
 * @return 0 on success and -1 if file can't be opened. 
 */
int logger_open(int level, char *filepath);
/**
 * @brief  Application closes the logger by calling this function
 * @return 0 on success and -1 if file can't be closed. 
 */
int logger_close();
/**
 * @brief  Printf the application events in the log file as per the configured
 * debug level.
 * @param level Log level of the event to be logged.
 * @param fmt format specifier, followed by variable length arguments.
 * @return number of characters printed.
 */
int print_log(int level, char *fmt, ...);

#endif /* LOGGER_H */


