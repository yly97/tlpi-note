// 4-1
#include <stdio.h>
#include <getopt.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "tlpi_hdr.h"

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

#define printable(ch) (isprint((unsigned char) ch) ? ch : '#')

static void
usageError(char *prog_name, char *msg, int opt) {
    if (msg != NULL && opt != 0) {
        fprintf(stderr, "%s (-%c)\n", msg, printable(opt));
    }
    fprintf(stderr, "Usage: %s [-a]\n", prog_name);
    exit(EXIT_FAILURE);
}

int 
main(int argc, char *argv[]) {
    char buf[BUF_SIZE];
    int output_fd;
    int opt;
    Boolean is_append = FALSE;

    // 处理命令选项
    while ((opt = getopt(argc, argv, ":ah")) != -1) {
        if (opt == 'h') {
            usageErr(" %s [-a]\n", argv[0]);
        }

        switch (opt)
        {
        case 'a':
            is_append = TRUE;
            break;
        case ':':
            usageError(argv[0], "Missing argument", optopt);
        case '?':
            usageError(argv[0], "Unrecognized option", optopt);
        default:
            fatal("Unexpected case int switch()");
        }
    }

    if (optind + 1 != argc) {
        usageErr(" %s [-a]\n", argv[0]);
    }

    int open_flags = O_WRONLY | O_CREAT;
    if (is_append) {
        open_flags |= O_APPEND;
    } else {
        open_flags |= O_TRUNC;
    }
    mode_t file_mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
                S_IROTH | S_IWOTH;
    output_fd = open(argv[optind], open_flags, file_mode);

    // 从标准输入中读取数据，写入标注输出和文件中
    ssize_t num_read;
    while ((num_read = read(STDIN_FILENO, buf, BUF_SIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, num_read) != num_read) {
            fatal("write() returned error or partial write occurred");
        }
        if (write(output_fd, buf, num_read) != num_read) {
            fatal("write() returned error or partial write occurred");
        }
    }
    if (num_read == -1) {
        errExit("read");
    }
    
    if (close(output_fd) == -1) {
        errExit("close output");
    }

    exit(EXIT_SUCCESS);
}