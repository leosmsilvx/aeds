#include <stdio.h>

#define LIN 4
#define COL 4

int main() {
    int A[LIN][COL];
    int linhas_nulas = 0, colunas_nulas = 0;

    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            printf("Digite o elemento da linha %d e coluna %d: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < LIN; i++) {
        int n_zeros = 0;
        for (int j = 0; j < COL; j++) {
            if (A[i][j] == 0) {
                n_zeros++;
            }
        }
        if (n_zeros == COL) {
            linhas_nulas++;
        }
    }

    for (int j = 0; j < COL; j++) {
        int n_zeros = 0;
        for (int i = 0; i < LIN; i++) {
            if (A[i][j] == 0) {
                n_zeros++;
            }
        }
        if (n_zeros == LIN) {
            colunas_nulas++;
        }
    }

    printf("Esta matriz tem %d linha(s) nula(s)\n", linhas_nulas);
    printf("Esta matriz tem %d coluna(s) nula(s)\n", colunas_nulas);

    return 0;
}
