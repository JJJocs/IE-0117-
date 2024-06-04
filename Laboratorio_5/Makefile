CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = main
OBJS = main.o double_list.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c double_list.h
	$(CC) $(CFLAGS) -c main.c

double_list.o: double_list.c double_list.h
	$(CC) $(CFLAGS) -c double_list.c

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: clean
