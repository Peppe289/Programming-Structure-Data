build: clean item-string list btree main
	gcc item-string.o main.o list.o btree.o -Wall -Wextra

item-string:
	gcc -c item-string.c -Wall -Wextra

list:
	gcc -c list.c -Wall -Wextra

main:
	gcc -c main.c -Wall -Wextra

btree:
	gcc -c btree.c -Wall -Wextra

clean:
	rm -rf *.o a.out