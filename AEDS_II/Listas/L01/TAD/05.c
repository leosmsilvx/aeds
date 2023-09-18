#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    double lado;
} Cubo;

Cubo criaCubo(double lado) {
    Cubo cubo;
    cubo.lado = lado;
    return cubo;
}

double tamLado(Cubo cubo) {
    return cubo.lado;
}

double tamArea(Cubo cubo) {
    return cubo.lado * cubo.lado * 6.0;
}

double tamVolume(Cubo cubo) {
    return pow(cubo.lado, 3.0);
}

int main() {
    Cubo cubo = criaCubo(2.0);

    printf("Lado: %.2lf\n", tamLado(cubo));
    printf("Area : %.2lf\n", tamArea(cubo));
    printf("Volume: %.2lf\n", tamVolume(cubo));

    return 0;
}