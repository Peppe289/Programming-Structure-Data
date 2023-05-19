HEADERS = -Iinclude/

FLAGS = -Wall -Wextra


link:  btree item_int main
	gcc item_int.o main.o btree.o $(HEADERS)

btree:
	gcc -c btree.c $(HEADERS) $(FLAGS)

item_str:
	gcc -c item_str.c $(HEADERS) $(FLAGS)

item_int:
	gcc -c item_int.c $(HEADERS) $(FLAGS)

main:
	gcc -c main.c $(HEADERS) $(FLAGS)

clean:
	rm -rf *.o a.out

