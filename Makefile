CC=gcc
CFLAGS=-Wall -Werror -g -pthread 

PROG=udpmsg client server

.PHONY: all
all: $(PROG)

%: %.c 
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(PROG)
