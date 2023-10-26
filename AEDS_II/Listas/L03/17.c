#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct no {
  int valor;
  struct no* proximo;
};

void remove(struct no** lista, int valor) {
  if (*lista == NULL) {
    return;
  }

  struct no* anterior = NULL;
  struct no* atual = *lista;
  while (atual != NULL && atual->valor != valor) {
    anterior = atual;
    atual = atual->proximo;
  }

  if (atual == NULL) {
    return;
  }

  if (anterior == NULL) {
    *lista = atual->proximo;
  } else {
    anterior->proximo = atual->proximo;
  }

  free(atual);
}

int main() {
  struct no* lista = malloc(sizeof(struct no));
  lista->valor = 1;
  lista->proximo = malloc(sizeof(struct no));
  lista->proximo->valor = 3;
  lista->proximo->proximo = malloc(sizeof(struct no));
  lista->proximo->proximo->valor = 2;
  lista->proximo->proximo->proximo = NULL;

  remove(&lista, 3);

  struct no* no = lista;
  while (no != NULL) {
    printf("%d ", no->valor);
    no = no->proximo;
  }
  printf("\n");

  return 0;
}
