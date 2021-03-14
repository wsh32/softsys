CFLAGS = -Wall -Werror
OBJS_LIST = trout.o util.o

all: trout test

clean:
	rm trout test $(OBJS_LIST)

trout: main.c trout.o util.o
	gcc $(CFLAGS) -o trout main.c trout.c util.c

test: util.c test_util.c
	gcc -o test test_util.c util.c

%.o: %.c
	gcc -c -g $(CFLAGS) $< -o $@

.PHONY: all clean

