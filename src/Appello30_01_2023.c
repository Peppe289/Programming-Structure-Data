#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 10

// fix con lo shift
#define SHIFT_FIX

typedef struct
{
    char **nc;
    char **esami;
    int num_esami;
} studente;
void aggiungi_studente(studente *, int pos);
void aggiungi_esame(studente *, char *, char *, char *);
int annulla_esame(studente *, char *);
void stampa(studente *);

int main()
{
    studente *s = malloc(sizeof(studente) * M);
    aggiungi_studente(s, 0);
    aggiungi_studente(s, 1);
    aggiungi_studente(s, 2);
    aggiungi_esame(s, "Mario", "Rossi", "Matematica");
    aggiungi_esame(s, "Mario", "Rossi", "Programmazione");
    aggiungi_esame(s, "Mario", "Bianchi", "Programmazione");
    stampa(s); // implementazione non richiesta
    printf("\nAnnullo esame Programmazione\n");
    int k = annulla_esame(s, "Programmazione");
    printf("Studenti coinvolti: %d\n", k);
    stampa(s); // implementazione non richiesta
}

void aggiungi_studente(studente *s, int pos)
{
    s[pos].nc = malloc(sizeof(char *) * 2);
    s[pos].nc[0] = malloc(sizeof(char) * 20);
    s[pos].nc[1] = malloc(sizeof(char) * 20);
    s[pos].esami = malloc(sizeof(char *) * 30);
    s[pos].num_esami = 0;
    printf("Nome: ");
    scanf("%s", s[pos].nc[0]);
    printf("Cognome: ");
    scanf("%s", s[pos].nc[1]);
    return;
}
void aggiungi_esame(studente *s, char *n, char *c, char *e)
{
    for (int i = 0; i < M; i++)
    {
        if (s[i].nc != NULL)
        {
            if (strcmp(s[i].nc[0], n) == 0 && strcmp(s[i].nc[1], c) == 0)
            {
                s[i].esami[s[i].num_esami] = malloc(sizeof(char) * strlen(e));
                strcpy(s[i].esami[s[i].num_esami], e);
                s[i].num_esami++;
            }
        }
    }
}
int annulla_esame(studente *s, char *e)
{
    int k = 0;
    for (int i = 0; i < M; i++)
    {
        if (s[i].nc != NULL)
        {
            for (int j = 0; j < s[i].num_esami; j++)
            {
                if (strcmp(s[i].esami[j], e) == 0)
                {
                    strcpy(s[i].esami[j], "");
                    s[i].num_esami--;
                    k++;
#ifdef SHIFT_FIX
                    /**
                     * Dopo aver eliminato il valore e decrementato il numero
                     * di esami effettutati si creare un errore logico.
                     *
                     * Le iterazioni di input sono già state definite nel main,
                     * come anche i parametri da passare in annulla_esame() e aggiungi_esame()
                     *
                     * =========================================================================
                     * Scenario attuale:
                     *
                     * Se nella funzione aggiungi_studente() inseriamo due studenti
                     * di nome ["Mario", "Rossi"] e ["Mario", "Bianchi"] e in seguito
                     * con la funzione aggiungi_esame() viene attribuito a
                     * "Mario Rossi" l'esame di "Matematica" (indirizzo 0) e
                     * "Programmazione" (indirizzo 1) e a
                     * "Mario Bianchi" solo "Programmazione" (indirizzo 0),
                     * portando quindi il valore di (struct).num_esami a 2 per il primo e 1 per il secondo
                     *
                     * Esecuzione:
                     *
                     * Nella funzione annulla_esame() per entrambi l'esame "Programmazione" è presente all'ultima cella,
                     * data la cancellazione del valore viene anche decrementato il valore di (struct).num_esami.
                     * In questo scenario non viene evidenziato nessun problema, poiché i valori cancellati
                     * presenti all'ultima cella indicata come [(struct).num_esami - 1] (indice prima del decremento),
                     * non devono essere, e non verranno, considerati.
                     * =========================================================================
                     * Bug:
                     *
                     * Nel caso in cui i parametri cambiano, per esempio non è più "Programmazione" ad essere cancellato,
                     * ma "Matematica", per lo studente "Mario Rossi" accade:
                     *
                     * Input:
                     * (struct).esami[0] = "Matematica"
                     * (struct).esami[1] = "Programmazione"
                     * (struct).num_esami = 2;
                     *
                     *
                     * annulla_esame():
                     * (struct).esami[0] = ""
                     * (struct).esami[1] = "Programmazione"
                     * (struct).num_esami = 1;
                     *
                     * Nella funzione di stampa con condizione (..; x < s[i].num_esami; ..;) verranno
                     * visti solo gli indici [0, ..., (struct).num_esami - 1] ovvero solo l'indice [0] che oltretutto
                     * costituisce una stringa vuota.
                     *
                     * =========================================================================
                     *
                     * Ciò rende il codice "non universale". Tra le pillole di teoria che ci sono state insegnate,
                     * l'uso delle funzioni ci garantisce modulità e non ambiguità.
                     *
                     * Seguendo questa logica l'unico fix possibile, ma impensabile nei 45 minuti forniti
                     * nell'appello, era uno shift di indirizzi per togliere il valore ormai cancellato e recuperare
                     * il valore decrementato indicante l'indice.
                     *
                     * In alternativa possiamo non decrementare, ma ciò non resta coerente con la traccia:
                     * "num_esami è un campo intero che tiene traccia del numero di esami sostenuti".
                     *
                     * Tutte le altre soluzioni sono inefficienti.
                     */
                    int shift;
                    for (shift = j; shift != s[i].num_esami; ++shift)
                    {
                        // free(s[i].esami[shift]); // non necessario per risolvere il bug
                        s[i].esami[shift] = (char *)s[i].esami[shift + 1];
                    }
#endif
                }
            }
        }
    }
    return k;
}
void stampa(studente *s)
{
    for (int i = 0; i < M; i++)
    {
        if (s[i].nc != NULL)
        {
            printf("%s %s\n", *s[i].nc, *(s[i].nc + 1));
            for (int j = 0; j < s[i].num_esami; j++)
            {
                printf("%s ", s[i].esami[j]);
            }
            printf("\n");
        }
    }
}