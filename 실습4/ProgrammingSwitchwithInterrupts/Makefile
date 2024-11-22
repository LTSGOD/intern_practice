CC = gcc
CFLAGS = -lwiringPi 
OBJS = switchInterrupt.o
TARGET = switchInterrupt

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

clean:
	rm	-f	*.o
	rm	-f	$(TARGET)