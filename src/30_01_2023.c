// soluzione by @Peppe289

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 10

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

void aggiungi_studente(studente *studenti, int pos)
{
    // crea l'array per inserire nome e cognome
    studenti[pos].nc = malloc(2 * sizeof(char *));

    // nome e cognome
    studenti[pos].nc[0] = malloc(20 * sizeof(char));
    studenti[pos].nc[1] = malloc(20 * sizeof(char));

    printf("Inserisci il nome: ");
    scanf("%s", studenti[pos].nc[0]);

    printf("Inserisci il cognome: ");
    scanf("%s", studenti[pos].nc[1]);
    // crea celle vuote
    studenti[pos].esami = calloc(30, sizeof(char *));
    // inizializza a 0
    studenti[pos].num_esami = 0;
}

void aggiungi_esame(studente *studenti, char *nome, char *cognome, char *esame)
{
    int i;
    int pos;

    for (i = 0; i != M; ++i)
    {
        if (studenti[i].nc == NULL)
            continue;

        if (!strcmp(studenti[i].nc[0], nome) &&
            !strcmp(studenti[i].nc[1], cognome))
        {
            pos = studenti[i].num_esami;
            studenti[i].esami[pos] = calloc(strlen(esame) + 1, sizeof(char));
            strcpy(studenti[i].esami[pos], esame);
            studenti[i].num_esami++;
        }
    }
}

int annulla_esame(studente *studenti, char *esame)
{
    int ret = 0;
    int i, k;

    for (i = 0; i != M; ++i)
    {
        if (studenti[i].nc == NULL)
            continue;

        for (k = 0; k != studenti[i].num_esami && k < 30; ++k)
        {
            if (!strcmp(studenti[i].esami[k], esame))
            {
                free(studenti[i].esami[k]);
                studenti[i].esami[k] = NULL;
                ret++;
            }
        }
    }

    return ret;
}

void stampa(studente *s)
{
    for (int i = 0; i < M; i++)
    {
        if (s[i].nc == NULL)
            continue;

        printf("Libretto di : %s %s\n", *s[i].nc, *(s[i].nc + 1));
        for (int j = 0; j < s[i].num_esami; j++)
        {
            // if (s[i].esami[j] != NULL)
            printf("\t%s ", s[i].esami[j]);
        }
        printf("\n");
    }
}