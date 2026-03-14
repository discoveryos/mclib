#include <stdio.h>
#include <stdlib.h>
#include "../../arch/x86_64/syscall_arch.h"

#define SYS_close 3

int fclose(FILE *f) {
    if (!f) return -1;
    __syscall1(SYS_close, f->fd);
    free(f->buf);
    free(f);
    return 0;
}
