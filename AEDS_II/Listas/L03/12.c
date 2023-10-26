#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct no {
  int valor;
  struct no* proximo;
};

struct no* criar_lista_encadeada(int* vetor, int tamanho) {
  struct no* primeiro = malloc(sizeof(struct no));
  primeiro->valor = vetor[0];
  primeiro->proximo = NULL;

  for (int i = 1; i < tamanho; i++) {
    struct no* novo = malloc(sizeof(struct no));
    novo->valor = vetor[i];
    novo->proximo = NULL;

    struct no* ultimo = primeiro;
    while (ultimo->proximo != NULL) {
      ultimo = ultimo->proximo;
    }
    ultimo->proximo = novo;
  }

  return primeiro;
}

int main() {
  int vetor[] = {1, 2, 3, 4, 5};
  int tamanho = sizeof(vetor) / sizeof(int);

  struct no* lista = criar_lista_encadeada(vetor, tamanho);

  struct no* no = lista;
  while (no != NULL) {
    printf("%d ", no->valor);
    no = no->proximo;
  }
  printf("\n");

  return 0;
}
