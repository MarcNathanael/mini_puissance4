# Variables
CC = gcc
CFLAGS = -Wall -Wextra
TARGET = puissance4
SRCS = main.c fonction.c

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
