#include <stdio.h>
#include <string.h>
#include "../../arch/x86_64/syscall_arch.h"

#define SYS_read 0

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *f) {
    size_t total_to_read = size * nmemb;
    size_t bytes_read = 0;
    unsigned char *dest = (unsigned char *)ptr;

    while (bytes_read < total_to_read) {
        // If buffer is empty, refill it
        if (f->pos >= f->end) {
            long n = __syscall3(SYS_read, f->fd, (long)f->buf, f->buf_size);
            if (n <= 0) break; // EOF or Error
            f->pos = 0;
            f->end = (size_t)n;
        }

        // Copy from buffer to destination
        size_t available = f->end - f->pos;
        size_t chunk = (total_to_read - bytes_read < available) ? 
                        (total_to_read - bytes_read) : available;
        
        memcpy(dest + bytes_read, f->buf + f->pos, chunk);
        f->pos += chunk;
        bytes_read += chunk;
    }

    return bytes_read / size;
}
