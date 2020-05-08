CC=gcc
CFLAGS=-g -Wall `pkg-config --cflags glib-2.0`
LDFLAGS=`pkg-config --libs glib-2.0`

OBJS=frequency_analysis.o

.PHONY: all
all: word_count ex_compile

.PHONY: clean
clean:
	rm word_count ex_compile *.o

ex_compile: ex_compile.c
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $^

word_count: word_count.c $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $^

frequency_analysis.o: frequency_analysis.c
	$(CC) -c -o $@ $(CFLAGS) $(LDFLAGS) $^

caesar.txt:
	wget http://www.gutenberg.org/cache/epub/1785/pg1785.txt -O caesar.txt

