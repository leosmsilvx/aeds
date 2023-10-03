#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pilha {
    char *itens;
    int topo;
    unsigned capacidade;
};

struct Pilha *criarPilha(unsigned capacidade) {
    struct Pilha *pilha = (struct Pilha *)malloc(sizeof(struct Pilha));
    pilha->capacidade = capacidade;
    pilha->topo = -1;
    pilha->itens = (char *)malloc(capacidade * sizeof(char));
    return pilha;
}

int estaVazia(struct Pilha *pilha) {
    return pilha->topo == -1;
}

void empilhar(struct Pilha *pilha, char caractere) {
    pilha->itens[++(pilha->topo)] = caractere;
}

char desempilhar(struct Pilha *pilha) {
    if (!estaVazia(pilha))
        return pilha->itens[pilha->topo--];
    return '0';
}

void inverterPalavras(char *texto) {
    int tamanho = strlen(texto);
    struct Pilha *pilha = criarPilha(tamanho);

    for (int i = 0; i < tamanho; i++) {
        if (texto[i] != ' ' && texto[i] != '.') {
            empilhar(pilha, texto[i]);
        } else {
            while (!estaVazia(pilha)) {
                printf("%c", desempilhar(pilha));
            }
            if (texto[i] == ' ') {
                printf(" ");
            } else {
                printf(".");
            }
        }
    }
}

int main() {
    char texto[] = "Leo a.";
    printf("Texto Invertido: ");
    inverterPalavras(texto);
    printf("\n");
    return 0;
}
