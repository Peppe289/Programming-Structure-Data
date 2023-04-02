#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"
#include "item.h"
#include "list.h"
#include "song.h"

#ifndef SONG_COMPILE
#define CREATE_DATA(x, y) addHead(x, y);
#define PRINT_LIST(x) printList(x);
#define REMOVE_LIST(x, y) removeListPos(x, y);
#define SORT_LIST(x) sortList(x);
#define REMOVE_ITEM removeListItem(x, y);
#else
#define CREATE_DATA(x, y) addSong(x, y);
#define PRINT_LIST(x) printList(songList(x));
#define REMOVE_LIST(x, y) removeListPos(songList(x), y);
#define SORT_LIST(x) sortList(songList(x));
#define REMOVE_ITEM(x, y) removeListItem(songList(x), (Item)findName(songList(x), y));
#endif

/**
 * Menù per l'utilizzo delle funzioni.
 */
static int choseMenu()
{
	int input;

	do
	{
		printf("\nScegli cosa vuoi fare:\n %s %s %s %s %s %s",
			   "0) Esci dal programma\n",
			   "1) Aggiungere un dato in testa alla lista\n",
			   "2) Rimuovere un dato\n",
			   "3) Rimuovere un dato con l'indice\n",
			   "4) Ordinare la lista.\n",
			   "5) Stampa la lista\n");
		printf("$ ");
		scanf("%d", &input);

	} while (input < 0 || input > 5);

	// pulisci il buffer
	getchar();

	return input;
}

int main(void)
{
	int i, chose, pos;
	void *delete;
	Item el, stampa;
	int size;

#ifndef SONG_COMPILE
	List list = newList();
#else
	Playlist list = createPlaylist("BRUH");
#endif // SONG_COMPILE

	do
	{
		chose = choseMenu();
		switch (chose)
		{
		/* esci dal programma */
		case 0:
			exit(0);
			break;
		/* Aggiungere un dato in testa alla lista */
		case 1:
			printf("Scegli quanti valori vuoi inserire: ");
			scanf("%d", &size);
			
			// clear buffer
			getchar();

			for (i = 0; i < size; i++)
			{
				el = inputItem();
				CREATE_DATA(list, el);
			}
			break;
		/* Rimuovere un dato */
		case 2:
			printf("Inserisci il dato da eliminare: ");
			delete = addrDataInput();
			stampa = REMOVE_ITEM(list, delete);
			if (!stampa)
			{
#ifdef INT_COMPILE
				printf("\nValore %d non trovato\n", *(int *)delete);
#else
				printf("\nValore %s non trovato\n", (char *)delete);
#endif
			}
			else
			{
				printf("\nEliminato: ");
				outputItem(stampa);
			}
			break;
		/* Rimuovere un dato con l'indice */
		case 3:
			printf("Inserisci la posizione da eliminare: ");
			scanf("%d", &pos);
			stampa = REMOVE_LIST(list, pos);
			if (stampa == NULL)
				printf("Errore, item non trovato\n");
			else
			{
				printf("\nEliminato: ");
				outputItem(stampa);
			}
			break;
		/* Ordinare la lista */
		case 4:
			printf("\nOrdina la lista...");
			SORT_LIST(list);
			printf("\nDone!");
			break;
		case 5:
			PRINT_LIST(list);
			break;
		default:
			/* none */
			break;
		}
	} while (1);

	printf("\n");
	return 0;
}