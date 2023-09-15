// 5-2

// 以O_APPEND标志打的的文件，文件末尾的下一个字符的偏移量就是0,
// 即调用了lseek(fd, 0, SEEK_SET)将偏移置量0也没用，还是从文件尾加入数据。
// 很神奇，和自己认为的不太一样，这样设计也有它的好处，没法覆盖之前的数据。

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "tlpi_hdr.h"

int
main (int argc, char *argv[]) {
    int fd;
    off_t off;
    if (argc != 2 || strcmp(argv[1], "--help") == 0) {
        usageErr("%s pathname\n", argv[0]);
    }

    fd = open(argv[1], O_WRONLY | O_APPEND);
    if (fd == -1) {
        errExit("open");
    }

    if (off = lseek(fd, 0, SEEK_SET) == -1) {
        errExit("lseek");
    }
    
    if (write(fd, "test", 4) == -1) {
        errExit("write");
    }

    if (close(fd) == -1) {
        errExit("close fd");
    }
    exit(EXIT_SUCCESS);
}