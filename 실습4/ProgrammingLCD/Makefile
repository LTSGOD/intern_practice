CC = gcc
CFLAGS = -lwiringPi 
OBJS = lcd2.o
TARGET = lcd2

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

clean:
	rm	-f	*.o
	rm	-f	$(TARGET)