#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    double raio;
} Esfera;

Esfera criaEsfera(double raio) {
    Esfera esfera;
    esfera.raio = raio;
    return esfera;
}

double tamRaio(Esfera esfera) {
    return esfera.raio;
}

double tamArea(Esfera esfera) {
    return 4.0 * 3.14 * esfera.raio * esfera.raio;
}

double tamVolume(Esfera esfera) {
    return (4.0 / 3.0) * 3.14 * esfera.raio * esfera.raio * esfera.raio;
}

int main() {
    Esfera esf = criaEsfera(5.0);

    printf("Raio: %.2lf\n", tamRaio(esf));
    printf("Area: %.2lf\n", tamArea(esf));
    printf("Volume: %.2lf\n", tamVolume(esf));

    return 0;
}
