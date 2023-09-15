// 5-3

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "tlpi_hdr.h"

int
main (int argc, char *argv[]) {
    int fd;
    off_t off;
    Boolean is_atomic = FALSE;

    if (argc != 3 && argc != 4 || (argc == 4 && strcmp(argv[3], "x") != 0)) {
        usageErr("%s filename num-bytes [x]\n", argv[0]);
    }

    ssize_t num_bytes = atol(argv[2]);
    int open_flags = O_WRONLY | O_CREAT;
    if (argc == 3) {
        is_atomic = TRUE;
        open_flags |= O_APPEND;
    }

    mode_t open_mode = S_IRUSR | S_IWUSR;
    fd = open(argv[1], open_flags, open_mode);
    if (fd == -1) {
        errExit("open");
    }

    if (is_atomic) {
        while (num_bytes--) {
            if (write(fd, "a", 1) == -1) {
                errExit("write");
            }
        }
    } else {
        while (num_bytes--) {
            if (off = lseek(fd, 0, SEEK_END) == -1) {
                errExit("lseek");
            }

            if (write(fd, "a", 1) == -1) {
                errExit("write");
            }
        }
    }

    if (close(fd) == -1) {
        errExit("close fd");
    }
    exit(EXIT_SUCCESS);
}