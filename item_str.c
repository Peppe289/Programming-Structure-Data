#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <list.h>
#include <item.h>

Item inputItem()
{
	printf("Inserisci la stringa: ");
	return inputString();
}

void outputItem(Item a)
{
	char *p = a;
	printf("%s ", p);
}
int cmpItem(Item a, Item b)
{
	char *p1 = a;
	char *p2 = b;

	return strcmp(p1, p2);
}

void *addrDataInput()
{
	return inputString();
}

/**
 * Ritorna l'indirizzo dell'Item value
 */
static void *addrStruct(Node data) {
	return valueNode(data);
}

/**
 * Per item_int la struttura è:
 * 
 * struct node {
 * 		Item value;
 * 		struct node *next;
 * }
 * 
 * @value: contiene una stringa su memoria heap.
 * Basta fare il free del valore.
 */
void free_struct(Node data) {
	free(addrStruct(data));
	free(data);
}

/**
 * Il parametro Item data dovrebbe contenere il valore di nodo->data.
 * 
 * - Crea la memoria heap per una nuova stringa.
 * - Copia il nuovo valore nella nuova memoria.
 * - Ritorna il nuovo indirizzo.
 */
Item cloneDataArgs(Item data) {
	char *ret;
	ret = malloc((strlen((char *)data) + 1) * sizeof(char));
	strcpy(ret, (char *)data);
	return ret;
}
