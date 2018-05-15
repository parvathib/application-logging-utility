#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "logger.h"

void usage(void)
{
    printf("Usage: logger_test [-h] [-f filename] [-d log level] \n");
    printf("   -h   print this message\n");
    printf("   -f   log file name\n");
    printf("   -d   log level\n");
    exit(0);
}

int main(int argc, char *argv[])
{
    char c;
    char *fname = NULL;
    int log_level = 0;
    while ((c = getopt(argc, argv, "hf:d:")) != EOF) {
        switch(c) {
            case 'h':
                usage();
                break;
            case 'f':
                fname = strdup(optarg);
                break;
            case 'd':
                log_level = atoi(optarg);
                break;
            default:
                usage();
        }
    }
    if(logger_open(log_level, fname) < 0) {
        perror("logger_open");
        exit(-1);
    }

    
    print_log(DEBUG, "Hello World!\n");
     
    print_log(INFO, "char %c, int %d long %lld\n", 'd', 3, (long long)3000);
    
    print_log(ERROR, "double %e float %f\n", 3.0, 3.0);
    
    char *str = "This is error message";
    print_log(ERROR, "<<%-20.20s>>\n", str);
    
    unsigned int i = 0;
    while(i < 10) {
        print_log(INFO, "Unsigned int %u Hexadecimal %x \n", i, INT_MAX - i);
        i++;
    }
    
    i = 0;
    while(i < 10) {
        print_log(DEBUG, "Octal notation %o  Pointer %p\n", i, str + i);
        i++;
    }
    
    i = 0;
    while(i < 10) {
        print_log(ERROR, "Float %.2f Integer with width  %*f \n", 0.01234, 2, 1.99999);
        i++;
    }

    logger_close();
    return 0;
}

