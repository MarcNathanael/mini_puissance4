# Variables
CC = gcc
CFLAGS = -Wall -Wextra
TARGET = puissance4
SRCS = main.c fonction.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(SRCS) $(TARGET)
