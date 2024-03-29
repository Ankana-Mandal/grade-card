
# Makefile for compiling the C program with multiple source files

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Source files
SRCS = main.c average.c grade-card.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
EXEC = grade-card

# Default target
all: $(EXEC)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into executable
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

# Clean up intermediate object files and executable
clean:
	rm -f $(OBJS) $(EXEC)