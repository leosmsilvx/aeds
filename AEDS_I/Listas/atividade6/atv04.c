#include <stdio.h>
#include <string.h>

int main() {
    char nome[50], sobrenome[50], nome_completo[100];

    printf("Digite o nome: ");
    scanf("%s", nome);

    printf("Digite o sobrenome: ");
    scanf("%s", sobrenome);

    strcpy(nome_completo, nome);
    strcat(nome_completo, " ");
    strcat(nome_completo, sobrenome);

    printf("Nome completo: %s\n", nome_completo);
    printf("Numero de caracteres: %d\n", strlen(nome_completo));
    printf("Primeira letra: %c\n", nome_completo[0]);
    printf("Ultima letra: %c\n", nome_completo[strlen(nome_completo) - 1]);

    return 0;
}
