#include <math.h>
#include "vettore.h"

typedef enum bool
{
    false = 0,
    true = 1,
} bool;

/**
 * La funzione prende da un buffer di stringhe gli interi
 * e li restituisce in un puntatore di int.
 */
int *input_array_dyn(int *size, const char *line)
{
    /**
     * @ret:    array con valori estratti dal pointer buffer.
     *          La memoria viene allocata dinamicamente.
     * @buff:   Valore temporaneo preso in sscanf().
     * @i:      Incremento del for.
     * @size:   Dimensione di realloc().
     * @index:  Indice della linea del buffer.
     * @len:    Lunghezza dei caratteri letti.
     */
    int *ret;
    int i, buff;
    int index = 0;
    int len;

    *size = 1;
    ret = malloc(*size * sizeof(int));

#ifdef DEBUG
    printf("%s\n", line);
#endif

    for (i = 0; true; ++i)
    {

        /**
         * Se l'utente ha inserito più spazi skippa.
         */
        if (line[index] == ' ')
        {
            index++;
            continue;
        }

        // ripeti fino a fine dell'input (EOF).
        if (sscanf(&line[index], "%d%n", &buff, &len) != EOF)
        {
            /**
             * len è per la lunghezza del numero.
             * In questo modo cambia l'indice
             * dell'indirizzo base per poter leggere
             * il numero successivo.
             */
            index += len;
#ifdef DEBUG
            printf("%d ", buff);
#endif
            ret[*size - 1] = buff;
            ret = realloc(ret, (++(*size)) * sizeof(int));
        }
        else
        {
            break;
        }
    }

    /**
     * Poiché il valore è incrementato nella funzione realloc()
     * da parametro per l'input successivo, decrementa il valore
     * a fine operazione.
     */
    --(*size);
    return ret;
}

/**
 * Restituisce il nuovo array concatenato sui 2 presi in input.
 */
int *concatena_vet(int *array1, int *array2, int size1, int size2, int *tot_size) {
    int *ret;
    int i;

    ret = malloc((size1 + size2) * sizeof(int));

    for (i = 0; i < size1; ++i)
        ret[i] = array1[i];

    for (i = 0; i < size2; ++i)
        ret [i + size1] = array2[i];

    *tot_size = size1 + size2;

    return ret;
}
