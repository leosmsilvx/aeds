#include <stdio.h>

int main(){
    float num1, num2, resul;
    int op;

    printf("Digite um numero: ");
    scanf("%f", &num1);

    printf("Digite um outro numero: ");
    scanf("%f", &num2);


    do{
        printf("\nDigite uma opcao\nAdicao[1]\nSubtracao[2]\nMultiplicacao[3]\nDivisao[4]\nSair[0]\n");
        scanf("%d", &op);

        if(op > 0 || (op < 5 && op != 0)){
            if(op == 1){
                resul = num1 + num2;
            } else if(op == 2){
                resul = num1 - num2;
            } else if(op == 3){
                resul = num1*num2;
            } else if(op == 4){
                resul = num1/num2;
            }
            printf("O resultado e: %.2f\n", resul);
        }
    }while(op != 0);

    return 0;
}