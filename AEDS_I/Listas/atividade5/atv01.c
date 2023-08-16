#include <stdio.h>

int main() {
    int tabela[4][5];
    int i, j, soma, soma_total = 0;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            printf("Digite o elemento da linha %d e coluna %d: ", i, j);
            scanf("%d", &tabela[i][j]);
        }
    }

    for (i = 0; i < 4; i++) {
        soma = 0;
        for (j = 0; j < 5; j++) {
            soma += tabela[i][j];
            soma_total += tabela[i][j];
        }
        printf("A soma da linha %d eh igual a %d\n", i, soma);
    }

    printf("A soma de todos os elementos eh %d\n", soma_total);

    return 0;
}
