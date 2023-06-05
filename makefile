build: clean item list btree main
	gcc item-int.o main.o list.o btree.o -Wall -Wextra

item:
	gcc -c item-int.c -Wall -Wextra

list:
	gcc -c list.c -Wall -Wextra

main:
	gcc -c main.c -Wall -Wextra

btree:
	gcc -c btree.c -Wall -Wextra

clean:
	rm -rf *.o a.out