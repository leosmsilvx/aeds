#include <stdio.h>

int main() {
    int num, par = 0, impar = 0;

    for (int i = 0; i < 5; i++) {
        printf("Digite um numero: ");
        scanf("%d", &num);

        if (num % 2 == 0) {
            par++;
        } else {
            impar++;
        }
    }

    printf("Quantidade de numeros pares: %d\n", par);
    printf("Quantidade de numeros impares: %d\n", impar);

    return 0;
}
