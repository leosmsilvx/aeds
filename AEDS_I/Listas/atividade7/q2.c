#include <stdio.h>

typedef struct bandas {
    char nome[255];
    char genero[255];
    int numIntegrantes;
    int ranking;
} Bandas;

int main() {
    Bandas bandas[5];

    for (int i = 0; i < 5; i++) {
        printf("Digite a banda %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", bandas[i].nome);
        printf("Gênero: ");
        scanf("%s", bandas[i].genero);
        printf("Número de integrantes: ");
        scanf("%d", &bandas[i].numIntegrantes);
        printf("Ranking (1-5): ");
        scanf("%d", &bandas[i].ranking);
    }

    int posicaoTopoRanking = 0;
    for (int i = 1; i < 5; i++) {
        if (bandas[i].ranking < bandas[posicaoTopoRanking].ranking) {
            posicaoTopoRanking = i;
        }
    }

    printf("\nBanda no topo do ranking:\n");
    printf("Nome: %s\n", bandas[posicaoTopoRanking].nome);
    printf("Gênero: %s\n", bandas[posicaoTopoRanking].genero);
    printf("Número de integrantes: %d\n", bandas[posicaoTopoRanking].numIntegrantes);
    printf("Ranking: %d\n", bandas[posicaoTopoRanking].ranking);

    return 0;
}
