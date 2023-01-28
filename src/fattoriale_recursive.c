/**
 * Algoritmo ricorsivo per il calcolo del fattoriale.
 */
#include <stdio.h>

/**
 * @input: numero utilizzato per il calcolo.
 * Il calcolo avviene dal maggiore al minore.
 *
 * @counter: numero utilizzato per tenere traccia
 * delle attivazioni delle funzioni.
 */
int recursive(int input, int counter)
{

    printf("Load %s (%d) Value : %d\n", __func__,
           counter, input);

    /**
     * Poiché decrementiamo il valore passato ogni
     * volta, quando arriva al valore 1 dobbiamo fermare
     * la funzione, senza effettuare il calcolo.
     *
     * Effettivamente la moltiplicazione per 1 non
     * effettua alcuna mofica al risultato.
     */
    if (input == 1)
        return input;

    /**
     * Moltiplica il prodotto precedente input successivo
     * e restituisci il prodotto alle funzioni superiori
     * per ripetere l'operazione logica.
     *
     * N.B. è necessario utilizzare ++counter anziché counter++
     * altrimenti il valore passato alla funzione non sarà
     * quello incrementato.
     */
    return input * recursive(input - 1, ++counter);
}

int main()
{
    int input;

    printf("Inserisci il numero da calcolare: ");
    scanf("%d", &input);

    printf("From %s. Result: %d\n", __func__,
           recursive(input, 1));

    return 0;
}