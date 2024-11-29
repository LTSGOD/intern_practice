CC = gcc
CFLAGS = -lwiringPi
SRCS = client_sender.c server_receiver.c
TARGETS = $(SRCS:.c=)

all: $(TARGETS)

%: %.c
	$(CC) -o $@ $< $(CFLAGS)

clean:
	rm -f $(TARGETS) *.o
