#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct filme {
  char titulo[50];
  int ano;
};

struct no {
  struct filme* filme;
  struct no* proximo;
};

void insere_final(struct no** lista, struct filme* filme) {
  struct no* novo = malloc(sizeof(struct no));
  novo->filme = filme;
  novo->proximo = NULL;

  if (*lista == NULL) {
    *lista = novo;
  } else {
    struct no* atual = *lista;
    while (atual->proximo != NULL) {
      atual = atual->proximo;
    }

    atual->proximo = novo;
  }
}

void insere_posicao(struct no** lista, struct filme* filme, int posicao) {
  if (posicao < 0 || posicao > tamanho(*lista)) {
    return;
  }

  if (posicao == 0) {
    insere_final(lista, filme);
    return;
  }

  struct no* novo = malloc(sizeof(struct no));
  novo->filme = filme;

  struct no* atual = *lista;
  for (int i = 0; i < posicao - 1; i++) {
    atual = atual->proximo;
  }

  novo->proximo = atual->proximo;
  atual->proximo = novo;
}

void remove(struct no** lista, char* titulo) {
  struct no* atual = *lista;
  struct no* anterior = NULL;
  while (atual != NULL && strcmp(atual->filme->titulo, titulo) != 0) {
    anterior = atual;
    atual = atual->proximo;
  }

  if (atual == NULL) {
    return;
  }

  if (anterior == NULL) {
    *lista = atual->proximo;
  } else {
    anterior->proximo = atual->proximo;
  }

  free(atual);
}

void remove_posicao(struct no** lista, int posicao) {
  if (posicao < 0 || posicao >= tamanho(*lista)) {
    return;
  }

  if (posicao == 0) {
    struct no* removido = *lista;
    *lista = removido->proximo;
    free(removido);
    return;
  }

  struct no* atual = *lista;
  for (int i = 0; i < posicao - 1; i++) {
    atual = atual->proximo;
  }

  struct no* removido = atual->proximo;
  atual->proximo = removido->proximo;
  free(removido);
}

int pesquisa(struct no* lista, char* titulo) {
  struct no* atual = lista;
  while (atual != NULL && strcmp(atual->filme->titulo, titulo) != 0) {
    atual = atual->proximo;
  }

  if (atual == NULL) {
    return -1;
  }

  return atual->filme->ano;
}

void listar(struct no* lista) {
  struct no* atual = lista;
  while (atual != NULL) {
    printf("Titulo: %s, Ano: %d\n", atual->filme->titulo, atual->filme->ano);
    atual = atual->proximo;
  }
}

void inverte(struct no** lista) {
  if (*lista == NULL) {
    return;
  }

  struct no* lista_auxiliar = NULL;

  struct no* atual = *lista;
  while (atual != NULL) {
    struct no* novo = malloc(sizeof(struct no));
    novo->filme = atual->filme;
    novo->proximo = lista_auxiliar;
    lista_auxiliar = novo;
    atual = atual->proximo;
  }

  *lista = NULL;

  while (lista_auxiliar != NULL) {
    struct no* novo = malloc(sizeof(struct no));
    novo->filme = lista_auxiliar->filme;
    novo->proximo = *lista;
    *lista = novo;
    lista_auxiliar = lista_auxiliar->proximo;
  }
}

int main() {
  struct no* lista = NULL;
  char titulo[50];

  while (1) {
    printf("Menu:\n");
    printf("1 - Inserir um filme no final da lista\n");
    printf("2 - Inserir um filme em uma posicao especifica da lista\n");
    printf("3 - Remover um filme da lista\n");
    printf("4 - Remover um filme em uma posicao especifica da lista\n");
    printf("5 - Pesquisar se um filme consta na lista\n");
    printf("6 - Listar todos os filmes da lista\n");
    printf("7 - Inverter a ordem dos filmes presentes na lista\n");
    printf("8 - Encerrar o programa\n");

    int opcao;
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        struct filme* filme = malloc(sizeof(struct filme));
        printf("Titulo: ");
        scanf("%s", filme->titulo);
        printf("Ano: ");
        scanf("%d", &filme->ano);
        insere_final(&lista, filme);
        break;
      case 2:
        struct filme* filme = malloc(sizeof(struct filme));
        printf("Titulo: ");
        scanf("%s", filme->titulo);
        printf("Ano: ");
        scanf("%d", &filme->ano);
        printf("Posicao: ");
        int posicao;
        scanf("%d", &posicao);
        insere_posicao(&lista, filme, posicao);
        break;
      case 3:
        printf("Titulo do filme a ser removido: ");
        scanf("%s", titulo);
        remove(&lista, titulo);
        break;
      case 4:
        printf("Posicao do filme a ser removido: ");
        scanf("%d", &posicao);
        remove_posicao(&lista, posicao);
        break;
      case 5:
        printf("Titulo do filme a ser pesquisado: ");
        scanf("%s", titulo);
        int posicao_filme = pesquisa(lista, titulo);
        if (posicao_filme == -1) {
          printf("O filme nao foi encontrado.\n");
        } else {
          printf("O filme esta na posicao %d.\n", posicao_filme);
        }
        break;
      case 6:
        listar(lista);
        break;
      case 7:
        inverte(&lista);
        break;
      case 8:
        printf("Fim do programa.\n");
        return 0;
      default:
        printf("Opcao inválida.\n");
        break;
    }
  }
}


