# Compiler and flags
CC = gcc
CFLAGS = -Wall -pthread

# Targets
all: zad1 zad2

program1: program1.c
	$(CC) $(CFLAGS) -o zad1 zad1.c

program2: program2.c
	$(CC) $(CFLAGS) -o zad2 zad2.c

# Clean up build artifacts
clean:
	rm -f zad1 zad2
