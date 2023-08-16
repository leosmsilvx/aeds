#include <stdio.h>

int main(){
    int num;
    float maior = 0, menor = 0, val;

    printf("Quantos números deseja digitar?: ");
    scanf("%d", &num);

    int i = 1;
    while(i <= num){
        printf("Digite o numero: ");
        scanf("%f", &val);

        if(menor == 0){
            menor = val;
        }

        if(val < menor){
            menor = val;
        }
        if(val > maior){
            maior = val;
        }
        i++;
    }

    printf("Maior: %.2f\nMenor: %.2f", maior, menor);

    return 0;
}