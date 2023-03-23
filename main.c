#include <stdio.h>
#include <string.h>
#include "vettore.h"

static void output_array(int *data, int size)
{
    int i;

    for (i = 0; i != size; ++i)
        printf("%d ", data[i]);
}

/**
 * Aumenta la leggibilità
 */
int main()
{
    int size1, size2;
    char line[100];
    int *data1, *data2;
    int conc;
    int *array_conc;

    // array 1
    printf("Inserisci il vettore: ");
    scanf("%[^\n]", line);
    data1 = input_array_dyn(&size1, line);

    /**
     * Pulisci l'array @line e il buffer del terminale.
     * La pulitura del buffer di terminale serve l'input
     * della scanf() fatto in questo modo non prende
     * il carattere di invio.
     */
    memset(line, 0, sizeof(char) * 100);
    getchar();

    // array 2
    printf("Inserisci il vettore: ");
    scanf("%[^\n]", line);
    data2 = input_array_dyn(&size2, line);

    /**
     * Pulisci il buffer sporco con \n
     */
    getchar();

    printf("\nArray 1: ");
    output_array(data1, size1);

    printf("\nArray 2: ");
    output_array(data2, size2);

    // array concatenato
    array_conc = concatena_vet(data1, data2, size1, size2, &conc);

    printf("\nValore concatenato: ");
    output_array(array_conc, conc);

    free(data1);
    free(data2);
    free(array_conc);
    return 0;
}