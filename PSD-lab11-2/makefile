# bruh

HEADERS = -Iinclude

FLAGS = -Wall -Wextra

link: clean stack_array item_int main queue
	gcc stack_array.o item_int.o main.o queue.o -o queue $(HEADERS) $(FLAGS)

queue:
	gcc -c queue.c $(HEADERS) $(FLAGS)

#item_str:
#	gcc -c item_str.c $(HEADERS) $(FLAGS)

item_int:
	gcc -c item_int.c $(HEADERS) $(FLAGS)

stack_array:
	gcc -c stack_array.c $(HEADERS) $(FLAGS)

main:
	gcc -c main.c $(HEADERS) $(FLAGS)

clean:
	rm -rf *.o queue

