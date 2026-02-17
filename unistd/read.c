#include <unistd.h>
#include "../syscall/syscall.h"


size_t read(int fd, void *buf, size_t count) {
    long ret;
    asm volatile (
      "syscall"
      : "=a"(ret)
      : "a"(SYS_read), "D"(fd), "S"(buf), "d"(count)
      : "rcx" , "r11" , "memory"
    );
    return ret;
}

