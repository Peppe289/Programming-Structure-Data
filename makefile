#
# make version 4.4.1
#

#
# Debug
#
FLAGS = -Wall -Wextra -g

#
# header
#
FLAGS += -Iinclude/

#
# Other flags
#
FLAGS += -std=c2x

#
# Compiler
#
ifeq ($(cc), )
	CC = gcc
else
	CC = $(cc)
endif

#
# Macro per abilitare il debug con GDB 
#
ifeq ($(dbg), true)
	FLAGS += -DGDB_DEBUG
endif

#
# Aggiungi flag al lauch del make
#
ifneq ($(flags), )
	FLAGS += $(flags)
endif

link_int: array utils item_int main queue
	$(CC) array.o utils.o item_int.o main.o queue_array.o $(FLAGS)

link_str: array utils item_str main queue
	$(CC) array.o utils.o item_str.o main.o queue_array.o $(FLAGS)

item_str:
	$(CC) -c item_str.c $(FLAGS)

item_int:
	$(CC) -c item_int.c $(FLAGS)
	
array:
	$(CC) -c array.c $(FLAGS)

utils:
	$(CC) -c utils.c $(FLAGS)

main: 
	$(CC) -c main.c $(FLAGS)

queue:
	$(CC) -c queue_array.c $(FLAGS)

clean:
	rm -f *.o a.out
