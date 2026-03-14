#include <stdio.h>

int fputs(const char *s, FILE *f) {
    while (*s) {
        fputc(*s++, f);
    }
    return 0;
}

int puts(const char *s) {
    fputs(s, stdout);
    fputc('\n', stdout);
    return 0;
}
