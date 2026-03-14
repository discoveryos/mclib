#ifndef _STDIO_H
#define _STDIO_H

#include <stddef.h>

typedef struct _IO_FILE {
    int fd;             // The Linux File Descriptor
    char *buf;          // Pointer to the start of the buffer
    size_t buf_size;    // Total size of the buffer
    size_t pos;         // Current position in the buffer
} FILE;

extern FILE *stdout;
extern FILE *stderr;
extern FILE *stdin;

int fputc(int c, FILE *f);
int fputs(const char *s, FILE *f);
int fflush(FILE *f);

#endif
