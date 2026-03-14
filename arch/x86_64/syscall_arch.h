#ifndef SYSCALL_ARCH_H
#define SYSCALL_ARCH_H

// Core inline assembly for x86_64 syscalls (0-6 arguments)
static __inline long __syscall0(long n) {
	unsigned long ret;
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n) : "rcx", "r11", "memory");
	return ret;
}
// ... (Implementation for __syscall1 through __syscall6 omitted for brevity)
#endif
