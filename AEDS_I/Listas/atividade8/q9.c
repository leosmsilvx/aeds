#include <stdio.h>
#include <stdbool.h>

bool verificarPositivo(int valor) {
    if (valor > 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    printf("Digite o número de valores a verificar: ");
    scanf("%d", &n);

    int valor;
    for (int i = 1; i <= n; i++) {
        printf("Digite o valor %d: ", i);
        scanf("%d", &valor);

        if (verificarPositivo(valor)) {
            printf("%d é positivo.\n", valor);
        } else {
            printf("%d não é positivo.\n", valor);
        }
    }

    return 0;
}
