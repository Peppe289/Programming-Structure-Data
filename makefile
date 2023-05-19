HEADERS = -Iinclude/

FLAGS = -Wall -Wextra


link: bst item_int main
	gcc item_int.o main.o bst.o $(FLAGS) $(HEADERS)

bst:
	gcc -c bst.c $(HEADERS) $(FLAGS)

item_int:
	gcc -c item_int.c $(HEADERS) $(FLAGS)

main:
	gcc -c main.c $(HEADERS) $(FLAGS)

clean:
	rm -rf *.o a.out

