#include <stdio.h>

int main() {
    int a, b, c;

    printf("Digite o valor de A: ");
    scanf("%d", &a);
    printf("Digite o valor de B: ");
    scanf("%d", &b);

    c = a;
    a = b;
    b = c;

    printf("Os valores trocados sao: A = %d e B = %d\n", a, b);

    return 0;
}
