#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct carta {
    char valor[2];
    char naipe[10];
    int distribuida;
} Carta;

int main(){
    Carta jogador1[5], jogador2[5];

    Carta baralho[52];
    char naipes[4][10] = {"Paus", "Ouros", "Copas", "Espadas"};
    char valores[13][2] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};

    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 13; j++) {
            strcpy(baralho[i*13+j].naipe, naipes[i]);
            strcpy(baralho[i*13+j].valor, valores[j]);
            baralho[i*13+j].distribuida = 0;
        }
    }

    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        int rNum;
        do {
            rNum = rand() % 52;
        } while (baralho[rNum].distribuida == 1);
        jogador1[i] = baralho[rNum];
        baralho[rNum].distribuida = 1;

        do {
            rNum = rand() % 52;
        } while (baralho[rNum].distribuida == 1);
        jogador2[i] = baralho[rNum];
        baralho[rNum].distribuida = 1;
    }

    printf("\n-=-=-=-=-=-=-=-\nCartas do Jogador 1:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s de %s\n", jogador1[i].valor, jogador1[i].naipe);
    }

    printf("\n\n-=-=-=-=-=-=-=-\n\nCartas do Jogador 2:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s de %s\n", jogador2[i].valor, jogador2[i].naipe);
    }

    return 0;
}