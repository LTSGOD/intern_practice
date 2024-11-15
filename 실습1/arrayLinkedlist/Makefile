CC = gcc

TARGET = arrayLinkedlist

C_SRCS = $(wildcard *.c)
C_OBJS = $(C_SRCS:.c=.o)



all: $(TARGET)

$(TARGET): $(C_OBJS)
	$(CC) -o $@ $(C_OBJS)

%.o: %.c
	$(CC) -c -g $< -o $@