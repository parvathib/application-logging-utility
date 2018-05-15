/**
 * @file logger.c
 * @brief: Implements application event logger utility functions.
 *
 * @author Parvathi Bhogaraju (vbhogara@andrew.cmu.edu).
 */
#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include "logger.h"

/** Global Variables **/
/**
 * log level specified by the application 
 */
int app_log_level;
/**
 * log file stream opened at the time of logger_open()
 */
FILE *log_file;
/**
 * indicates that the logger is initialized successfully
 */
int log_init = 0;

/**
 * @brief  Application initializes the logger by calling this function
 * @param level  Log level configured by the application
 * @param filepath Path of the log file
 * @return 0 on success and -1 if file can't be opened. 
 */
int logger_open(int level, char *filepath)
{
    if((level < ERROR) || (level > DEBUG)) {
        errno = -EINVAL;
        perror("Undefined log level");
        return -1;
    }
    app_log_level = level;
    if(filepath == NULL) {
        log_file = stdout;
    } else {
        /**
         * Log file is truncated everytime the application restarts 
         */
        log_file = fopen(filepath, "w+");
        if(!log_file) {
            perror("log_file open");
            return -1;
        }
    }
    log_init = 1;
    return 0;
}

/**
 * @brief  Application closes the logger by calling this function
 * @return 0 on success and -1 if file can't be closed. 
 */
int logger_close() 
{
    if(log_init) {
        if(fclose(log_file) < 0) {
            perror("log_file close");
            return -1;
        }
    }
    return 0;
}

/**
 * @brief  Printf the application events in the log file as per the configured
 * debug level.
 * @param level Log level of the event to be logged.
 * @param fmt format specifier, followed by variable length arguments.
 * @return number of characters printed.
 */
int print_log(int level, char *fmt, ...)
{
    int print = 0;
    int ret = 0;
    if(log_init) {
        switch(level) {
            case ERROR:
                if (app_log_level >= level) {
                    print = 1;
                    ret = fprintf(log_file, "%s error: ", __TIME__);
                }
                break;
            case DEBUG:
                if (app_log_level >= level) {
                    print = 1;
                    ret = fprintf(log_file, "%s debug: ", __TIME__);
                }
                break;
            case INFO:
                if (app_log_level >= level) {
                    print = 1;
                    ret = fprintf(log_file, "%s info: ", __TIME__);
                }
                break;
            default:
                break;
        }
        if(print) {
            va_list vl;
            va_start(vl, fmt);
            ret += vfprintf(log_file, fmt, vl);
            va_end(vl);
        }
    }
    return ret;
}
