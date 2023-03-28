#ifndef _POINT_H_
#define _POINT_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    float x;
    float y;
} Point;

void riempiSequenza(Point *data, int size);
int coppieDistMinD(Point *data, int size, float minDist);
float distanza(Point data1, Point data2);
Point centroide(Point *data, int size);
float maxDistanza(Point *data, int size);
void sposta(Point *data, float dx, float dy);

#endif
