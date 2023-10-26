#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct no {
  int valor;
  struct no* proximo;
};

void insere(struct no** lista, int valor) {
  struct no* novo = malloc(sizeof(struct no));
  novo->valor = valor;
  novo->proximo = NULL;

  struct no* atual = *lista;
  while (atual != NULL && novo->valor < atual->valor) {
    atual = atual->proximo;
  }

  if (atual == *lista) {
    novo->proximo = *lista;
    *lista = novo;
  } else {
    novo->proximo = atual->proximo;
    atual->proximo = novo;
  }
}

int main() {
  struct no* lista = NULL;

  insere(&lista, 3);
  insere(&lista, 2);
  insere(&lista, 1);

  struct no* no = lista;
  while (no != NULL) {
    printf("%d ", no->valor);
    no = no->proximo;
  }
  printf("\n");

  return 0;
}
