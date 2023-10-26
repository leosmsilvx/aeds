#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void inverter_lista(int* lista1, int* lista2, int tamanho) {
  int* ponteiro_lista2 = lista2;

  for (int i = tamanho - 1; i >= 0; i--) {
    *ponteiro_lista2++ = lista1[i];
  }
}

int main() {
  int tamanho = 5;
  int lista1[5] = {1, 2, 3, 4, 5};

  int lista2[5];

  inverter_lista(lista1, lista2, tamanho);

  for (int i = 0; i < tamanho; i++) {
    printf("%d ", lista2[i]);
  }
  printf("\n");

  return 0;
}
