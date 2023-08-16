#include <stdio.h>

int main() {
  int A[4][4];
  int i, j;
  
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      printf("Digite o elemento da linha %d e coluna %d: ", i, j);
      scanf("%d", &A[i][j]);
    }
  }
  
  printf("Os elementos da diagonal sao ");
  for (i = 0; i < 4; i++) {
    printf("%d ", A[i][i]);
  }
  printf("\n");
  
  return 0;
}
