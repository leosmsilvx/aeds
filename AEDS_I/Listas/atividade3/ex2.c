#include <stdio.h>

int main(){
    int cont, val, pares = 0, i = 0;

    printf("Digite quantos valores deseja ler: ");
    scanf("%d", &cont);

    while(i < cont){
        printf("Digite um numero: ");
        scanf("%d", &val);



        if(val % 2 == 0){
            pares++;
        }
        i++;
    }

    printf("Foram digitados %d numeros pares\nForam digitados %d numeros impares", pares, cont-pares);

    return 0;
}