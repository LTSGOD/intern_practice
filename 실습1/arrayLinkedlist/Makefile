CC = gcc

TARGET = arrayLinkedlist

C_SRCS = $(wildcard *.c)
C_OBJS = $(patsubst %.c, build/%.o, $(C_SRCS))



all: $(TARGET)

$(TARGET): $(C_OBJS)
	$(CC) -o $@ $(C_OBJS)

build/%.o: %.c
	mkdir -p $(shell dirname $@)
	$(CC) -c -g $< -o $@