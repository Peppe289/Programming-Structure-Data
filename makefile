FLAGS = -Wall -Wextra -Iinclude/

SONG_DEF = -DSONG_COMPILE
INT_DEF = -DINT_COMPILE
STRING_DEF = -DSTRING_COMPILE

link_song: list item_song main
	gcc list.o item_song.o main.o $(SONG_DEF)

link_int : list item_int main
	gcc list.o item_int.o main.o $(INT_DEF)

link_str : list item_str main
	gcc list.o item_str.o main.o $(STRING_DEF)

item_str :
	gcc -c item_str.c $(FLAGS)

item_int :
	gcc -c item_int.c $(FLAGS)

item_song :
	gcc -c item_song.c $(FLAGS)

list :
	gcc -c list.c $(FLAGS)

main : 
	gcc -c main.c $(FLAGS)

clean : 
	rm -f *.o a.out

