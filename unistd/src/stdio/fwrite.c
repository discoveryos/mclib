#include <stdio.h>

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *f) {
    const unsigned char *s = ptr;
    size_t total = size * nmemb;
    for (size_t i = 0; i < total; i++) {
        if (fputc(s[i], f) == -1) return i / size;
    }
    return nmemb;
}
