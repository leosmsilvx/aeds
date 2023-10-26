#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct no {
  int valor;
  struct no* proximo;
};

void inverter_lista_encadeada(struct no* lista) {
  if (lista == NULL || lista->proximo == NULL) {
    return;
  }

  struct no* meio = lista->proximo;

  struct no* ultimo_da_primeira_metade = lista;
  while (ultimo_da_primeira_metade->proximo != NULL) {
    ultimo_da_primeira_metade = ultimo_da_primeira_metade->proximo;
  }

  struct no* primeiro_da_segunda_metade = meio->proximo;

  while (lista != ultimo_da_primeira_metade) {
    lista->proximo = primeiro_da_segunda_metade;
    primeiro_da_segunda_metade = primeiro_da_segunda_metade->proximo;
    lista = lista->proximo;
  }

  meio->proximo = NULL;
  ultimo_da_primeira_metade->proximo = meio;
}

int main() {
  struct no* lista = malloc(sizeof(struct no));
  lista->valor = 1;
  lista->proximo = malloc(sizeof(struct no));
  lista->proximo->valor = 2;
  lista->proximo->proximo = malloc(sizeof(struct no));
  lista->proximo->proximo->valor = 3;
  lista->proximo->proximo->proximo = NULL;

  struct no* no = lista;
  while (no != NULL) {
    printf("%d ", no->valor);
    no = no->proximo;
  }
  printf("\n");

  inverter_lista_encadeada(lista);

  no = lista;
  while (no != NULL) {
    printf("%d ", no->valor);
    no = no->proximo;
  }
  printf("\n");

  return 0;
}
