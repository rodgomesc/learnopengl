CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lglfw3 -lopengl32
TARGET = main

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c $(LDFLAGS)

clean:
	rm -f $(TARGET) 