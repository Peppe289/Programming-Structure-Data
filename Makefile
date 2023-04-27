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

INT_DEF = -DINT_COMPILE
STRING_DEF = -DSTRING_COMPILE

link_int: clean list item_int main_int
	$(CC) list.o item_int.o main.o $(INT_DEF) $(FLAGS)

link_str: clean list item_str main_str
	$(CC) list.o item_str.o main.o $(STRING_DEF) $(FLAGS)

item_str:
	$(CC) -c item_str.c $(FLAGS)

item_int:
	$(CC) -c item_int.c $(FLAGS)

list:
	$(CC) -c list.c $(FLAGS)

main_int: 
	$(CC) -c main.c $(FLAGS) $(INT_DEF)

main_str: 
	$(CC) -c main.c $(FLAGS) $(STRING_DEF)

clean: 
	rm -f *.o a.out

