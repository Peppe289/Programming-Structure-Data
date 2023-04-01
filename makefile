FLAGS = -Wall -Wextra

SONG_DEF = -DSONG_COMPILE

link_song: list item_song main_song
	gcc list.o item_song.o main.o $(SONG_DEF)

link_int : list item_int main
	gcc list.o item_int.o main.o

link_str : list item_str main
	gcc list.o item_str.o main.o

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

#
# Senza creare un secondo main compilalo
# con direttive di preprocessione diverse.
#
main_song :
	gcc -c main.c $(FLAGS) $(SONG_DEF)

clean : 
	rm -f *.o a.out

