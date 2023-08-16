#include <stdio.h>

void calcularMediaSalario() {
    float salario, totalSalario = 0;
    int numFilhos, totalPessoas = 0;

    printf("Digite o salário (ou um valor negativo para sair): ");
    scanf("%f", &salario);

    while (salario >= 0) {
        printf("Digite o número de filhos: ");
        scanf("%d", &numFilhos);

        totalSalario += salario;
        totalPessoas++;

        printf("\nDigite o salário (ou um valor negativo para sair): ");
        scanf("%f", &salario);
    }

    if (totalPessoas > 0) {
        float mediaSalario = totalSalario / totalPessoas;
        printf("\nMédia de salário da população: %.2f\n", mediaSalario);
    } else {
        printf("\nNenhum dado de salário foi inserido.\n");
    }
}

int main() {
    calcularMediaSalario();

    return 0;
}
