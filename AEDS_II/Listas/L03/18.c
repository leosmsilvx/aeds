#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct lista {
  int tamanho;
  int elementos[10];
};

void remove(struct lista* lista, int valor) {
  int i = 0;
  while (i < lista->tamanho && lista->elementos[i] != valor) {
    i++;
  }

  if (i == lista->tamanho) {
    return;
  }

  for (int j = i; j < lista->tamanho - 1; j++) {
    lista->elementos[j] = lista->elementos[j + 1];
  }

  lista->tamanho--;
}

int main() {
  struct lista lista = {0, {1, 3, 2, 5, 6, 7, 8, 9, 10}};

  remove(&lista, 3);

  for (int i = 0; i < lista.tamanho; i++) {
    printf("%d ", lista.elementos[i]);
  }
  printf("\n");

  return 0;
}
