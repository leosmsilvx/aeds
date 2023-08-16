#include <stdio.h>

int fatorial(int num) {
    int resultado = 1;
    for (int i = 1; i <= num; i++) {
        resultado *= i;
    }
    return resultado;
}

void calcularE(int n) {
    float resultado = 1.0;
    for (int i = 1; i <= n; i++) {
        resultado += 1.0 / fatorial(i);
    }
    printf("O valor de E é: %.4f\n", resultado);
}

int main() {
    int n;
    printf("Digite um valor inteiro e positivo para n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("O valor de n precisa ser positivo.\n");
    } else {
        calcularE(n);
    }

    return 0;
}
