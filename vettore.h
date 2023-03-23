#ifndef _VETTORE_H_
#define _VETTORE_H_

#include <stdio.h>
#include <stdlib.h>

int *input_array_dyn(int *size, const char *line);

int *concatena_vet(int *array1, int *array2, int size1, int size2, int *tot_size);

#endif // end _VETTORE_H_
