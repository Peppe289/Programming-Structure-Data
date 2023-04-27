#include <stdlib.h>
#include <stdio.h>
#include <list.h>
#include <item.h>

struct list
{
	int size;
	struct node *head;
};

struct node
{
	Item value;
	struct node *next;
};

/**
 * Prende in input e alloca dinamicamente la stringa.
 * Il valore di ritorno è la stringa.
 *
 * Il vantaggio di questa funzione è il poter prendere gli spazi.
 */
char *inputString()
{
	char *ret;
	char tmp;
	int size = 1;
	ret = malloc(size * sizeof(char));

	do
	{
		tmp = getchar();
		ret = realloc(ret, (++size) * sizeof(char));
		ret[size - 2] = tmp;
	} while (tmp != '\n');

	ret[size - 2] = '\0';

	return ret;
}

struct node *headList(List data)
{
	return data->head;
}

struct node *nextList(struct node *data)
{
	return data->next;
}

Item valueNode(struct node *data)
{
	return data->value;
}

void sortList(List data)
{
	struct node *p;
	struct node *next;
	for (p = data->head; p != NULL; p = p->next)
	{
		// printf("%d -> ", *((int*)p->value));
		for (next = p->next; next != NULL; next = next->next)
		{
			if (cmpItem(p->value, next->value) > 0)
			{
				void *tmp;
				tmp = next->value;
				next->value = p->value;
				p->value = tmp;
			}
		}
	}
}

List newList()
{
	List list = malloc(sizeof(struct list));
	list->size = 0;
	list->head = NULL;
	return list;
}

int isEmpty(List list)
{
	if (list->size == 0)
		return 1;

	return 0;
}

void addHead(List list, Item el)
{

	struct node *newHead = malloc(sizeof(struct node));

	newHead->value = el;
	newHead->next = list->head;

	list->head = newHead;

	(list->size)++;
}

Item removeHead(List list)
{

	if (isEmpty(list))
		return NULL;

	struct node *temp = list->head;
	list->head = temp->next;

	Item el = temp->value;
	free(temp);

	(list->size)--;

	return el;
}

Item getHead(List list)
{

	if (isEmpty(list))
		return NULL;

	return list->head->value;
}

int sizeList(List list)
{
	return list->size;
}

/*
void printList(List list)
{
	struct node *p;
	for (p = list->head; p != NULL; p = p->next)
	{
		outputItem(p->value);
	}
}
*/

void printListRec(List data)
{
	/**
	 * E' necessaria una variabile ausiliaria
	 * che acquisisce la lista a partire
	 * dall'elemento successivo.
	 * Ad ogni ricorsione viene caricata
	 * una sottolista.
	 */
	struct list local;

	/**
	 * Caso Base: Lista vuota.
	 */
	if (isEmpty(data))
		return;

	/**
	 * Posizionati con la struct list all'elemento successivo.
	 */
	local.size = data->size - 1;
	local.head = ((struct node *)headList(data))->next;

	/* Stampa il dato */
	outputItem(getHead(data));

	/**
	 * Passo ricorsivo:
	 * E' necessario passare l'indirizzo poiché
	 * il parametro formare è un indirizzo di struct list.
	 *
	 * Il passaggio avviene con memoria stack per evitare malloc().
	 *
	 * N.B. Utilizzare i malloc() e quindi memoria heap nella ricorsione
	 * aumenta in modo significativo la complessità temporale.
	 */
	printListRec(&local);
}

Item searchListItem(List l, Item q, int *pos)
{
	struct node *p;
	*pos = 0;
	for (p = l->head; p != NULL; p = p->next, (*pos)++)
	{
		if (cmpItem(q, p->value) == 0)
		{
			return p->value;
		}
	}
	*pos = -1;
	return NULL;
}

Item removeListItem(List list, Item el)
{
	struct node *prev, *p;
	Item val;

	if (isEmpty(list))
		return NULL;

	/**
	 * Il valore da eliminare potrebbe
	 * essere un valore nullo.
	 */
	if (el == NULL)
		return NULL;

	p = list->head;

	if (cmpItem(el, p->value) == 0)
		return removeHead(list);

	for (prev = p, p = p->next; p != NULL; p = p->next)
	{
		if (cmpItem(el, p->value) != 0)
		{
			/**
			 * Salva il precedente se l'iterazione successiva
			 * è quella per rimuovere l'item. (o quelle dopo o nessuna).
			 */
			prev = p;
			continue;
		}

		prev->next = p->next;
		val = p->value; // assegno il valore precedente dell'item
		(list->size)--; // decremento taglia lista
		/**
		 * il valore dell'item viene restituito in output,
		 * sarà la funzione chiamante a liberare quella memoria.
		 */
		free(p);	// libero memoria p
		return val; // ritorno l'item
	}

	return NULL; // caso in cui non è stato trovato
}

