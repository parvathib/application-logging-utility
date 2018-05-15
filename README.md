# application-logging-utility
Sample logger test application and logger utility to log application 
events to a user specified log file with a configurable log level. 

files:
========
logger.c - Implements Logger utility functions.
logger.h - Exploses the logger utility APIs which can be used by the application.
logger_test.c - Test application to test different log level events from the 
                application. It takes the log file and the log level from the 
                command line and initializes the logger. 
tests.sh - shell script that invokes the logger test with different command line
            options.

test procedure:
===============
Download the logger.tar, and from the directory where logger.tar is placed,
perform the following steps from the command shell prompt:
$ tar -xvf logger.tar
$ cd logger.tar
$ make
$ ./tests.sh

Results:
========
Test1 and  Test 2 do not create any files and the application should exit
with appropriate message. 
Test3, 4, and 5 will generate log files with different log level messages 
(refer to the tests.sh scripts for more information).


