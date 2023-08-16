#include <stdio.h>

#define ROWS 3
#define COLS 3

int main() {
    int A[ROWS][COLS], B[ROWS][COLS], C[ROWS][COLS];
    int i, j, k;

    printf("Digite os elementos da matriz A:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("Digite o elemento da linha %d e coluna %d: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("Digite os elementos da matriz B:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("Digite o elemento da linha %d e coluna %d: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            C[i][j] = 0;
            for (k = 0; k < ROWS; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("A matriz C = A * B eh igual a:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
