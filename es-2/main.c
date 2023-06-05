#include "item.h"
#include "list.h"
#include "auto.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(Item *d1, Item *d2) {
	Item tmp;
	tmp = *d1;
	*d1 = *d2;
	*d2 = tmp;
}

/**
 * Confronta per tarda. Ci serve nell'ordinamento.
 */
int confronta(Item data1, Item data2) {
	int t1 = getProd(data1);
	int t2 = getProd(data2);

	return t1 - t2;
}

/**
 * Utilizza la procedura in loco per ordinare.
 * 
 * Svuota la lista mettendo il valore in un array,
 * ordina l'array e poi ricarica la lista
 * (al contrario se aggiungiamo in testa).
 */
void SelectionSort(List lista) {
	Item *tmp;
	int i, k, size, min;

	if (isEmpty(lista))
		return;

	size = sizeList(lista);
	tmp = malloc(sizeof(Item) * size);

	/**
	 * Carica i dati nel vettore svuotando dalla testa.
	 */
	for (i = 0; i < size; ++i) {
		tmp[i] = removeHead(lista);
	}

	for (i = 0; i != size - 1; ++i) {
		min = i;
		for (k = i + 1; k < size; ++k) {
			if (confronta(tmp[k], tmp[min]) < 0) {
				swap(&tmp[k], &tmp[min]);
				min = k;
			}
		}
	}

	/**
	 * Ricarica i valori svuotati.
	 */
	for (i = size - 1; i >= 0; --i) {
		addHead(lista, tmp[i]);
	}

	free(tmp);
}

/**
 * Cerca l'auto in base alla targa.
 * 
 * Ad ogni chiamata ricorsiva nello stack precedente viene lasciato
 * il valore rimosso dall'head per poi essere aggiunto di nuovo
 * alla chiusura della ricorsione.
 * 
 * Quando trovi il valore restituiscilo.
 * Se non lo trova allora restituisce NULL.
 * 
 * Non trovo altro modo per scorrere la lista.
 */
Item searchIn(List data, char *targa) {
	Item tmp;
	Item ret;

	if (isEmpty(data))
		return NULL;

	tmp = getTarga(getHead(data));

	if (!strcmp(tmp, targa))
		return getHead(data);

	tmp = removeHead(data);
	ret = searchIn(data, targa);
	addHead(data, tmp);

	return ret;
}

/**
 * Scorri ricorsivamente la lista. quando trovi il valore da elimare
 * togli il valore e fai i free.
 * 
 * Ad ogni chiamata ricorsiva nello stack precedente viene lasciato
 * il valore rimosso dall'head per poi essere aggiunto di nuovo
 * alla chiusura della ricorsione.
 * 
 * Non trovo altro modo per scorrere la lista.
 */
int removeCar(List data, char *targa)
{
	Item tmp;
	int ret;

	if (isEmpty(data))
		return 0;

	tmp = getTarga(getHead(data));

	if (!strcmp(tmp, targa))
	{
		tmp = removeHead(data);
		free(getTarga(tmp));
		free(getModello(tmp));
		free(tmp);
		return 1;
	}

	tmp = removeHead(data);
	ret = removeCar(data, targa);
	addHead(data, tmp);

	return ret;
}

/**
 * @buff: valore contente:
 *
 * 1) targa
 * 2) modello
 * 3) anno di produzione
 * 4) anno di matricolazione
 */
void load_from_file(List concess)
{
	FILE *fp = fopen("file.txt", "r");
	int k;
	char line[50], buff[4][50];
	Item el;

	while (1)
	{
		k = 0;
		while (k < 4)
		{
			if (fscanf(fp, "%s", line) == EOF)
			{
				goto exit;
			}

			strcpy(buff[k], line);
			k++;
		}

		el = newAuto(buff);
		addHead(concess, el);
	}

exit:
	fclose(fp);
}

void free_struct(List data)
{
	Item el;

	if (isEmpty(data))
	{
		free(data);
		return;
	}

	el = removeHead(data);
	free(getTarga(el));
	free(getModello(el));
	free(el);

	free_struct(data);
}

int main()
{
	List concessionario = newList();
	char tmp[40];
	Item el;

	load_from_file(concessionario);

	printf("\n\n");
	printList(concessionario);

	SelectionSort(concessionario);

	printf("\n\n");
	printList(concessionario);

	printf("\n\nInserisci la targa da rimuovere: ");
	scanf("%s", tmp);

	if(removeCar(concessionario, tmp))
		printf("\nMacchina rimossa con successo\n");
	else
		printf("\nImpossibile trovare la macchina da rimuovere\n");

	printList(concessionario);

	printf("\nInserisci il numero di targa da cercare: ");
	scanf("%s", tmp);

	el = searchIn(concessionario, tmp);
	
	if (el != NULL) {
		printf("\nTarga trovata!");
		outputItem(el);
	} else {
		fprintf(stderr, "\nTarga non trovata");
	}

	free_struct(concessionario);
	printf("\n");

	return 0;
}