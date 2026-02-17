CC = gcc
AS = as
AR = ar

CFLAGS = -ffreestanding -fno-builtin -nostdlib -nostartfiles -Iinclude

OBJS = \
	crt/crt0.o \
	unistd/write.o \
	unistd/read.o \
	unistd/exit.o

libmclib.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)

crt/crt0.o: crt/crt0.s
	$(AS) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) libmclib.a
