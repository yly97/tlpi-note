// 6-3
// 需要注意的应该是getenv和putenv函数，getenv的返回的字符串和传入putenv的字符串都不能随便修改，
// 它们会直接影响到environ环境列表中的值。

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024
extern char **environ;

// 返回-1的情况还未知。。
int mySetenv(const char *name, const char *value, int overwrite) {
    char *value_ = getenv(name);
    if (overwrite == 0 && value_ != NULL) {
        return 0;
    }

    char buf[BUF_SIZE];
    int i = 0;

    for (const char *it = name; *it != '\0'; ++it) {
        buf[i++] = *it; 
    }
    buf[i++] = '=';
    for (const char *it = value; *it != '\0'; ++it) {
        buf[i++] = *it; 
    }
    buf[i] = '\0';

    putenv(buf);    // 调用putenv函数后，对buf的修改会直接修改环境列表
                    // 因为putenv函数直接把environ中的一个指针直接指向buf
    return 0;
}

// 返回-1的情况还位置。。
int myUnsetenv(const char *name) {
    char *value_ = getenv(name);
    if (value_ == NULL) return 0;

    char **last = environ;
    while (*(last + 1)) ++last; // last指向最后一个环境变量

    char **it = environ;
    size_t len_name = strlen(name);
    while (*it) {
        if (strncmp(name, *it, len_name) == 0) {
            *it = *last;
            *last = NULL;
            --last;
            continue;
        }
        ++it;
    }
    return 0;
}

int main() {
    // for (char **ep = environ; *ep != NULL; ++ep) {
    //     printf("%s\n", *ep);
    // }

    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    char *value_ = getenv("SHELL");
    if (value_) puts(value_);

    printf("========================================================\n");
    mySetenv("SHELL", "XXXX", 1);
    
    value_ = getenv("SHELL");   // glibc中的getenv返回的不是静态缓冲区，
                                // 需要再次调用获取修改后的值
    if (value_) puts(value_);

    printf("========================================================\n");
    myUnsetenv("SHELL");

    value_ = getenv("SHELL");
    if (value_) puts(value_);
    else printf("SHELL is undefined\n");

    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    // myUnsetenv("LS_COLORS");
    // myUnsetenv("PATH");
    for (char **ep = environ; *ep != NULL; ++ep) {
        printf("%s\n", *ep);
    }

    exit(EXIT_SUCCESS);
}