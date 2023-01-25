/*
 * Riproduci un algoritmo per il cifrario di Cesare:
 * 
 * Inserisci una frase e un chiave. Ogni singola lettera
 * deve essere spostata avanti seguendo la posizione dell'alfabeto:
 * 
 * Es:
 * @Frase: ciao come stai?      @Key: 2
 * Risultato:
 * @Frase: ekcq"eqog"uvckA
 * 
 * 
 * In questo caso le virgolette sono il prodotto
 * dello spostamento su alfabeto ASCII  
 */

#include <stdio.h>
#include <stdlib.h>

void cifratura(char input[], int key) {
    int i, k;

    /*
     * Il carattere che determina la fine dell'input corrisponde
     * al carattere '\n' preso in input con getchar() nel load dell'array.
     */
    for (i = 0; input[i] != '\0'; ++i) {
        /*
         * Lo shifting controllato in un for ci consente
         * di creare una cifratura su un alfabeto ciclico.
         */
        for (k = 0; k != key; ++k) {
            /*
             * Poiché la cifratura è ciclica, quando arriva alla
             * lettera finale dell'alfabeto riporta il valore
             * ASCII alla lettera iniziale.
             * 
             * Stiamo supponendo le lettere maiuscole e minuscole
             * come due alfabeti di lunghezza uguale.
             */
            if ((input[i]) == 'Z' || (input[i]) == 'z')
                input[i] = input[i] - ('Z' - 'A');
            else
                /*
                 * Se il valore non rappresenta la fine dell'alfabeto
                 * continua con lo shifting.
                 */
                input[i]++;
        }
    }

    printf("\nMessaggio cifrato : %s", input);
}

void decifratura(char input[], int key) {
    int i, k;

    for (i = 0; input[i] != '\0'; ++i) {
        for (k = 0; k != key; ++k) {
            /*
             * Seguendo la stessa logica effettua l'operazione
             * inversa di cifratura().
             */
            if ((input[i]) == 'A' || (input[i]) == 'a')
                input[i] = input[i] + ('Z' - 'A');
            else
                input[i]--;
        }
    }

    printf("\nMessaggio decifrato : %s\n", input);
}

int main () {

    char *input;
    int key;
    char ch;
    int load = 0;

    /*
     * Assegna una dimesione iniziale.
     */
    input = (char *)calloc(1, sizeof(char));

    printf("Inserisci il messaggio: ");
    do {
        /*
         * Gestiamo l'input come sequenza di caratteri
         * e non come stringa.
         * Ciò ci rende coerenti alla traccia nel trattare
         * la variabile come array e non come stringa.
         * 
         * Ci garantisce anche di poter inserire più parole
         * separati dallo spazio.
         */
        ch = getchar();

        /*
         * Assegna al vettore dinamico maggiore dimensione
         */
        input = (char *)realloc(input, (load + 1) * sizeof(char));

        *(input + load) = ch == '\n' ? '\0' : ch;

        load++;
        /*
         * Imponiamo '\n' come carattere di fine stringa.
         */
    } while (ch != '\n');

    printf("Inserisci la chiave di cifratura: ");
    scanf("%d", &key);

    cifratura(input, key);
    decifratura(input, key);

    free(input);
    return 0;
}
