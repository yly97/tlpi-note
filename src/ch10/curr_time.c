#include <time.h>
#include "curr_time.h"

#define BUF_SIZE 1024

char *currTime(const char *format) {
    static char buf[BUF_SIZE];
    time_t t= time(NULL);
    struct tm *tm = localtime(&t);
    if (tm == NULL) return NULL;
    size_t s = strftime(buf, BUF_SIZE, (format != NULL) ? format : "%c", tm);
    return s == 0 ? NULL : buf;
}