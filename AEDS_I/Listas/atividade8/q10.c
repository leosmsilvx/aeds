#include <stdio.h>

float calcularMediaAprovados() {
    int contador = 0;
    float somaNotas = 0.0;
    float nota;

    printf("Digite as notas dos alunos (digite um valor negativo para encerrar):\n");

    while (1) {
        printf("Nota: ");
        scanf("%f", &nota);

        if (nota < 0) {
            break;
        }

        if (nota >= 6) {
            contador++;
            somaNotas += nota;
        }
    }

    if (contador > 0) {
        float media = somaNotas / contador;
        return media;
    } else {
        return 0.0;
    }
}

int main() {
    float mediaAprovados = calcularMediaAprovados();

    if (mediaAprovados > 0) {
        printf("A média das notas dos alunos aprovados é: %.2f\n", mediaAprovados);
    } else {
        printf("Nenhum aluno aprovado. Média não calculada.\n");
    }

    return 0;
}
