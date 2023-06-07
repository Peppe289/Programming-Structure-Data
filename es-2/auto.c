#include <stdio.h>
#include <string.h>
#include "auto.h"
#include "item.h"
#include <stdlib.h>

struct automobile {
    char *targa;
    char *modello;
    int prod;
    int immatric;
};

Auto newAuto(char data[4][50]) {
    Auto ret;
    ret = malloc(sizeof(struct automobile));

    ret->targa = malloc(sizeof(char) * strlen(data[0]) + 1);
    ret->modello = malloc(sizeof(char) * strlen(data[1]) + 1);

    strcpy(ret->targa, data[0]) ;
    strcpy(ret->modello, data[1]);
    ret->prod = atoi(data[2]);
    ret->immatric = atoi(data[3]);

    return ret;
}

char *getTarga(Auto data) {
    return data->targa;
}

char *getModello(Auto data) {
    return data->modello;
}

int getProd(Auto data) {
    return data->prod;
}

int getImm(Auto data) {
    return data->immatric;
}
