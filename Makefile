FLAGS = -Wall -Wextra -Iinclude/ -g

SONG_DEF = -DSONG_COMPILE
INT_DEF = -DINT_COMPILE
STRING_DEF = -DSTRING_COMPILE

link_song: clean list item_song main_song
	gcc list.o item_song.o main.o $(SONG_DEF) $(FLAGS)

link_int: clean list item_int main_int
	gcc list.o item_int.o main.o $(INT_DEF) $(FLAGS)

link_str: clean list item_str main_str
	gcc list.o item_str.o main.o $(STRING_DEF) $(FLAGS)

item_str:
	gcc -c item_str.c $(FLAGS)

item_int:
	gcc -c item_int.c $(FLAGS)

item_song:
	gcc -c item_song.c $(FLAGS)

list:
	gcc -c list.c $(FLAGS)

main_song: 
	gcc -c main.c $(FLAGS) $(SONG_DEF)

main_int: 
	gcc -c main.c $(FLAGS) $(INT_DEF)

main_str: 
	gcc -c main.c $(FLAGS) $(STRING_DEF)

clean: 
	rm -f *.o a.out

