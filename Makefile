#
## Makefile for logger test
# 
# # Type "make" to build test application
# #
CC = /usr/bin/gcc
CFLAGS = -Wall -g -Werror
LIBS = -lpthread

FILES = logger_test
all: $(FILES)

logger_test: logger_test.c logger.c
	$(CC) $(CFLAGS) -o logger_test logger_test.c logger.c $(LIBS)

# Clean up
clean:
	rm -f $(FILES) *.o *~
