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
     *
     * Fermiamo i calcoli anche se il valore è minore di 1.
     * Nel main() se il valore inserito è negativo lo
     * rendiamo positivo, quindi escludiamo come corretto
     * input un valore negativo o uguale a 0. In questo modo
     * ritorniamo lo stesso risultato dell'input senza
     * creare errore nel codice.
     */
    if (input <= 1)
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
    short int flag = 1;

    printf("Inserisci il numero da calcolare: ");
    scanf("%d", &input);

    /**
     * Se il valore è negativo rendilo positivo
     * ricordalo per l'output
     */
    if (input < 0)
    {
        flag = 0;
        input = -input;
    }

    printf("From %s. Result: %d\n", __func__,
           flag ? recursive(input, 1) : -recursive(input, 1));

    return 0;
}