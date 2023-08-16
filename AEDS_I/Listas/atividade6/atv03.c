#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int n, result;

    printf("Digite a primeira string: ");
    fgets(str1, 100, stdin);

    printf("Digite a segunda string: ");
    fgets(str2, 100, stdin);

    printf("Digite o numero de caracteres a serem comparados: ");
    scanf("%d", &n);

    result = strncmp(str1, str2, n);

    if (result == 0) {
        printf("As strings sao iguais nos primeiros %d caracteres.\n", n);
    } else {
        printf("As strings sao diferentes nos primeiros %d caracteres.\n", n);
        printf("O valor retornado pela comparação e: %d\n", result);
    }

    return 0;
}
