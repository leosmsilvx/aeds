#include <stdio.h>

void verificarTriangulo(float x, float y, float z) {
    if (x + y > z && x + z > y && y + z > x) {
        if (x == y && y == z) {
            printf("Triângulo equilátero\n");
        } else if (x == y || x == z || y == z) {
            printf("Triângulo isósceles\n");
        } else {
            printf("Triângulo escaleno\n");
        }
    } else {
        printf("Os valores não formam um triângulo\n");
    }
}

int main() {
    float x, y, z;

    printf("Digite o valor de X: ");
    scanf("%f", &x);
    printf("Digite o valor de Y: ");
    scanf("%f", &y);
    printf("Digite o valor de Z: ");
    scanf("%f", &z);

    verificarTriangulo(x, y, z);

    return 0;
}
