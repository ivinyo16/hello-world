CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11
SRC = linear_search.c
OBJ = $(SRC:.c=.o)
TARGET = a

ifeq ($(OS),Windows_NT)
    RM = del /f /q
	FixPath = $(subst /,\,$1)
else
    RM = rm -f
	FixPath = $1
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(call FixPath,$(OBJ) $(TARGET).exe)

.PHONY: all clean