#include <stdio.h>

int main() {
    int arr[5];
    int i, maior, menor;
    float media, soma = 0;

    printf("Digite 5 numeros:\n");
    for (i = 0; i < 5; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    maior = arr[0];
    menor = arr[0];
    soma = arr[0];

    for (i = 1; i < 5; i++) {
        if (arr[i] > maior) {
            maior = arr[i];
        }
        if (arr[i] < menor) {
            menor = arr[i];
        }
        soma += arr[i];
    }

    media = soma / 5.0;

    printf("O maior valor armazenado no arranjo eh: %d\n", maior);
    printf("O menor valor armazenado no arranjo eh: %d\n", menor);
    printf("A media dos valores armazenados no arranjo eh: %.2f\n", media);

    return 0;
}
