#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct contato {
  char nome[50];
  char telefone[20];
  char email[50];
  struct contato* proximo;
};


struct contato* novo_contato(char* nome, char* telefone, char* email) {
  struct contato* contato = malloc(sizeof(struct contato));
  strcpy(contato->nome, nome);
  strcpy(contato->telefone, telefone);
  strcpy(contato->email, email);
  return contato;
}

void insere(struct contato** lista, struct contato* contato) {
  if (*lista == NULL) {
    *lista = contato;
  } else {
    struct contato* atual = *lista;
    while (atual->proximo != NULL) {
      atual = atual->proximo;
    }

    atual->proximo = contato;
  }
}

struct contato* encontra_contato(struct contato** lista, char* nome) {
  struct contato* atual = *lista;
  while (atual != NULL) {
    if (strcmp(atual->nome, nome) == 0) {
      return atual;
    }
    atual = atual->proximo;
  }

  return NULL;
}

void atualiza_contato(struct contato** lista, char* nome, char* telefone, char* email) {
  struct contato* contato = encontra_contato(lista, nome);

  if (contato != NULL) {
    strcpy(contato->telefone, telefone);
    strcpy(contato->email, email);
  }
}

void exclui_contato(struct contato** lista, char* nome) {
  struct contato* contato = encontra_contato(lista, nome);

  if (contato != NULL) {
    if (*lista == contato) {
      *lista = contato->proximo;
    } else {
      struct contato* anterior = *lista;
      while (anterior->proximo != contato) {
        anterior = anterior->proximo;
      }

      anterior->proximo = contato->proximo;
    }

    free(contato);
  }
}

void lista_contatos(struct contato** lista) {
  if (*lista == NULL) {
    return;
  }

  struct contato* atual = *lista;
  while (atual != NULL) {
    printf("Nome: %s\nTelefone: %s\nE-mail: %s\n\n", atual->nome, atual->telefone, atual->email);
    atual = atual->proximo;
  }
}

int main() {
  struct contato** lista = malloc(sizeof(struct contato*));
  *lista = NULL;

  while (1) {
    printf("Menu:\n");
    printf("1 - Adicionar um novo contato\n");
    printf("2 - Atualizar as informacoes de um contato\n");
    printf("3 - Excluir um contato\n");
    printf("4 - Listar todos os contatos\n");
    printf("5 - Sair\n");

    int opcao;
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        char nome[50];
        char telefone[20];
        char email[50];
        printf("Nome: ");
        scanf("%s", nome);
        printf("Telefone: ");
        scanf("%s", telefone);
        printf("E-mail: ");
        scanf("%s", email);
        struct contato* contato = novo_contato(nome, telefone, email);
        insere(lista, contato);
        break;
      case 2:
        char nome_antigo[50];
        printf("Nome do contato a ser atualizado: ");
        scanf("%s", nome_antigo);
        char telefone_novo[20];
        printf("Novo telefone: ");
        scanf("%s", telefone_novo);
        char email_novo[50];
        printf("Novo e-mail: ");
        scanf("%s", email_novo);
        atualiza_contato(lista, nome_antigo, telefone_novo, email_novo);
        break;
      case 3:
        char nome_a_excluir[50];
        printf("Nome do contato a ser excluido: ");
        scanf("%s", nome_a_excluir);
        exclui_contato(lista, nome_a_excluir);
        break;
      case 4:
        lista_contatos(lista);
        break;
      case 5:
        printf("Fim do programa.\n");
        return 0;
      default:
        printf("Opcao invalida.\n");
        break;
    }
  }

  return 0;
}
