#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int* filtrar_pares(int* lista, int tamanho) {
  int* lista_pares = lista;

  for (int i = 0; i < tamanho; i++) {
    if (lista[i] % 2 == 0) {
      lista_pares++;
    }
  }

  return lista_pares;
}

int main() {
  int lista[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int tamanho = sizeof(lista) / sizeof(int);

  for (int i = 0; i < tamanho; i++) {
    printf("%d ", lista[i]);
  }
  printf("\n");

  int* lista_pares = filtrar_pares(lista, tamanho);

  for (int i = 0; i < tamanho; i++) {
    printf("%d ", lista_pares[i]);
  }
  printf("\n");

  return 0;
}
