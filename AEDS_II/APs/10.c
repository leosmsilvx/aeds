#include <stdio.h>

void bubbleSort(int *vetor, int tamanho) {
  int i, j, aux;

  for (i = 0; i < tamanho - 1; i++) {
    for (j = 0; j < tamanho - i - 1; j++) {
      if (vetor[j] > vetor[j + 1]) {
        aux = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = aux;
      }
    }
  }
}

void selectionSort(int *vetor, int tamanho) {
  int i, j, menor, aux;

  for (i = 0; i < tamanho - 1; i++) {
    menor = i;
    for (j = i + 1; j < tamanho; j++) {
      if (vetor[j] < vetor[menor]) {
        menor = j;
      }
    }
    aux = vetor[i];
    vetor[i] = vetor[menor];
    vetor[menor] = aux;
  }
}

void insertionSort(int *vetor, int tamanho) {
  int i, j, elemento;

  for (i = 1; i < tamanho; i++) {
    elemento = vetor[i];
    j = i - 1;
    while (j >= 0 && vetor[j] > elemento) {
      vetor[j + 1] = vetor[j];
      j--;
    }
    vetor[j + 1] = elemento;
  }
}

int main() {
  int vetor[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int tamanho = sizeof(vetor) / sizeof(int);

  printf("Vetor original: ");
  for (int i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  bubbleSort(vetor, tamanho);
  printf("BubbleSort: ");
  for (int i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  selectionSort(vetor, tamanho);
  printf("SelectionSort: ");
  for (int i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  insertionSort(vetor, tamanho);
  printf("InsertionSort: ");
  for (int i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  return 0;
}
