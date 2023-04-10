#include <stdio.h>
#include <stdlib.h>
#include <playlist.h>
#include <item.h>
#include <list.h>
#include <song.h>

#ifndef SONG_COMPILE
#define CREATE_DATA(x, y) addHead(x, y)
#define PRINT_LIST(x) printList(x)
#define REMOVE_LIST(x, y) removeListPos(x, y)
#define SORT_LIST(x) sortList(x)
#define REMOVE_ITEM(x, y) removeListItem(x, y)
#define SIZE_LIST(x) sizeList(x)
#define DESTROY_NODE(x) removeHead(x)
#define DESTROY_LIST(x) free(x)
#define ADD_POS_LIST(x, y, z) addListPos(x, y, z)
#else
#define CREATE_DATA(x, y) addSong(x, y)
#define PRINT_LIST(x) printList(songList(x))
#define REMOVE_LIST(x, y) removeListPos(songList(x), y)
#define SORT_LIST(x) sortList(songList(x))
#define REMOVE_ITEM(x, y) removeListItem(songList(x), (Item)findName(songList(x), y))
#define SIZE_LIST(x) sizeList(songList(x))
#define DESTROY_NODE(x) removeHead(songList(x))
#define DESTROY_LIST(x) free(songList(x))
#define ADD_POS_LIST(x, y, z) addListPos(songList(x), y, z)
#endif

/**
 * Menù per l'utilizzo delle funzioni.
 */
static int choseMenu()
{
	int input;

	do
	{
		printf("\nScegli cosa vuoi fare:\n %s %s %s %s %s %s %s",
			   "0) Esci dal programma\n",
			   "1) Aggiungere un dato in testa alla lista\n",
			   "2) Rimuovere un dato\n",
			   "3) Rimuovere un dato con l'indice\n",
			   "4) Ordinare la lista.\n",
			   "5) Stampa la lista\n",
			   "6) Aggiungi un valore in una posizione\n");
		printf("$ ");
		scanf("%d", &input);

	} while (input < 0 || input > 6);

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
			size = SIZE_LIST(list);
			printf("\nExit...\nRimuovi la memoria di %d elementi\n",
				   size);

			for (i = 0; i != size; i++)
			{
				/**
				 * @DESTROY_NODE: è definito con removeHead().
				 * L'intendo è rimuovere tutte le teste
				 * per distruggere tutti i nodi.
				 *
				 * Tuttavia la funzione removeHead() ha un valore
				 * di ritorno che è un puntatore al dato eliminato.
				 *
				 * E' necessario fare il free() anche di quello.
				 */
				el = DESTROY_NODE(list);

				if (el)
				{
#ifdef SONG_COMPILE
					free(artist(el));
					free(title(el));
					free(el);
#else
					free(el);
#endif
				}
			}

			/**
			 * Rimuovi la memoria allocata con newList()
			 */
			DESTROY_LIST(list);

#ifdef SONG_COMPILE
			/**
			 * Rimuovi la memoria allocata con createPlaylist();
			 *
			 * La funzione è disponibile solo per item_song();
			 */
			free(list);
#endif
			// chiudi il programma
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
#ifdef GDB_DEBUG
			raise(SIGINT);
#endif
			stampa = REMOVE_ITEM(list, delete);
#ifdef GDB_DEBUG
			raise(SIGINT);
#endif
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

#ifdef SONG_COMPILE
				free(artist(stampa));
				free(title(stampa));
				free(stampa);
#else
				free(stampa);
#endif
			}
			free(delete);
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
#ifdef SONG_COMPILE
				free(artist(stampa));
				free(title(stampa));
				free(stampa);
#else
				free(stampa);
#endif
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
		case 6:
			printf("Inserisci la posizione: ");
			scanf("%d", &pos);

			// pulisci il buffer
			getchar();

			el = inputItem();
			if (ADD_POS_LIST(list, el, pos))
			{
				printf("Posizione aggiunta con successo!\n");
			}
			else
			{
				printf("Errore nell'aggiungere la posizione\n");
#ifdef SONG_COMPILE
				free(artist(el));
				free(title(el));
				free(el);
#else
				free(el);
#endif
			}
			break;
		default:
			/* none */
			break;
		}
	} while (1);

	printf("\n");
	return 0;
}