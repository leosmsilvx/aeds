#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct no {
  int valor;
  struct no* anterior;
  struct no* proximo;
};

int busca(struct no* lista, int valor) {
  if (lista == NULL) {
    return -1;
  }

  struct no* atual = lista;
  int i = 0;
  while (atual != NULL && atual->valor != valor) {
    atual = atual->proximo;
    i++;
  }

  if (atual == NULL) {
    return -1;
  }

  return i;
}

int main() {
  struct no* lista = malloc(sizeof(struct no));
  lista->valor = 1;
  lista->proximo = malloc(sizeof(struct no));
  lista->proximo->valor = 3;
  lista->proximo->proximo = malloc(sizeof(struct no));
  lista->proximo->proximo->valor = 2;
  lista->proximo->proximo->proximo = NULL;

  int posicao = busca(lista, 3);

  printf("O elemento 3 está na posição %d.\n", posicao);

  return 0;
}
