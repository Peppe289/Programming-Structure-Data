#include "item.h"
#include "list.h"
#include <stdio.h>
#include "playlist.h"
#include "song.h"

#ifndef SONG_COMPILE
#define CREATE_DATA(x, y) addHead(x, y);
#define PRINT_LIST(x) printList(x);
#define REMOVE_LIST(x, y) removeListPos(x, y);
#define SORT_LIST(x) sortList(x);
#else
#define CREATE_DATA(x, y) addSong(x, y);
#define PRINT_LIST(x) printList(songList(x));
#define REMOVE_LIST(x, y) removeListPos(songList(x), y);
#define SORT_LIST(x) sortList(songList(x));
#endif

int main() {

#ifndef SONG_COMPILE
	List list = newList();
#else
	Playlist list = createPlaylist("BRUH");
#endif // SONG_COMPILE

	int i;
	int pos;
	Item stampa;
	Item el;
	
	for (i = 0; i < 4; i++){
		el = inputItem();
		CREATE_DATA(list, el);
	}

	PRINT_LIST(list);

	printf("\n");

	printf("Inserisci la posizione da eliminare: ");
	scanf("%d", &pos);
	stampa = REMOVE_LIST(list, pos);
	if (stampa == NULL)
		printf("Errore, item non trovato\n");
	else
	{
		printf("Item ");
		outputItem(stampa);
		printf("Eliminato\n");
	}


	printf("\nLista aggiornata: ");
	PRINT_LIST(list);

	printf("\nLista ordinata: ");
	SORT_LIST(list);
	PRINT_LIST(list);

	printf("\n");
	return 0;
}