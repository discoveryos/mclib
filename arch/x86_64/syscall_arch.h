#ifndef SYSCALL_ARCH_H
#define SYSCALL_ARCH_H

#define __SYSCALL_LL_E(x) (x)
#define __SYSCALL_LL_O(x) (x)

// Inline functions for syscalls (0-6 arguments) using 'syscall' instruction
// See musl implementation for full asm details
static inline long __syscall0(long n) { /* ... */ }
static inline long __syscall1(long n, long a1) { /* ... */ }
// ... (implementations for 2-6 arguments)
#endif
