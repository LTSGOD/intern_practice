CC = gcc

TARGET = bigNumber

INCLUDE = -I ../../실습1/arrayLinkedlist

VPATH = ../../실습1/arrayLinkedlist

C_SRCS = bigNumber.c
C_SRCS += $(notdir ../../실습1/arrayLinkedlist/linkedlist.c)
C_OBJS = $(patsubst %.c, build/%.o ,$(C_SRCS))

all: $(TARGET)

debug: $(TARGET)
	gdb ./bigNumber.exe

$(TARGET): $(C_OBJS)
	$(CC) -g -o $@ $(C_OBJS)


build/%.o: %.c
	mkdir -p $(shell dirname $@)
	$(CC) -c -g $(INCLUDE) -o $@ $<