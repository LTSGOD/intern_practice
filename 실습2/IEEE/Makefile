CC = gcc

FILENAME = ieee 

C_SRCS = ieee.c ../Bitwise/Bitwise.c
C_OBJS = $(C_SRCS:.c=.o)

all: $(C_OBJS)
	$(CC) -o $(FILENAME) $(C_OBJS)

%.o: %.c
	$(CC) -c -g -I ../Bitwise $< -o $@
# all: ieee.o Bitwise.o
# 	gcc -o $(FILENAME) ieee.o Bitwise.o

# ieee.o: ieee.c
# 	gcc -c -g -I ../Bitwise ieee.c

# Bitwise.o: ../Bitwise/Bitwise.c
# 	gcc -c  -g ../Bitwise/Bitwise.c