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