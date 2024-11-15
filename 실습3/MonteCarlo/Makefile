CC = gcc

TARGET = monte_carlo

# %.c -> 현재디렉토리에 있는 모든 c파일
# VPATH 지정시에 %.c가 현재 디렉토리뿐만아니라 VPATH에 있는 디렉토리도 추가
# %.c 에 ../RandomNumber/rand_between.c 기본적으로 포함되지 않음.

VPATH = ../RandomNumber

INCLUDE = -I ../RandomNumber

C_SRCS = monte_carlo.c rand_between.c
C_OBJS = $(patsubst %.c, build/%.o , $(C_SRCS))

all: $(C_OBJS)
	$(CC) -o $(TARGET) $(C_OBJS)

build/%.o: %.c
	mkdir -p $(shell dirname $@)
	$(CC) -c -o $@ $< $(INCLUDE)