CFLAGS = -g -finstrument-functions

SRCS=$(wildcard *.c)

main: $(SRCS)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -rf *.o main

test:
	size main
	objdump -D main > a.txt