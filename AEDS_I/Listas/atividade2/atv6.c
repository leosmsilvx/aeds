#include <stdio.h>

int main() {
    float salario_hora, horas_trabalhadas, horas_extras, salario_bruto, salario_dependentes, salario_liquido;
    int num_dependentes;
    printf("Digite o valor do salário por hora trabalhada: ");
    scanf("%f", &salario_hora);
    printf("Digite o número de horas trabalhadas: ");
    scanf("%f", &horas_trabalhadas);
    printf("Digite o número de horas extras trabalhadas: ");
    scanf("%f", &horas_extras);
    printf("Digite o número de dependentes: ");
    scanf("%d", &num_dependentes);
    
    salario_bruto = salario_hora * horas_trabalhadas + salario_hora * 1.5 * horas_extras;
    
    salario_dependentes = num_dependentes * 128;
    
    float ir;
    if (salario_bruto <= 1434.59) {
        ir = 0;
    } else if (salario_bruto <= 2150.00) {
        ir = 0.075;
    } else if (salario_bruto <= 2866.70) {
        ir = 0.15;
    } else if (salario_bruto <= 3582.00) {
        ir = 0.225;
    } else {
        ir = 0.275;
    }
    float imposto_renda = salario_bruto * ir;
    
    salario_liquido = salario_bruto - imposto_renda + salario_dependentes;
    
    float beneficio;
    if (salario_liquido <= 500.00) {
        beneficio = 180.00;
    } else if (salario_liquido <= 1000.00) {
        beneficio = 120.00;
    } else {
        beneficio = 100.00;
    }
    
    salario_liquido += beneficio;
    
    printf("O salário líquido do empregado é R$%.2f.\n", salario_liquido);
    
    return 0;
}
