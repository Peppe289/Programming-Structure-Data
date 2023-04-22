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
# Output name file
#
pwd = `pwd`
OUTPUT = stack

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
	@$(CC) stack_array.o item_str.o main.o $(FLAGS) -o $(OUTPUT)

main:
	@$(CC) -c main.c $(FLAGS)

stack_array:
	@$(CC) -c stack_array.c $(FLAGS)

item_str:
	@$(CC) -c item_str.c $(FLAGS)

msg_start:
	@echo "Start build..."
	@echo "Flags: 		$(FLAGS)"
	@echo "Compiler: 	$(CC)"
	@echo " "
	@echo "Build..."
	@echo " "

clean: 
	@rm -f *.o a.out $(OUTPUT)

