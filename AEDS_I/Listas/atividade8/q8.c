#include <stdio.h>

void calcularS(int n) {
    float resultado = 0.0;
    int sinal = 1;

    for (int i = 1; i <= n; i++) {
        resultado += sinal * (1.0 / i);
        sinal *= -1;
    }

    printf("O valor de S é: %.4f\n", resultado);
}

int main() {
    int n;
    printf("Digite um valor inteiro e positivo para n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("O valor de n precisa ser positivo.\n");
    } else {
        calcularS(n);
    }

    return 0;
}
