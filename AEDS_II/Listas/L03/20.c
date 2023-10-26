#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct no {
  int valor;
  struct no* proximo;
};

int tamanho(struct no* lista) {
  if (lista == NULL) {
    return 0;
  }

  return 1 + tamanho(lista->proximo);
}

int main() {
  struct no* lista = malloc(sizeof(struct no));
  lista->valor = 1;
  lista->proximo = malloc(sizeof(struct no));
  lista->proximo->valor = 3;
  lista->proximo->proximo = malloc(sizeof(struct no));
  lista->proximo->proximo->valor = 2;
  lista->proximo->proximo->proximo = NULL;

  int tamanho_lista = tamanho(lista);

  printf("O tamanho da lista é %d.\n", tamanho_lista);

  return 0;
}
