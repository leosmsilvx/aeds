#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct lista {
  int tamanho;
  int elementos[10];
};

void insere(struct lista* lista, int valor) {
  if (lista->tamanho == 10) {
    printf("A lista está cheia.\n");
    return;
  }

  int i = 0;
  while (i < lista->tamanho && lista->elementos[i] < valor) {
    i++;
  }

  for (int j = lista->tamanho - 1; j >= i; j--) {
    lista->elementos[j + 1] = lista->elementos[j];
  }
  lista->elementos[i] = valor;
  lista->tamanho++;
}

int main() {
  struct lista lista = {0, {0}};

  insere(&lista, 1);
  insere(&lista, 3);
  insere(&lista, 2);

  for (int i = 0; i < lista.tamanho; i++) {
    printf("%d ", lista.elementos[i]);
  }
  printf("\n");

  return 0;
}
