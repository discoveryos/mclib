.global _start
.extern main 


_start:
     
     call main          # int main()
     mov %eax, %edi     # exit code 
     mov $60, %eax      # sys_exit
     syscall
