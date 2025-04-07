CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Isrc/lib
LDFLAGS = -lglfw3 -lopengl32 -lgdi32
TARGET = main


all: $(TARGET)

$(TARGET): src/main.c $(GLAD_SRC)
	$(CC) $(CFLAGS) -o $(TARGET) src/main.c  $(LDFLAGS)

clean:
	rm -f $(TARGET) 