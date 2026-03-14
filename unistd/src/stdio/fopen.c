#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../arch/x86_64/syscall_arch.h"

#define SYS_open 2

FILE *fopen(const char *filename, const char *mode) {
    int flags = O_RDONLY;
    if (mode[0] == 'w') flags = O_WRONLY; // Simple mode check
    
    // Linux open syscall: open(filename, flags, mode)
    int fd = (int)__syscall3(SYS_open, (long)filename, flags, 0666);
    if (fd < 0) return NULL;

    // Allocate FILE struct + buffer (musl style)
    size_t buf_size = 1024;
    FILE *f = malloc(sizeof(FILE));
    if (!f) {
        __syscall1(3, fd); // Close FD on failure (SYS_close = 3)
        return NULL;
    }

    f->fd = fd;
    f->buf = malloc(buf_size);
    f->buf_size = buf_size;
    f->pos = 0;
    f->end = 0;

    return f;
}
