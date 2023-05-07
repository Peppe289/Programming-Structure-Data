#include <stdio.h>
#include <item.h>
#include <utils.h>
#include <string.h>
#include <queue.h>

void inputArray(Item arr[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		arr[i] = inputItem();
	}
}

void printArray(Item arr[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		outputItem(arr[i]);
	}
}

void bubbleSort(Item arr[], int n)
{
	int i, j;
	for (i = 1; i < n; i++)
		for (j = 0; j < n - i; j++)
			if (cmpItem(arr[j], arr[j + 1]) > 0)
				swap(&arr[j], &arr[j + 1]);
}

/************************************************
****************** Ordinamento ******************
*************************************************/
static int find_min(Item arr[], int size)
{
	int index;

	/**
	 * Se arrivi alla fine dell'array non devi confrontare.
	 */
	if (size == 1)
		return 0;

	/**
	 * ricorsivamente a partire dagli ultimi
	 * elementi confrontali e ritorna ogni volta
	 * l'index con valore minore.
	 */
	index = find_min(arr, size - 1);

	if (cmpItem(arr[size - 1], arr[index]) < 0)
		return size - 1;
	else
		return index;
}

void selection_sort_Rec(Item array[], int size)
{
	int tmp;

	/**
	 * Fine dell'array
	 */
	if (size < 2)
		return;

	tmp = find_min(array, size);

	/**
	 * Algoritmo stabile: se gli indirizzi sono uguali non scambiarli.
	 */
	if (tmp)
	{
#if 0 // debug
		printf("%s(): scambia array[0]: %d con array[%d]: %d\n",
						__func__, *(int *)array[0], tmp, *(int *)array[tmp]);
#endif
		swap(&array[0], &array[tmp]);
	}

	selection_sort_Rec(array + 1, size - 1);
}
/************************************************
********************** End **********************
*************************************************/

/************** Reverse Ricorsivo **************/
void reverseArray_Rec(Queue q, int size)
{
	Item tmp;

	/**
	 * Passo base:
	 *
	 * - Se la coda è vuota.
	 * - Se size è 1: quindi è rimasto l'ultimo
	 * elemento che non deve essere spostato,
	 * ma sarà lui ad essere in cima alla testa.
	 */
	if (isEmptyQueue(q) || size == 1)
	{
		return;
	}

	/**
	 * - Rimuovi la coda;
	 * - Passo ricorsivo;
	 * - Aggiungi la testa alla coda.
	 */
	tmp = dequeue(q);
	reverseArray_Rec(q, size - 1);
	enqueue(q, tmp);
}
/***********************************************/
