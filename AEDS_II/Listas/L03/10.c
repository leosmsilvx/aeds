#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void copiar_lista_sem_repetidos(int* lista1, int* lista2, int tamanho) {
  int* ponteiro_lista2 = lista2;

  for (int i = 0; i < tamanho; i++) {
    bool existe = false;
    for (int j = 0; j < i; j++) {
      if (lista1[i] == lista2[j]) {
        existe = true;
        break;
      }
    }

    if (!existe) {
      *ponteiro_lista2++ = lista1[i];
    }
  }
}

int main() {
  int tamanho = 7;
  int lista1[7] = {1, 2, 3, 2, 4, 1, 5};

  int lista2[7];

  copiar_lista_sem_repetidos(lista1, lista2, tamanho);

  for (int i = 0; i < tamanho; i++) {
    printf("%d ", lista2[i]);
  }
  printf("\n");

  return 0;
}
