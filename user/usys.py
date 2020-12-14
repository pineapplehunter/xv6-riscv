#!/usr/bin/python3

# Generate usys.S, the stubs for syscalls.

print("# generated by usys.pl - do not edit\n")

print('#include "kernel/syscall.h"\n')


def entry(name):
    print(
        f".global {name}\n"
        f"{name}:\n"
        f"    li a7, SYS_{name}\n"
        f"    ecall\n"
        f"    ret\n"
    )


entry("fork")
entry("exit")
entry("wait")
entry("pipe")
entry("read")
entry("write")
entry("close")
entry("kill")
entry("exec")
entry("open")
entry("mknod")
entry("unlink")
entry("fstat")
entry("link")
entry("mkdir")
entry("chdir")
entry("dup")
entry("getpid")
entry("sbrk")
entry("sleep")
entry("uptime")
entry("custom_print")
entry("custom_print_int")
entry("custom_print_pid")
entry("custom_print_str")
