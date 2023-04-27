#include <stdio.h>
#include <stdlib.h>
#include <item.h>
#include <list.h>

#define CREATE_DATA(x, y) addHead(x, y)
//#define PRINT_LIST(x) printList(x)
#define PRINT_LIST(x) printListRec(x)
#define REMOVE_LIST(x, y) removeListPos(x, y)
#define SORT_LIST(x) sortList(x)
#define REMOVE_ITEM(x, y) removeListItem(x, y)
#define SIZE_LIST(x) sizeList(x)
#define DESTROY_NODE(x) removeHead(x)
#define DESTROY_LIST(x) free(x)
#define ADD_POS_LIST(x, y, z) addListPos(x, y, z)
#define REVERSE_LIST(x) reverseList(x)
#define CLONE_LIST(x) clonelist(x)

/**
 * Menù per l'utilizzo delle funzioni.
 */
static int choseMenu()
{
	int input;

	do
	{
		printf("\nScegli cosa vuoi fare:\n %s %s %s %s %s %s %s %s %s %s",
			   "0) Esci dal programma (Dealloca ricorsivamente)\n",
			   "1) Aggiungere un dato in testa alla lista\n",
			   "2) Rimuovere un dato\n",
			   "3) Rimuovere un dato con l'indice\n",
			   "4) Ordinare la lista.\n",
			   "5) Stampa la lista (ricorsivo)\n",
			   "6) Aggiungi un valore in una posizione\n",
			   "7) Reverse list\n",
			   "8) Clona la lista\n",
			   "9) Count value (ricorsivo)\n");
		printf("$ ");
		scanf("%d", &input);

	} while (input < 0 || input > 9);

	// pulisci il buffer
	getchar();

	return input;
}

int main(void)
{
	int i, chose, pos;
	void *delete;
	Item el, stampa;
	Item search;
	int size;

	List list = newList();

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
			
			destroyListRec(list);
			
#if 0
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
					free(el);
			}

			/**
			 * Rimuovi la memoria allocata con newList()
			 */
			DESTROY_LIST(list);
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
				free(stampa);
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
				free(stampa);
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
				free(el);
			}
			break;
			case 7:
				printf("Inverti la sequenza della lista...");
				REVERSE_LIST(list);
				printf("\nFatto!\n");
			break;
			case 8:
				/**
				 * Devo continuare l'adattamento al programma PSD-es5
				 * 
				 * La funzione worka ma non ho idea di dove ritornare la nuova lista. 
				 */
				// CLONE_LIST(list);
			break;
		case 9:
			printf("Inserisci il dato da cercare: ");
			search = addrDataInput();

			pos = countItemListRec(list, search);

			if (!pos)
			{
#ifdef INT_COMPILE
				printf("\nValore %d non trovato\n", *(int *)search);
#else
				printf("\nValore %s non trovato\n", (char *)search);
#endif
			}
			else
			{
#ifdef INT_COMPILE
				printf("\nValore %d presente %d volte\n", *(int *)search, pos);
#else
				printf("\nValore %s presente %d volte\n", (char *)search, pos);
#endif
			}
			free(search);
			break;
		default:
			/* none */
			break;
		}
	} while (1);

	printf("\n");
	return 0;
}