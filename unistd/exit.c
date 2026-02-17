#include <unistd.h>
#include "../syscall/syscall.h"


void exit(int status) {
     asm volatile (
      "syscall"
      :
      : "a"(SYS_exit), "D"(status)
      : "rcx" , "r11" , "memory"
   );
   __builtin_unreachable();
}
