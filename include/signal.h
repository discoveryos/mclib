#ifndef _SIGNAL_H
#define _SIGNAL_H

#define SIGHUP    1
#define SIGINT    2
#define SIGQUIT   3
#define SIGILL    4
#define SIGTRAP   5
#define SIGABRT   6
#define SIGFPE    8
#define SIGKILL   9
#define SIGSEGV   11
#define SIGTERM   15

typedef void (*sighandler_t)(int);

sighandler_t signal(int signum, sighandler_t handler);

#endif
