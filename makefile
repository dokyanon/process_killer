COMPILER = clang
OUTFILE = "process_killer.so"
COMPILE_FLAGS = -c -m32 -O3 -fPIC -w -DLINUX -Wall -I./SDK/amx/

all:
	$(COMPILER) $(COMPILE_FLAGS) ./SDK/*.c
	$(COMPILER) $(COMPILE_FLAGS) main.c
	$(COMPILER) -m32 -O3 -fshort-wchar -shared -o $(OUTFILE) *.o -pthread
	rm -f *.o