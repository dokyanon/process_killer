process_killer
==============

Process Killer plugin for samp (linux)

Compile manual:

1) cd folder
2) make
3) copy process_killer.so from plugins folder in samp server.

NEED CLANG!! OR SEE MANUAL FOR COMPILE IN GCC

If u want compile from gcc:
1) open makefile
2) edit COMPILER = clang on COMPILER = gcc
3) use make from konsole

Usable manual:
1) download process_killer.so
2) copy process_killer.so from pugins folder in samp server
3) open u pwn file or create new include file
4) write native process_kill (procname[]);
5) use process_kill (procname);
