#include <stdio.h>
#include <errno.h>
#include "../../arch/x86_64/syscall_arch.h"

#define SYS_lseek 8

int fseek(FILE *f, long offset, int whence) {
    // If seeking relatively, we must account for our internal buffer position
    if (whence == SEEK_CUR) {
        offset -= (f->end - f->pos);
    }

    // Trigger the Linux lseek syscall
    long result = __syscall3(SYS_lseek, f->fd, offset, whence);
    
    if (result < 0) {
        return -1;
    }

    // Success: Discard the current buffer so the next read is fresh
    f->pos = 0;
    f->end = 0;
    
    return 0;
}
