#include <stdio.h>

float calcularMedia(float nota1, float nota2, float nota3, char opcao) {
    float media;

    if (opcao == 'A' || opcao == 'a') {
        media = (nota1 + nota2 + nota3) / 3;
    } else if (opcao == 'P' || opcao == 'p') {
        media = (nota1 * 5 + nota2 * 3 + nota3 * 2) / 10;
    } else {
        printf("Opção inválida! Escolha 'A' para média aritmética ou 'P' para média ponderada.\n");
        return 0;
    }

    return media;
}

int main() {
    int n, i;
    float nota1, nota2, nota3;
    char opcao;

    printf("Digite o número de alunos: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Aluno %d:\n", i);
        printf("Digite a primeira nota: ");
        scanf("%f", &nota1);
        printf("Digite a segunda nota: ");
        scanf("%f", &nota2);
        printf("Digite a terceira nota: ");
        scanf("%f", &nota3);
        printf("Digite 'A' para média aritmética ou 'P' para média ponderada: ");
        scanf(" %c", &opcao);

        float media = calcularMedia(nota1, nota2, nota3, opcao);

        if (media != 0) {
            printf("Média do aluno %d: %.2f\n", i, media);
        }
    }

    return 0;
}
