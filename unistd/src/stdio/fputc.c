#include <stdio.h>
#include "../../arch/x86_64/syscall_arch.h"

int fflush(FILE *f) {
    if (f->pos > 0) {
        // SYS_write = 1
        __syscall3(1, f->fd, (long)f->buf, f->pos);
        f->pos = 0;
    }
    return 0;
}

int fputc(int c, FILE *f) {
    if (f->pos >= f->buf_size) {
        fflush(f);
    }
    f->buf[f->pos++] = (char)c;
    
    // Line buffering: automatically flush if we see a newline
    if (c == '\n') fflush(f);
    
    return c;
}
