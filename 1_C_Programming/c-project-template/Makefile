CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11
SRC = src/code.c
OBJ = $(SRC:.c=.o)
TARGET = template

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean