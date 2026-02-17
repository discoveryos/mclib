#ifndef MC_UNISTD_H
#define MC_UNISTD_H


typedef unsigned long size_t;
typedef long ssize_t;


size_t read(int fd, void *buf, size_t count);
size_t write(int fd, const void *buf, size_t count);
void exit(int status);


#endif