Item removeListPos(List list, int pos)
{
	struct node *prev, *p;
	Item val;
	int i = 0;

	/**
	 * Controlllo precondizione
	 */
	if (isEmpty(list) || pos < 0 ||
		pos >= list->size)
		return NULL;

	p = list->head;

	if (pos == 0 && p != NULL)
		return removeHead(list);

	prev = p;

	for (i = 1, p = p->next; p != NULL; i++)
	{
		if (i != pos)
		{
			/**
			 * Salva il precedente se l'iterazione successiva
			 * è quella per rimuovere l'item. (o quelle dopo o nessuna).
			 *
			 * Passa anche al nodo successivo.
			 */
			prev = p;
			p = p->next;
			continue;
		}

		prev->next = p->next;
		val = p->value; // assegno il valore precedente dell'item
		(list->size)--; // decremento taglia lista
		/**
		 * il valore dell'item viene restituito in output,
		 * sarà la funzione chiamante a liberare quella memoria.
		 */
		free(p);	// libero memoria p
		return val; // ritorno l'item
	}

	return NULL;
}

int addListPos(List list, Item el, int pos)
{
	struct node *p = list->head, *newNode;
	int i;

	/**
	 * Controllo delle precondizioni.
	 */
	if (pos < 0 || pos > list->size)
		return 0;

	/**
	 * Se la posizione è 0 aggiungi in testa.
	 */
	if (pos == 0)
	{
		addHead(list, el);
		return 1;
	}

	/**
	 * Scorre le posizioni.
	 */
	for (i = 1; i < pos; i++, p = p->next)
		;

	/**
	 * - Crea il nuovo nodo.
	 * - Aggiungi l'elemento.
	 * - Aggiungi il nodo del nodo successivo.
	 * - Aggiungi l'indirizzo ad nodo->next precedente.
	 * - Incremeta la dimensione della lista.
	 */
	newNode = malloc(sizeof(struct node));
	newNode->value = el;
	/**
	 * ATTENZIONE: p->next potrebbe essere NULL.
	 * Nessuna correzione da fare.
	 */
	newNode->next = p->next;
	p->next = newNode;

	(list->size)++;

	return 1;
}

void reverseList(List list)
{
	struct node *read;
	struct node *prev = NULL;
	void *temp;

	for (read = list->head; read != NULL; read = temp)
	{
		/**
		 * - Salva il successivo
		 * - Metti il valore del precedente nel next dell'attuale nodo
		 * - Metti nel valore temporaneo prev il valore del nodo attuale.
		 *
		 * Nella istruzione di iterazione del for() con read = temp
		 * possiamo scorrere la sequenza non invertita, poiché
		 * temp contiene il vecchio nodo->next.
		 */
		temp = read->next;
		read->next = prev;
		prev = read;
	}

	/**
	 * Alla fine del ciclo assegna la nuova testa, ovvero l'ultimo nodo.
	 */
	list->head = prev;
}

List clonelist(List list)
{
	struct node *read;
	List ret;
	void *el;

	if (isEmpty(list))
		return NULL;

	/**
	 * Crea il nodo sopra la lista vuoto
	 *
	 * Contiene la dimensione e l'indirizzo del primo nodo utile.
	 */
	ret = newList();

	for (read = list->head; read != NULL; read = read->next)
	{
		el = cloneDataArgs(read->value);
		addHead(ret, el);
	}

	/**
	 * Ogni elemento viene inserito alla fine,
	 * quindi inverti la sequenda dopo aver clonato.
	 */
	reverseList(ret);

	return ret;
}

void destroyListRec(List data)
{
	/**
	 * Caso Base: Lista vuota.
	 */
	if (isEmpty(data))
	{
		/**
		 * Se la lista ormai è vuota e List non è NULL
		 * fai il free() anche di List.
		 */
		if (data) {
			fprintf(stdout, "\nLista eliminata, il programma verrà chiuso!\n");
			free(data);
		}

		return;
	}

	/**
	 * Rimuovi la testa di ogni sottolista ad ogni ricorsione.
	 */
	free(removeHead(data));

	/**
	 * Passo Ricorsivo
	 */
	destroyListRec(data);
}

int countItemListRec(List data, Item value) {
	/**
	 * E' necessaria una variabile ausiliaria
	 * che acquisisce la lista a partire
	 * dall'elemento successivo.
	 * Ad ogni ricorsione viene caricata
	 * una sottolista.
	 */
	struct list local;
	/**
	 * Contiene il valore di ritorno del confronto.
	 * Implementato solo per leggibilità del codice.
	 */
	int ret;

	/**
	 * Caso Base: Lista vuota.
	 */
	if (isEmpty(data))
		return 0;

	/**
	 * Posizionati con la struct list all'elemento successivo.
	 */
	local.size = data->size - 1;
	local.head = ((struct node *)headList(data))->next;

	/**
	 * Standard:
	 * 0 : dati uguali.
	 * 1 : dati non uguali.
	 * 
	 * La negazione logica può essere fatta con int, quindi produce:
	 * 0 : dati non uguali
	 * 1 : dati uguali.
	 * 
	 * il valore trovato viene sommato al valore di ritorno della ricorsione.
	 */
	ret = !cmpItem(getHead(data), value);

	return ret + countItemListRec(&local, value);
}

Item searchListRec(List data, Item value, int *) {

}