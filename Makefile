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
# Output name file
#
pwd = `pwd`
OUTPUT = stack

#
# C version
#
STD_VERSION = c2x
ifneq ($(std),)
	STD_VERSION = $(std)
endif

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

default: start

start: msg_start build
	@if [ -f $(pwd)/$(OUTPUT) ]; then \
		echo >&2 "***"; \
		echo >&2 "*** Build ended"; \
		echo >&2 "*** Check: $(pwd)/$(OUTPUT)"; \
		echo >&2 "***"; \
		true; \
	fi

build: clean item_str stack_array main
	@$(CC) stack_array.o item_str.o main.o -std=$(STD_VERSION) $(FLAGS) -o $(OUTPUT)

main:
	@$(CC) -c main.c -std=$(STD_VERSION) $(FLAGS)

stack_array:
	@$(CC) -c stack_array.c -std=$(STD_VERSION) $(FLAGS)

item_str:
	@$(CC) -c item_str.c -std=$(STD_VERSION) $(FLAGS)

msg_start:
	@echo "Start build..."
	@echo " "
	@echo "*** Flags:	$(FLAGS)"
	@echo "*** Compiler: 	$(CC)"
	@echo "*** C version:	$(STD_VERSION)"
	@echo " "
	@echo "Build..."
	@echo " "

clean: 
	@rm -f *.o a.out $(OUTPUT)

