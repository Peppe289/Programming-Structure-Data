#include <stdio.h>

#define N 8

// T(n) = 3 = O(1)
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// T(n) = O(n) = Omega(n) = Theta(n)
int minimo(int *array, int n)
{
	int i;
	int minimo = 0;

	for (i = 1; i < n; i++)
	{
		if (array[minimo] > array[i])
		{
			minimo = i;
		}
	}

	return minimo;
}

void inputArray(int *array, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
}

void printArray(int *array, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
}

// T(n) = n * Theta(n) = Theta(n^2)
void selectionSort(int *array, int n)
{
	int i;
	int min;

	for (i = 0; i < n - 1; i++)
	{
		min = minimo(array + i, n - i) + i; // Theta(n)
		swap(&array[min], &array[i]);
	}
}

// T(n) = O(n) = Omega(1)
void insertSortedArray(int *array, int val, int *n)
{
	int i;
	for (i = (*n); i > 0 && array[i - 1] > val; i--)
	{
		array[i] = array[i - 1];
	}
	array[i] = val;
	(*n)++;
}

// T(n) = O(n^2) = Omega(n)
void insertionSort(int *array, int n)
{
	int i = 1;
	while (i < n)
		insertSortedArray(array, array[i], &i); //
}

// T(n) = O(n^2) = Omega(n)
void bubbleSort(int *array, int n)
{
	int i, j, ordinato = 0;
	for (i = 1; i < n && !ordinato; i++)
	{
		ordinato = 1;
		for (j = 0; j < n - i; j++) // Theta(n)
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				ordinato = 0;
			}
	}
	if (ordinato == 1)
		printf("L'array è già ordinato\n");
}
// T(n)=T(n/2)+c
int ricercaBR(int *arr, int inf, int sup, int k)
{
	int centro;
	if (inf > sup)
		return -1;
	else
	{
		centro = (inf + sup) / 2;
		if (arr[centro] == k)
			return centro;
		else if (arr[centro] < k)
		{
			return ricercaBR(arr, centro + 1, sup, k);
		}
		else
			return ricercaBR(arr, inf, centro - 1, k);
	}
}

int ricercaBinariaR(int *arr, int size, int k)
{
	return ricercaBR(arr, 0, size - 1, k);
}

void merge(int *array_1, int *array_2, int size_1, int size_2, int *full)
{
	int i, j, k, buff[size_1 + size_2];

	for (i = j = k = 0; i < size_1 && j < size_2; k++)
	{
		if (array_1[i] <= array_2[j])
		{
			buff[k] = array_1[i];
			i++;
		}
		else
		{
			buff[k] = array_2[j];
			j++;
		}
	}

	/**
	 * Carica la prima parte dell'array
	 */
	for (; i < size_1; i++, k++)
		buff[k] = array_1[i];

	/**
	 * Carica la seconda parte dell'array
	 */
	for (; j < size_2; j++, k++)
		buff[k] = array_2[j];

	/**
	 * Carica fai il merge dell'array locale con l'array totale.
	 */
	for (k = 0; k < size_1 + size_2; k++)
		full[k] = buff[k];
}

#if 0
void mergeSort(int *array, int size)
{
	if (size > 1)
	{
		mergeSort(array, size / 2, 1 + tmp);
		mergeSort(array + size / 2, size - size / 2, 1 + tmp);
		merge(array, array + size / 2, size / 2, size - size / 2, array);
	}
}
#endif

/**
 * @left:
 * 		indice di partenza
 * @left_size:
 * 		dimensione maggiore del pezzo di array sinistro.
 * 		si esprime in potenza di 2
 * @right_size:
 * 		dimensione maggiore del pezzo di array destro.
 * 		si esprime in potenza di 2 oppure se il valore
 * 		può causare errori in memoria (supera size)
 * 		il valore è uguale a (left_size * 2) - size.
 */
void mergeSort(int *array, int size)
{
	int left;
	int left_size;
	int right_size;

	for (left_size = 1; left_size < size; left_size *= 2)
	{
		right_size = left_size;
		for (left = 0; left + left_size < size; left += left_size + right_size)
		{
			/**
			 * Controlla se il valore può causare errore di memoria.
			 * Se va oltre carica la differenza tra la size e il lato sinistro
			 * (parte di array restante).
			 */
			if (left + left_size + right_size > size)
				right_size = size - (left + left_size);

			merge(&array[left], &array[left + left_size], left_size,
				  right_size, &array[left]);
		}
	}
}

int partition(int *arr, int begin, int end)
{
	int pivot = arr[begin], i = begin - 1, j = end + 1;

	while (1)
	{
		do
		{
			j--;
		} while (arr[j] > pivot);

		do
		{
			i++;
		} while (arr[i] < pivot);

		if (i >= j)
			return j;

		swap(arr + j, arr + i);
	}
}

void qSort(int *arr, int begin, int end)
{
	if (begin < end)
	{
		int p = partition(arr, begin, end);
		qSort(arr, begin, p);
		qSort(arr, p + 1, end);
	}
}

void quickSort(int *arr, int size)
{
	qSort(arr, 0, size - 1);
}

int main()
{
	int array[N];
	int size = sizeof(array) / sizeof(int);

	inputArray(array, size);
	mergeSort(array, size);
	printf("\n");
	printf("\n");
	printArray(array, size);

	return 0;
}
