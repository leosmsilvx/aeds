#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct no {
  int numero;
  struct no* proximo;
};

struct no* novo_no(int numero) {
  struct no* novo = malloc(sizeof(struct no));
  novo->numero = numero;
  novo->proximo = NULL;
  return novo;
}

void insere(struct no** lista, int numero) {
  struct no* novo = novo_no(numero);

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

int esta_na_lista(struct no* lista, int numero) {
  struct no* atual = lista;
  while (atual != NULL) {
    if (atual->numero == numero) {
      return 1;
    }
    atual = atual->proximo;
  }

  return 0;
}

int soma_lista(struct no* lista) {
  int soma = 0;
  struct no* atual = lista;
  while (atual != NULL) {
    soma += atual->numero;
    atual = atual->proximo;
  }

  return soma;
}

int maior_numero(struct no* lista) {
  int maior = lista->numero;
  struct no* atual = lista->proximo;
  while (atual != NULL) {
    if (atual->numero > maior) {
      maior = atual->numero;
    }
    atual = atual->proximo;
  }

  return maior;
}

int menor_numero(struct no* lista) {
  int menor = lista->numero;
  struct no* atual = lista->proximo;
  while (atual != NULL) {
    if (atual->numero < menor) {
      menor = atual->numero;
    }
    atual = atual->proximo;
  }

  return menor;
}

void remove_pares(struct no** lista) {
  struct no* lista_impares = NULL;

  struct no* atual = *lista;
  while (atual != NULL) {
    if (atual->numero % 2 == 1) {
      insere(&lista_impares, atual->numero);
    }
    atual = atual->proximo;
  }

  *lista = lista_impares;
}

void inverte(struct no** lista) {
  if (*lista == NULL) {
    return;
  }

  struct no* lista_invertida = NULL;
  struct no* atual = *lista;

  while (atual != NULL) {
    insere(&lista_invertida, atual->numero);

    atual = atual->proximo;
  }

  *lista = lista_invertida;
}

void listar(struct no* lista) {
  if (lista == NULL) {
    return;
  }

  struct no* atual = lista;
  while (atual != NULL) {
    printf("%d ", atual->numero);
    atual = atual->proximo;
  }

  printf("\n");
}

int main() {
  struct no* lista = NULL;

  while (1) {
    printf("Menu:\n");
    printf("1 - Inserir um numero na lista\n");
    printf("2 - Verifica se um numero se encontra na lista\n");
    printf("3 - Exiba a soma de todos os numeros na lista\n");
    printf("4 - Exiba o maior numero na lista\n");
    printf("5 - Exiba o menor numero na lista\n");
    printf("6 - Remova todos os numeros pares da lista\n");
    printf("7 - Exiba os numeros que estao na lista, apos a remocao dos numeros pares\n");
    printf("8 - Inverta os elementos da lista\n");
    printf("9 - Encerrar o programa\n");

    int opcao;
    printf("Opçao: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        int numero;
        printf("Numero: ");
        scanf("%d", &numero);
        insere(&lista, numero);
        break;
      case 2:
        int numero_procurado;
        printf("Numero a ser procurado: ");
        scanf("%d", &numero_procurado);
        int esta_presente = esta_na_lista(lista, numero_procurado);
        if (esta_presente) {
          printf("O numero %d esta na lista\n", numero_procurado);
        } else {
          printf("O numero %d nao esta na lista\n", numero_procurado);
        }
        break;
      case 3:
        int soma = soma_lista(lista);
        printf("A soma dos numeros na lista e %d\n", soma);
        break;
      case 4:
        int maior = maior_numero(lista);
        printf("O maior numero na lista e %d\n", maior);
        break;
      case 5:
        int menor = menor_numero(lista);
        printf("O menor numero na lista e %d\n", menor);
        break;
      case 6:
        remove_pares(&lista);
        printf("Os numeros pares foram removidos da lista\n");
        break;
      case 7:
        printf("Os numeros na lista, após a remoçao dos numeros pares, sao:\n");
        listar(lista);
        break;
      case 8:
        inverte(&lista);
        printf("Os elementos da lista foram invertidos\n");
        break;
      case 9:
        printf("Fim do programa\n");
        return 0;
      default:
        printf("Opçao invalida\n");
        break;
    }
  }

  return 0;
}

