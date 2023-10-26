#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct lista {
  int tamanho;
  int itens;
  int *dados;
};

struct lista *criar_lista(int tamanho) {
  struct lista *lista = malloc(sizeof(struct lista));
  lista->tamanho = tamanho;
  lista->itens = 0;
  lista->dados = malloc(tamanho * sizeof(int));
  return lista;
}

void liberar_lista(struct lista *lista) {
  free(lista->dados);
  free(lista);
}

int lista_cheia(struct lista *lista) {
  return (lista->itens == lista->tamanho);
}

int lista_vazia(struct lista *lista) {
  return (lista->itens == 0);
}

void inserir_final(struct lista *lista, int item) {
  if (!lista_cheia(lista)) {
    lista->dados[lista->itens] = item;
    lista->itens++;
  }
}

void inserir_posicao(struct lista *lista, int item, int posicao) {
  if (!lista_cheia(lista) && posicao >= 0 && posicao <= lista->itens) {
    for (int i = lista->itens; i > posicao; i--) {
      lista->dados[i] = lista->dados[i - 1];
    }
    lista->dados[posicao] = item;
    lista->itens++;
  }
}

void remover_final(struct lista *lista) {
  if (!lista_vazia(lista)) {
    lista->itens--;
  }
}

int recuperar_chave(struct lista *lista, int chave) {
  for (int i = 0; i < lista->itens; i++) {
    if (lista->dados[i] == chave) {
      return lista->dados[i];
    }
  }
  return -1;
}

int recuperar_posicao(struct lista *lista, int posicao) {
  if (posicao >= 0 && posicao < lista->itens) {
    return lista->dados[posicao];
  }
  return -1;
}

int contar_itens(struct lista *lista) {
  return lista->itens;
}

void imprimir_lista(struct lista *lista) {
  for (int i = 0; i < lista->itens; i++) {
    printf("%d ", lista->dados[i]);
  }
  printf("\n");
}

int main() {
  struct lista *lista = criar_lista(10);

  inserir_final(lista, 1);
  inserir_final(lista, 2);
  inserir_final(lista, 3);

  printf("Tamanho da lista: %d\n", contar_itens(lista));

  printf("Item da posição 0: %d\n", recuperar_posicao(lista, 0));
  printf("Item da chave 2: %d\n", recuperar_chave(lista, 2));

  remover_final(lista);

  imprimir_lista(lista);

  liberar_lista(lista);

  return 0;
}