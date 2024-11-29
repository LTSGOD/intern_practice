CC = gcc
CFLAGS = -lwiringPi
SRCS = sender.c receiver.c
TARGETS = $(SRCS:.c=)

all: $(TARGETS)

%: %.c
	$(CC) -o $@ $< $(CFLAGS)

clean:
	rm -f $(TARGETS) *.o
