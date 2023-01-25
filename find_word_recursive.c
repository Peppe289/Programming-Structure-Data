/*
 * Richiesta del programma:
 * Cercare una parola in una frase. 
 * 
 * Plus:
 * - frase in input. selezionabile alla compilazione
 * - Utilizzo della memoria dinamica
 * - Ricorsione
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Definisci un input manuale e una dimensione
 * della parola da cercare senza limiti di lunghezza
 * 
 * Commenta questo per l'uso statico del programma.
 */
#define INPUT

/* solo per l'input con la dimensione statica */
#define DIM 15

#define _skip_over(x) for (; frase[x] != ' ' && frase[x] != '\0'; x++)
#define _clear_buffer() do { } while (getchar() != '\n')

typedef enum bool
{
    false = 0,
    true = 1
} bool;

void cerca_parola(char *, char[], int *);

#ifdef INPUT
char *input(bool single);
#endif

int main()
{
#ifdef INPUT
    char *frase;
    char *search_word;
#else
    char frase[] = {"questa è una frase di esempio"};
    char search_word[DIM];
#endif
    int count_word = 0;

#ifdef INPUT
    printf("Inserisci la frase: ");
    frase = input(false);
#endif

    printf("\nInserisci parola da cercare: ");
#ifdef INPUT
    search_word = input(true);
#else
    scanf("%s", search_word);
#endif

    cerca_parola(frase, search_word, &count_word);
    printf("la parola '%s' è presente %d volta/e\n", search_word, count_word);

#ifdef INPUT
    free(frase);
    free(search_word);
#endif

    return 0;
}

#ifdef INPUT
char *input(bool single)
{
    char ch;
    int i = 0;
    char *ptr;

    ptr = malloc(sizeof(char));

    while (1)
    {
        ptr = realloc(ptr, (i + 1) * sizeof(char));

        if ((ch = getchar()) == '\n')
        {
            ptr[i] = '\0';
            break;
        }
        else if (single && (ch == ' '))
        {
            /*
             * Se dobbiamo caricare il vettore con una singola
             * parola, chiudiamo l'input dopo un eventuale spazio.
             * 
             * Per un'ulteriore sicurezza, usiamo la macro
             * _clear_buffer() per pulire il buffer che può contenere
             * valori dopo la fine dell'uso del getchar()
             * e l'interruzione allo spazio
             */
            ptr[i] = '\0';
            _clear_buffer();
            break;
        }
        ptr[i] = ch;
        ++i;
    }

    return ptr;
}
#endif

void cerca_parola(char *frase, char search_word[], int *count_w)
{
    int i = 0;
    char *temp;

    temp = calloc(strlen(frase) + 1, sizeof(char));

    // skippa lo spazio della parola precedente
    if (frase[i] == ' ')
        i += 1;

    /*
     * Indirizzo di i, con i = all'unltima cella con lo
     * spazio o fine stringa.
     *
     * Dopo di che taglia la stringa allo spazio.
     */
    strcpy(temp, &frase[i]);
    strtok(temp, " ");

#if 0
    printf("\n%s", temp);
#endif

    if (!strcmp(search_word, temp))
        (*count_w)++;

    free(temp);

    if (frase[i] != '\0')
    {
        // i = indice di inizio della nuova parola
        _skip_over(i);
        cerca_parola(&frase[i], search_word, count_w);
    }
}