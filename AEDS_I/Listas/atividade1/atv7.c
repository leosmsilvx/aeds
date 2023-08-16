#include <stdio.h>

int main() {
    float salario_base, gratificacao, imposto, salario_receber;

    printf("Digite o salário base do funcionário: ");
    scanf("%f", &salario_base);

    gratificacao = salario_base * 0.05;

    imposto = salario_base * 0.07;

    salario_receber = salario_base + gratificacao - imposto;

    printf("O salário a receber é: R$ %.2f\n", salario_receber);

    return 0;
}
