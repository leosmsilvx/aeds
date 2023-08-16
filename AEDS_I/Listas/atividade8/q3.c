#include <stdio.h>

void exibirOrdemCrescente(int a, int b, int c) {
    int temp;

    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }

    if (b > c) {
        temp = b;
        b = c;
        c = temp;

        if (a > b) {
            temp = a;
            a = b;
            b = temp;
        }
    }

    printf("%d, %d, %d\n", a, b, c);
}

int main() {
    int n, i;
    int valor1, valor2, valor3;

    printf("Digite o número de conjuntos: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Conjunto %d:\n", i);
        printf("Digite o primeiro valor: ");
        scanf("%d", &valor1);
        printf("Digite o segundo valor: ");
        scanf("%d", &valor2);
        printf("Digite o terceiro valor: ");
        scanf("%d", &valor3);

        printf("Valores em ordem crescente: ");
        exibirOrdemCrescente(valor1, valor2, valor3);
        printf("\n");
    }

    return 0;
}
