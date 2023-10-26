#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct no {
  int valor;
  struct no* proximo;
  struct no* anterior;
};

void insere(struct no** lista, int valor) {
  struct no* novo = malloc(sizeof(struct no));
  novo->valor = valor;
  novo->proximo = NULL;
  novo->anterior = NULL;

  struct no* atual = *lista;
  while (atual != NULL && novo->valor < atual->valor) {
    atual = atual->proximo;
  }

  if (atual == *lista) {
    novo->proximo = *lista;
    *lista = novo;
  } else {
    novo->proximo = atual;
    novo->anterior = atual->anterior;
    atual->anterior->proximo = novo;
    atual->anterior = novo;
  }
}

void insere_de_duas_listas(struct no** lista_resultado, struct no* lista_encadeada, int* lista_estatica, int tamanho_lista_estatica) {
  struct no* no_encadeado = lista_encadeada;
  while (no_encadeado != NULL) {
    insere(lista_resultado, no_encadeado->valor);
    no_encadeado = no_encadeado->proximo;
  }

  for (int i = 0; i < tamanho_lista_estatica; i++) {
    insere(lista_resultado, lista_estatica[i]);
  }
}

int main() {
  struct no* lista_encadeada = NULL;

  insere(&lista_encadeada, 3);
  insere(&lista_encadeada, 2);
  insere(&lista_encadeada, 1);

  int lista_estatica[] = {5, 4, 6};

  struct no* lista_resultado = NULL;

  insere_de_duas_listas(&lista_resultado, lista_encadeada, lista_estatica, sizeof(lista_estatica) / sizeof(int));

  struct no* no = lista_resultado;
  while (no != NULL) {
    printf("%d ", no->valor);
    no = no->proximo;
  }
  printf("\n");

  return 0;
}
