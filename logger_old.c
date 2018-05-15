#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "logger.h"

char *logfile = "log.txt";

void print_log(int level, char *fmt, ...)
{
    int print = 0;
    char *s;

    switch(level) {
        case ERROR:
            if (LOG_LEVEL <= level) {
                print = 1;
                printf("error: ");
            }
            break;
        case DEBUG:
            if (LOG_LEVEL <= level) {
                print = 1;
                printf("debug: ");
            }
            break;
        case INFO:
            if (LOG_LEVEL <= level) {
                print = 1;
                printf("info: ");
            }
            break;
        default:
            break;
    }
    if(print) {
        va_list vl;
        va_start(vl, fmt);
        for(s = fmt; *s != '\0'; s++) {
            if ( *s != '%') {
                putchar(*s);
                continue;
            }
            char fstr[10] = {0};
            //char format = *++s;
            int i = 1;
            fstr[0] = '%';
            ++s;
            while(((*s >= 'a') && (*s <= 'z')) || ((*s >= 'A') && (*s <= 'Z'))) {
                //printf("*s %c ", *s);
                fstr[i++] = *s;
                ++s;
            }
            fstr[i] = '\0';
            char format = fstr[i - 1];
            int invalid = 0;
            //printf("format %c fstr %s\n", format, fstr);
            /* single Character */
            switch(format) {
                case 'c': 
                    printf(fstr, va_arg(vl, int));
                    break;
                case 'i':
                case 'd':
                    printf(fstr, va_arg(vl, int)); 
                    break;
                case 'o':
                    printf(fstr, va_arg(vl, int));
                    break;
                case 'u':
                    printf(fstr, va_arg(vl, unsigned int));
                    break;
                case 'x':
                case 'X':
                    printf(fstr, va_arg(vl, long long unsigned int));
                    break;
                case 'f':
                    printf(fstr, va_arg(vl, double));
                    break;
                case 'e':
                case 'E':
                case 'g':
                case 'G':
                    printf("%e", va_arg(vl, double));
                    break;
                case 's':
                    printf("%s", va_arg(vl, char *));
                    break;
                case 'p':
                    printf("%p", va_arg(vl, void *));
                    break;
                default:
                    invalid = 1;
                    break;
            }
            if(invalid) {
                printf("%s", fstr);
            } else {
                putchar(*s);
            }
        }
        /* clean up at the end */
        va_end(vl); 
    }
}
