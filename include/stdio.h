#ifndef _STDIO_H
#define _STDIO_H

#include <stddef.h>
#include <stdarg.h>

/* File Seek Constants */
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

/* Standard File Descriptors */
#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

/* The FILE Structure - Buffered I/O */
typedef struct _IO_FILE {
    int fd;
    unsigned char *buf;
    size_t buf_size;
    size_t pos;
    size_t end;
    int flags;
} FILE;

/* Standard Streams */
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

/* Function Prototypes */

/* Character & String I/O */
int fputc(int c, FILE *f);
int fputs(const char *s, FILE *f);
int puts(const char *s);
int fgetc(FILE *f);

/* Formatted I/O */
int printf(const char *fmt, ...);
int fprintf(FILE *f, const char *fmt, ...);
int vfprintf(FILE *f, const char *fmt, va_list ap);
int sprintf(char *s, const char *fmt, ...);

/* File Management */
FILE *fopen(const char *filename, const char *mode);
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *f);
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *f);
int fseek(FILE *f, long offset, int whence);
long ftell(FILE *f);
int fflush(FILE *f);
int fclose(FILE *f);

#endif
