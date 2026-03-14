#include <stdio.h>

static char stdout_buf[1024];
static FILE _stdout = {
    .fd = 1,
    .buf = stdout_buf,
    .buf_size = 1024,
    .pos = 0
};

FILE *stdout = &_stdout;
