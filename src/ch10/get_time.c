#include <sys/time.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
    time_t t = time(NULL);
    printf("%s", ctime(&t));

    // 获取的是格林威治标准时间
    struct tm *ft = gmtime(&t);  
    char *st = asctime(ft);
    printf("%s", st);

    // 会考虑时区和夏令时
    struct tm *ft2 = localtime(&t);
    char *st2 = asctime(ft2);
    printf("%s", st2);
}

// ctime和asctime都无法控制输出时间的格式
// ctime会考虑会对时间做本地化处理
// gettimeofday时间精确到微秒，必time_t精度高