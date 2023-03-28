#include <point.h>
#include <math.h>

// carica le coordinate dei punti.
void riempiSequenza(Point *data, int size) {
    int i;

    for (i = 0; i != size; ++i) {
        printf("Punto %d\n", i + 1);
        printf("\tX : ");
        scanf("%f", &data[i].x);
        printf("\tY : ");
        scanf("%f", &data[i].y);
    }
}

/**
 * Calcola la quantità di punti minori di quella distanza
 */
int coppieDistMinD(Point *data, int size, float minDist) {
    int i, j, cont = 0;
    float d;

    for (i = 0; i != size - 1; ++i) {
        for (j = i + 1; j < size; ++j) {
            d = distanza(data[i], data[j]);
            if(d <= minDist)
                cont++;
        }
    }

    return cont;
}

// calcola la distanza tra due punti nel piano
float distanza(Point data1, Point data2) {
    float ret = sqrtf(powf(data1.x - data2.x, 2) + powf(data1.y - data2.y, 2));
    //printf("\n%s : %f", __func__, ret);
    return ret;
}

Point centroide(Point *data, int size) {
    int i;
    Point ret;
    float sumx = 0, sumy = 0; 

    for (i = 0; i != size; ++i) {
        sumx += data[i].x;
        sumy += data[i].y;
    }

    sumx /= size;
    sumy /= size;

    ret.x = sumx;
    ret.y = sumy;

    return ret;
}

float maxDistanza(Point *data, int size) {
    int i, j;
    float max = 0, d;

    for (i = 0; i != size - 1; i++) {
        for (j = i + 1; j != size; ++j) {
            d = distanza(data[i], data[j]);
            if (d >= max)
                max = d;
        }
    }

    return max;
}

void sposta(Point *data, float dx, float dy) {
    data->x += dx;
    data->y += dy;
}