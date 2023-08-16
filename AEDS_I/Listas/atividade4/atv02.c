#include <stdio.h>

int main() {
    int arr[5];
    int menor = 0, posicao_menor = 0, temp;
    int i, j;

    printf("Digite os 5 elementos do arranjo:\n");
    for (i = 0; i < 5; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    menor = arr[0];
    for (i = 1; i < 5; i++) {
        if (arr[i] < menor) {
            menor = arr[i];
            posicao_menor = i;
        }
    }

    temp = arr[0];
    arr[0] = arr[posicao_menor];
    arr[posicao_menor] = temp;

    printf("Os elementos do arranjo apos a troca sao:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
