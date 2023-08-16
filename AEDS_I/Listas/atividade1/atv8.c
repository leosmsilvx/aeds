#include <stdio.h>

int main() {
    int dias_trabalhados;
    float valor_diaria, valor_bruto, imposto, valor_liquido;

    valor_diaria = 30.0;
    printf("Digite o número de dias trabalhados: ");
    scanf("%d", &dias_trabalhados);

    valor_bruto = valor_diaria * dias_trabalhados;

    imposto = valor_bruto * 0.08;

    valor_liquido = valor_bruto - imposto;

    printf("O valor líquido a ser pago é: R$ %.2f\n", valor_liquido);

    return 0;
}
