CC = gcc

FILENAME = main

C_SRCS = $(wildcard *.c)
C_OBJS = $(C_SRCS:.c=.o)

all: $(C_OBJS)
	$(CC) -o $(FILENAME) $(C_OBJS)

%.o: %.c
	$(CC) -c -g  $< -o $@