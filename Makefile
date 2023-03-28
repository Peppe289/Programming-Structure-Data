HEADER = -Iinclude/

CC = gcc

FLAGS = -lm -O3 -Wall -Wextra

default: clean object
	@$(CC) $(HEADER) $(FLAGS) *.o

object:
	@$(CC) $(HEADER) $(FLAGS) *.c -c

clean:
	@rm -rf *.o a.out