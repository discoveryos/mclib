#ifndef SYSCALL_ARCH_H
#define SYSCALL_ARCH_H

/* Inline functions for 0-6 syscall arguments, following x86_64 ABI */
static inline long __syscall0(long n) { /* ... */ }
static inline long __syscall1(long n, long a1) { /* ... */ }
static inline long __syscall2(long n, long a1, long a2) { /* ... */ }
static inline long __syscall3(long n, long a1, long a2, long a3) { /* ... */ }
static inline long __syscall4(long n, long a1, long a2, long a3, long a4) { /* ... */ }
static inline long __syscall5(long n, long a1, long a2, long a3, long a4, long a5) { /* ... */ }
static inline long __syscall6(long n, long a1, long a2, long a3, long a4, long a5, long a6) { /* ... */ }

/* Macro magic to count arguments and call the correct __syscallN function */
#define __SYSCALL_NARG_(_0,_1,_2,_3,_4,_5,_6,N,...) N
#define __SYSCALL_NARG(...) __SYSCALL_NARG_(__VA_ARGS__,6,5,4,3,2,1,0)
#define __SYSCALL_CONCAT_X(a,b) a##b
#define __SYSCALL_CONCAT(a,b) __SYSCALL_CONCAT_X(a,b)
#define __SYSCALL_DISP(b,...) __SYSCALL_CONCAT(b,__SYSCALL_NARG(__VA_ARGS__))(__VA_ARGS__)

#define syscall(...) __SYSCALL_DISP(__syscall,__VA_ARGS__)

#endif
