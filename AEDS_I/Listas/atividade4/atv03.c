#include <stdio.h>

int main() {
    int arr1[5], arr2[5];
    int i;

    printf("Digite 5 numeros:\n");
    for (i = 0; i < 5; i++) {
        printf("arr1[%d] = ", i);
        scanf("%d", &arr1[i]);
    }

    for (i = 0; i < 5; i++) {
        arr2[i] = 3 * arr1[i];
    }

    printf("Os componentes do segundo arranjo (triplo do primeiro arranjo) sao:\n");
    for (i = 0; i < 5; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    return 0;
}
