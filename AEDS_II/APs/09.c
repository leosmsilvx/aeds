#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct no {
  int chave;
  struct no *ant;
  struct no *prox;
} No;

typedef struct lista {
  No *ini;
  No *fim;
} Lista;

Lista *criar_lista() {
  Lista *lista = malloc(sizeof(Lista));
  lista->ini = NULL;
  lista->fim = NULL;
  return lista;
}

int lista_vazia(Lista *lista) {
  return lista->ini == NULL;
}

int lista_tamanho(Lista *lista) {
  if (lista_vazia(lista)) {
    return 0;
  }

  int tamanho = 0;

  No *no_atual = lista->ini;

  while (no_atual != NULL) {
    tamanho++;
    no_atual = no_atual->prox;
  }

  return tamanho;
}

void inserir_no_inicio(Lista *lista, int chave) {
  No *no_novo = malloc(sizeof(No));

  no_novo->chave = chave;
  no_novo->prox = lista->ini;

  if (lista->ini != NULL) {
    lista->ini->ant = no_novo;
  }

  lista->ini = no_novo;

  if (lista->fim == NULL) {
    lista->fim = no_novo;
  }
}

void inserir_no_final(Lista *lista, int chave) {
  No *novo_no = malloc(sizeof(No));
  novo_no->chave = chave;
  novo_no->ant = lista->fim;
  novo_no->prox = NULL;

  if (lista->fim != NULL) {
    lista->fim->prox = novo_no;
  }

  lista->fim = novo_no;

  if (lista->ini == NULL) {
    lista->ini = novo_no;
  }
}

void inserir_item_por_posicao(Lista *lista, int chave, int posicao) {
  if (lista_vazia(lista)) {
    inserir_no_inicio(lista, chave);
    return;
  }

  if (posicao < 0 || posicao > lista_tamanho(lista)) {
    printf("Posição inválida.\n");
    return;
  }

  No *no_anterior = lista->ini;

  for (int i = 0; i < posicao - 1; i++) {
    no_anterior = no_anterior->prox;
  }

  No *novo_no = malloc(sizeof(No));
  novo_no->chave = chave;
  novo_no->ant = no_anterior;
  novo_no->prox = no_anterior->prox;

  no_anterior->prox->ant = novo_no;
  no_anterior->prox = novo_no;
}


int remover_no_inicio(Lista *lista) {
  if (lista_vazia(lista)) {
    return -1;
  }

  No *no_removido = (No *) malloc(sizeof(No));
  no_removido = lista->ini;

  lista->ini = lista->ini->prox;

  if (lista->ini == NULL) {
    lista->fim = NULL;
  } else {
    lista->ini->ant = NULL;
  }

  free(no_removido);
  return no_removido->chave;
}

int remover_no_final(Lista *lista) {
  if (lista_vazia(lista)) {
    return -1;
  }

  No *no_removido = (No *) malloc(sizeof(No));
  no_removido = lista->fim;

  if (lista->ini == lista->fim) {
    lista->ini = NULL;
    lista->fim = NULL;
  } else {
    lista->fim = lista->fim->ant;
    lista->fim->prox = NULL;
  }

  free(no_removido);
  return no_removido->chave;
}

int remover_item_por_posicao(Lista *lista, int posicao) {
  if (lista_vazia(lista)) {
    return -1;
  }

  if (posicao < 1 || posicao > lista_tamanho(lista)) {
    return -1;
  }

  No *no_atual = (No *) malloc(sizeof(No));
  no_atual = lista->ini;

  for (int i = 0; i < posicao - 1; i++) {
    no_atual = no_atual->prox;
  }

  int chave_removida = no_atual->chave;

  if (no_atual == lista->ini) {
    remover_no_inicio(lista);
  } else if (no_atual == lista->fim) {
    remover_no_final(lista);  
  } else {
    no_atual->ant->prox = no_atual->prox;
    no_atual->prox->ant = no_atual->ant;   
    free(no_atual);
  }

  return chave_removida;
}

No *recuperar_item_por_chave(Lista *lista, int chave) {
  if (lista_vazia(lista)) {
    return NULL;
  }

  No *no_atual = lista->ini;

  while (no_atual != NULL && no_atual->chave != chave) {
    no_atual = no_atual->prox;
  }

  return no_atual;
}

No *recuperar_item_por_posicao(Lista *lista, int posicao) {
  if (lista_vazia(lista)) {
    return NULL;
  }

  if (posicao < 0 || posicao > lista_tamanho(lista)) {
    return NULL;
  }

  No *no_atual = lista->ini;

  for (int i = 0; i < posicao; i++) {
    no_atual = no_atual->prox;
  }

  return no_atual;
}


void imprimir_lista(Lista *lista) {
  if (lista_vazia(lista)) {
    return;
  }

  No *no_atual = lista->ini;

  while (no_atual != NULL) {
    printf("%d\n", no_atual->chave);
    no_atual = no_atual->prox;
  }
}

void liberar_lista(Lista *lista) {
  while (!lista_vazia(lista)) {
    remover_no_inicio(lista);
  }

  free(lista);
}

int main() {
  Lista *lista = criar_lista();

  inserir_no_inicio(lista, 1);
  inserir_no_inicio(lista, 2);
  inserir_no_inicio(lista, 3);

  imprimir_lista(lista);  

  No *no_encontrado = recuperar_item_por_chave(lista, 2);
  if (no_encontrado != NULL) {
    printf("Chave encontrada: %d\n", no_encontrado->chave);
  }

  int chave_removida = remover_item_por_posicao(lista, 0);
  printf("Chave removida: %d\n", chave_removida);

  imprimir_lista(lista);

  liberar_lista(lista);

  return 0;
}










