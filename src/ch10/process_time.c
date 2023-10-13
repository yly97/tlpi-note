#include <sys/times.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

// clock_t times(struct tms *buf)进程运行到调用该函数时的用户时间和内核时间
// clock_t clock()进程运行到调用该函数时的总运行时间
// 两个函数返回值的时间单位不同，times返回的是时钟计时单元（clock tick），
// 通过sysconf(_SC_CLK_TCK)获得每秒clock tick数，要获取实际秒数要除以该值，
// clock返回的要除以CLOCKS_PER_SEC，该值不是编译期常量


int main() {
    long cnt = sysconf(_SC_CLK_TCK);
    printf("%ld\n", cnt);
    
    struct tms buf;
    printf("%ld", times(&buf) / cnt);
}