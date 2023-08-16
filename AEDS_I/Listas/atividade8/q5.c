#include <stdio.h>

void exibirConceito(float media) {
    if (media >= 90.0) {
        printf("Conceito: A\n");
    } else if (media >= 80.0 && media < 89.0) {
        printf("Conceito: B\n");
    } else if (media >= 70.0 && media < 79.0) {
        printf("Conceito: C\n");
    } else if (media >= 60.0 && media < 69.0) {
        printf("Conceito: D\n");
    } else if (media >= 40 && media < 59.0) {
        printf("Conceito: E\n");
    } else if (media <= 39.0) {
        printf("Conceito: F\n");
    } else {
        printf("Média inválida\n");
    }
}

int main() {
    int n, i;
    float media;

    printf("Digite o número de alunos: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Aluno %d:\n", i);
        printf("Digite a média final: ");
        scanf("%f", &media);

        exibirConceito(media);
        printf("\n");
    }

    return 0;
}
