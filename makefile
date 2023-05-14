#
# Make 4.4.1
#
HEADER = include/

## compiler
CC = gcc

## root project
PROJECT_ROOT = `pwd`

## source
PROJECT_SOURCE = $(PROJECT_ROOT)/src

## item
ITEM_FILE = $(PROJECT_SOURCE)/item

## stack
STACK_FILE = $(PROJECT_SOURCE)/stack

## tree
BTREE_FILE = $(PROJECT_SOURCE)/tree

MAIN = $(PROJECT_SOURCE)/main.c

## output build
output_build = $(PROJECT_ROOT)/build

build: create_dir link_str clean-obj
	@if [ -f ${output_build}/exec ]; then \
		echo >&2 "***"; \
		echo >&2 "*** Build ended"; \
		echo >&2 "*** Check: ${output_build}/exec"; \
		echo >&2 "***"; \
		true; \
	fi

run:
	@cd ${output_build}/; ./exec

create_dir:
	@mkdir ${output_build}/

link_str: btree item_str main stack
	@$(CC) ${output_build}/*.o -o ${output_build}/exec -I$(HEADER)

btree:
	@$(CC) -c $(BTREE_FILE)/btree.c -o ${output_build}/btree.o -I$(HEADER)

#item_int:
#	@$(CC) -c $(ITEM_FILE)/item_int.c -o ${output_build}/item_str.o -I$(HEADER)

item_str:
	@$(CC) -c $(ITEM_FILE)/item_str.c -o ${output_build}/item_str.o -I$(HEADER)

main:
	@$(CC) -c $(MAIN) -o ${output_build}/main.o -I$(HEADER)

stack:
	@$(CC) -c $(STACK_FILE)/stack_array.c -o ${output_build}/stack_array.o -I$(HEADER)

clean-obj:
	@rm -f ${output_build}/*.o

clean_all:
	rm -rf ${output_build}/

