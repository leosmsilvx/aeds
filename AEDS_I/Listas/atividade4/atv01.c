#include <stdio.h>

int main() {
    int a[5], b[5], produto_escalar = 0;
    int i;

    printf("Digite os elementos do arranjo A:\n");
    for (i = 0; i < 5; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    printf("Digite os elementos do arranjo B:\n");
    for (i = 0; i < 5; i++) {
        printf("b[%d] = ", i);
        scanf("%d", &b[i]);
    }

    for (i = 0; i < 5; i++) {
        produto_escalar += a[i] * b[i];
    }

    printf("O produto escalar de A por B eh: %d\n", produto_escalar);

    return 0;
}
