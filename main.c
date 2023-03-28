#include <stdio.h>
// libreria locale
#include <point.h>

static void output(Point *data, int size) {
    int i;

    for (i = 0; i != size; ++i) {
        printf("\nPunto %d\n", i + 1);
        printf("\tX : %f", data[i].x);
        printf("\n\tY : %f", data[i].y);
    }
}

static void shift(Point *data, int size) {
    int input;
    float dx, dy;
    do {
        printf("\nScegli il punto da spostare. (1 - %d) : ", size);
        scanf("%d", &input);
    } while(input < 1 || input > size);

    printf("Di quando vuoi spostare?");
    printf("\n\tX : ");
    scanf("%f", &dx);
    printf("\tY : ");
    scanf("%f", &dy);

    sposta(&data[input - 1], dx, dy);
}

int main() {
    Point *point;
    Point centroid;
    int size;
    float minDist;

    printf("Inserisci il numero di punti: ");
    scanf("%d", &size);

    point = (Point *)malloc(size * sizeof(Point));

    riempiSequenza(point, size);

    printf("Inserisci una distanza: ");
    scanf("%f", &minDist);

    printf("\nI numeri con questa disanza minima sono: %d",
            coppieDistMinD(point, size, minDist));

    centroid = centroide(point, size);

    printf("\nCentroide : %f - %f", centroid.x, centroid.y);

    printf("\nLa disanza massima e' : %f", maxDistanza(point, size));

    shift(point, size);
    output(point, size);

    free(point);

    return 0;
}
