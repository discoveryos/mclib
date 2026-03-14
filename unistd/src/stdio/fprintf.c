#include <stdio.h>
#include <stdarg.h>

int fprintf(FILE *f, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int result = vfprintf(f, fmt, ap);
    va_end(ap);
    return result;
}

int vfprintf(FILE *f, const char *fmt, va_list ap) {
    char buf[64]; // Buffer for number conversions
    int count = 0;

    for (const char *p = fmt; *p; p++) {
        if (*p != '%') {
            fputc(*p, f);
            count++;
            continue;
        }

        p++; // Skip '%'
        switch (*p) {
            case 'd': {
                extern char *itoa(long val, char *s, int radix);
                itoa(va_arg(ap, int), buf, 10);
                fputs(buf, f);
                break;
            }
            case 's': {
                char *s = va_arg(ap, char *);
                fputs(s, f);
                break;
            }
            default:
                fputc(*p, f);
        }
    }
    return count;
}
