#include <signal.h>
#include "../../arch/x86_64/syscall_arch.h"

#define SYS_rt_sigaction 13

/* Simplified signal implementation */
sighandler_t signal(int signum, sighandler_t handler) {
    /* In a real libc, you'd use a struct sigaction here */
    /* This is a high-level wrapper for the rt_sigaction syscall */
    // __syscall4(SYS_rt_sigaction, signum, (long)act, (long)oldact, 8);
    return handler; 
}
