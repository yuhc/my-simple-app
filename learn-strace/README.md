STRACE
===============================================================================

`strace` is a command which lets you trace system calls and signals
received by a process (and its children). A simple HelloWorld C program
is written in `trace_me.c`. The program simply prints a line of `hello
world` on the screen.

We can trace the system calls that trace_me makes by:
```
strace -s 2000 -f ./trace_me
```

`-s` flag specifies the maximum string size that `strace` will print.
Passing a large enough value can make sure to display the whole
parameters of functions, etc. `-f` means to trace the children too. The
terminal then returns a lot of things:
```
execve("./trace_me", ["./trace_me"], [/* 59 vars */]) = 0
brk(0)                                  = 0x197d000
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or
directory)
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0)
= 0x7fdb640f5000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or
directory)
open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=212104, ...}) = 0
mmap(NULL, 212104, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7fdb640c1000
close(3)                                = 0
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or
directory)
open("/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3,
"\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\320\37\2\0\0\0\0\0@\0\0\0\0\0\0\0
\6\34\0\0\0\0\0\0\0\0\0@\0008\0\n\0@\0D\0C\0\6\0\0\0\5\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0000\2\0\0\0\0\0\0000\2\0\0\0\0\0\0\10\0\0\0\0\0\0\0\3\0\0\0\4\0\0\0000\177\30\0\0\0\0\0000\177\30\0\0\0\0\0000\177\30\0\0\0\0\0\34\0\0\0\0\0\0\0\34\0\0\0\0\0\0\0\20\0\0\0\0\0\0\0\1\0\0\0\5\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\24\240\33\0\0\0\0\0\24\240\33\0\0\0\0\0\0\0
\0\0\0\0\0\1\0\0\0\6\0\0\0@\247\33\0\0\0\0\0@\247;\0\0\0\0\0@\247;\0\0\0\0\0`Q\0\0\0\0\0\0\200\233\0\0\0\0\0\0\0\0
\0\0\0\0\0\2\0\0\0\6\0\0\0\240\333\33\0\0\0\0\0\240\333;\0\0\0\0\0\240\333;\0\0\0\0\0\340\1\0\0\0\0\0\0\340\1\0\0\0\0\0\0\10\0\0\0\0\0\0\0\4\0\0\0\4\0\0\0p\2\0\0\0\0\0\0p\2\0\0\0\0\0\0p\2\0\0\0\0\0\0D\0\0\0\0\0\0\0D\0\0\0\0\0\0\0\4\0\0\0\0\0\0\0\7\0\0\0\4\0\0\0@\247\33\0\0\0\0\0@\247;\0\0\0\0\0@\247;\0\0\0\0\0\20\0\0\0\0\0\0\0\260\0\0\0\0\0\0\0\20\0\0\0\0\0\0\0P\345td\4\0\0\0L\177\30\0\0\0\0\0L\177\30\0\0\0\0\0L\177\30\0\0\0\0\0\4g\0\0\0\0\0\0\4g\0\0\0\0\0\0\4\0\0\0\0\0\0\0Q\345td\6\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\20\0\0\0\0\0\0\0R\345td\4\0\0\0@\247\33\0\0\0\0\0@\247;\0\0\0\0\0@\247;\0\0\0\0\0\3008\0\0\0\0\0\0\3008\0\0\0\0\0\0\1\0\0\0\0\0\0\0\4\0\0\0\24\0\0\0\3\0\0\0GNU\0000\311M\306j\37\351Q\200\303\326\215+\211\345v\325\256!<\4\0\0\0\20\0\0\0\1\0\0\0GNU\0\0\0\0\0\2\0\0\0\6\0\0\0\30\0\0\0\0\0\0\0\363\3\0\0\n\0\0\0\0\1\0\0\16\0\0\0\0000\20D\240
\2\1\210\3\346\220\305E\214\0\300\0\10\0\5\200\0`\300\200\0\r\212\f\0\4\20\0\210D2\10.@\210P4,
\16\"H&\204\300\214\4\10\0\2\2\16\241\254\32\4f\300\0\3002\0\300\0P\1
\201\10\204\v  ($\0\4 P\0\20X\200\312DB(\0\6\200\20\30B\0
@\200\0\tP\0Q\212@\20\0\0\0\0\10\0\0\21\20", 832) = 832
fstat(3, {st_mode=S_IFREG|0755, st_size=1840928, ...}) = 0
mmap(NULL, 3949248, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3,
0) = 0x7fdb63b10000
mprotect(0x7fdb63ccb000, 2093056, PROT_NONE) = 0
mmap(0x7fdb63eca000, 24576, PROT_READ|PROT_WRITE,
MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1ba000) = 0x7fdb63eca000
mmap(0x7fdb63ed0000, 17088, PROT_READ|PROT_WRITE,
MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7fdb63ed0000
close(3)                                = 0
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0)
= 0x7fdb640c0000
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0)
= 0x7fdb640be000
arch_prctl(ARCH_SET_FS, 0x7fdb640be740) = 0
mprotect(0x7fdb63eca000, 16384, PROT_READ) = 0
mprotect(0x600000, 4096, PROT_READ)     = 0
mprotect(0x7fdb640f7000, 4096, PROT_READ) = 0
munmap(0x7fdb640c1000, 212104)          = 0
fstat(1, {st_mode=S_IFCHR|0620, st_rdev=makedev(136, 25), ...}) = 0
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0)
= 0x7fdb640f4000
write(1, "hello world\n", 12hello world
)           = 12
exit_group(12)                          = ?
+++ exited with 12 +++
```

We can have a quick brief look at the output log.
* `execve("./trace_me", ["./trace_me"], ...)` is called. It accepts the
arguments, environment variables to set up the program.
* Then it tries to map the useful files into the memory using `mmap(2)`.
* Then the standard C libraries are connected (see
  `open("/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC)`) and read. More
  contents of files are mapped into the memory.
* Finally the program starts with `write(1, "hello world\n", 12)`.
  `1` is the file descriptor to write to, which is standard output stream here.
  The `hello world` after `"hello world\n", 12` is the output of the program.
* All threads and the process exit by `exit_group()`.

Besides, if we want to trace a running process, we can use
```
sudo strace -o /tmp/strace.out -s 2000 -fp 1234
```

`1234` is the PID of the process we want to trace. More generally, we can use
```
sudo strace -o /tmp/strace.out -s 2000 -fp `pgrep PROCESS_NAME`
```
