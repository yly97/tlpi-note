// 6-2
// 不太理解这里运行为什么没有报错，讲道理按书上说的，跳到了一个已经返回的函数是有问题的。
// 这里调用bar函数时应该已经覆盖了foo函数的栈帧，longjmp竟然还能恢复到一个不存在的栈帧，
// 很奇怪！算了，这个函数貌似基本用不到。。

#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include "tlpi_hdr.h"

static jmp_buf env; // 保存当前环境的信息

void 
foo() {
    if (setjmp(env) == 0) {
        printf("setjmp()\n");
    } else {
        printf("longjmp()\n");
    }
}

void
bar() {
    longjmp(env, 1);
}

int
main() {
    foo();
    printf("==========\n");
    bar();

    exit(EXIT_SUCCESS);
}