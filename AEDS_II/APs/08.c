#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct no {
  int item;
  struct no *proximo;
};

struct lista {
  struct no *inicio;
  struct no *fim;
};

struct lista *criar_lista() {
  struct lista *lista = malloc(sizeof(struct lista));
  lista->inicio = NULL;
  lista->fim = NULL;
  return lista;
}

void liberar_lista(struct lista *lista) {
  struct no *no = lista->inicio;
  while (no != NULL) {
    struct no *proximo = no->proximo;
    free(no);
    no = proximo;
  }
  free(lista);
}

int contar_itens(struct lista *lista) {
  int contador = 0;
  struct no *no = lista->inicio;
  while (no != NULL) {
    contador++;
    no = no->proximo;
  }
  return contador;
}

int lista_cheia(struct lista *lista) {
  return false;
}

int lista_vazia(struct lista *lista) {
  return lista->inicio == NULL;
}

void inserir_inicio(struct lista *lista, int item) {
  struct no *novo = malloc(sizeof(struct no));
  novo->item = item;
  novo->proximo = lista->inicio;
  lista->inicio = novo;

  if (lista->fim == NULL) {
    lista->fim = novo;
  }
}

void inserir_final(struct lista *lista, int item) {
  struct no *novo = malloc(sizeof(struct no));
  novo->item = item;
  novo->proximo = NULL;

  if (lista_vazia(lista)) {
    lista->inicio = novo;
    lista->fim = novo;
  } else {
    lista->fim->proximo = novo;
    lista->fim = novo;
  }
}

void inserir_posicao(struct lista *lista, int item, int posicao) {
  if (posicao < 0 || posicao > contar_itens(lista)) {
    return;
  }

  if (posicao == 0) {
    inserir_inicio(lista, item);
    return;
  }

  struct no *anterior = lista->inicio;
  for (int i = 1; i < posicao; i++) {
    anterior = anterior->proximo;
  }

  struct no *novo = malloc(sizeof(struct no));
  novo->item = item;
  novo->proximo = anterior->proximo;
  anterior->proximo = novo;
}

void remover_inicio(struct lista *lista) {
  if (lista_vazia(lista)) {
    return;
  }

  struct no *no = lista->inicio;
  lista->inicio = lista->inicio->proximo;

  if (lista->inicio == NULL) {
    lista->fim = NULL;
  }

  free(no);
}

void remover_final(struct lista *lista) {
  if (lista_vazia(lista)) {
    return;
  }

  struct no *no = lista->fim;
  if (lista->inicio == lista->fim) {
    lista->inicio = NULL;
  } else {
    struct no *anterior = lista->inicio;
    while (anterior->proximo != lista->fim) {
      anterior = anterior->proximo;
    }
    lista->fim = anterior;
    lista->fim->proximo = NULL;
  }

  free(no);
}

void remover_posicao(struct lista *lista, int posicao) {
  if (posicao < 0 || posicao >= contar_itens(lista)) {
    return;
  }

  if (posicao == 0) {
    remover_inicio(lista);
    return;
  }

  struct no *anterior = lista->inicio;
  for (int i = 1; i < posicao; i++) {
    anterior = anterior->proximo;
  }

  struct no *no = anterior->proximo;
  anterior->proximo = no->proximo;

  if (no == lista->fim) {
    lista->fim = anterior;
  }

  free(no);
}

int recuperar_chave(struct lista *lista, int chave) {
  struct no *no = lista->inicio;
  while (no != NULL) {
    if (no->item == chave) {
      return no->item;
    }
    no = no->proximo;
  }
  return -1;
}

int recuperar_posicao(struct lista *lista, int posicao) {
  if (posicao < 0 || posicao >= contar_itens(lista)) {
    return -1;
  }

  struct no *no = lista->inicio;
  for (int i = 0; i < posicao; i++) {
    no = no->proximo;
  }
  return no->item;
}

void imprimir_lista(struct lista *lista) {
  struct no *no = lista->inicio;
  while (no != NULL) {
    printf("%d ", no->item);
    no = no->proximo;
  }
  printf("\n");
}

int main() {
  struct lista *lista = criar_lista();

  inserir_final(lista, 1);
  inserir_final(lista, 2);
  inserir_final(lista, 3);

  printf("Tamanho da lista: %d\n", contar_itens(lista));

  printf("Item da posicao 0: %d\n", recuperar_posicao(lista, 0));
  printf("Item da chave 2: %d\n", recuperar_chave(lista, 2));

  remover_final(lista);

  imprimir_lista(lista);

  liberar_lista(lista);

  return 0;
}