CC = gcc
CFLAGS = -g -Wall -ansi

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) -o $@  -c $< $(CFLAGS) 

genetic_algorithm: $(OBJS)
	$(CC) -o $@ $^
