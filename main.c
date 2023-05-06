#include <array.h>
#include <item.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue.h>

#define array_start(x) getArray(x) + getHead(x)
#define array_size(x) getTail(x) - getHead(x)

static void free_item(Item *array, int size)
{
	int i;

	for (i = 0; i != size; ++i)
		free(array[i]);
}

int main(void)
{
	Queue coda = newQueue();
	int i;

	for (i = 0; i < 5; i++)
	{
		enqueue(coda, inputItem());
	}

	/**
	 * Ordinamento:
	 * Complessità N * N/2
	 *
	 * Ad ogni passo ricorsivo il vettore viene ridotto di 1,
	 * quindi la ricerca si riduce alla sommatoria di N - 1 per ogni N.
	 *
	 * Es:
	 *
	 * - 1, 2, 3, 4, 5
	 * - 2, 3, 4, 5
	 * - 3, 4, 5
	 * - 4, 5
	 *
	 * Se resta solo un elemento non serve cercare il minimo.
	 */
	selection_sort_Rec(array_start(coda), array_size(coda));

	printf("\nOrdinato: ");
	printArray(array_start(coda), array_size(coda));

	/**
	 * Reverse:
	 * Complessità computazione N/2
	 *
	 * Il programma ricorsivo scambia il primo elemento con l'ultimo,
	 * ristringendo il vettore di size - 2 ad ogni passo ricorsivo.
	 *
	 * Ad ogni ricorsione quindi scambia due elementi concludendo
	 * quindi le operazioni in N/2.
	 */
	reverseArray_Rec(array_start(coda), array_size(coda));

	printf("\nReverse: ");
	printArray(array_start(coda), array_size(coda));

	/**
	 * - free array
	 * - free Queue
	 */
	free_item(array_start(coda), array_size(coda));
	free(coda);

	printf("\n");
	return 0;
}