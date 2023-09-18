#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    double altura;
    double raio;
} Cilindro;

Cilindro criaCilindro(double altura, double raio) {
    Cilindro cilindro;
    cilindro.altura = altura;
    cilindro.raio = raio;
    return cilindro;
}

double tamAltura(Cilindro cilindro) {
    return cilindro.altura;
}

double tamRaio(Cilindro cilindro) {
    return cilindro.raio;
}

double tamArea(Cilindro cilindro) {
    double areaLateral = 2.0 * 3.14 * cilindro.raio * cilindro.altura;
    double areaBase = 3.14 * cilindro.raio * cilindro.raio;
    return areaLateral + (2.0 * areaBase);
}

double tamVolume(Cilindro cilindro) {
    return 3.14 * cilindro.raio * cilindro.raio * cilindro.altura;
}

int main() {
    Cilindro cil = criaCilindro(3.0, 1.0); 

    printf("Altura: %.2lf\n", tamAltura(cil));
    printf("Raio: %.2lf\n", tamRaio(cil));
    printf("Area: %.2lf\n", tamArea(cil));
    printf("Volume: %.2lf\n", tamVolume(cil));

    return 0;
}
