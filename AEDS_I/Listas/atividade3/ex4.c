#include <stdio.h>

int main(){
    int num, div = 0;

    printf("Digite um numero: ");
    scanf("%d", &num);

    int i = 1;
    while(i <= num){
        if(num % i == 0){
            div++;
        }
        i++;
    }

    if(num == 1){
        printf("1 e um numero primo");
    } else if(div == 2){
        printf("%d e um numero primo", num);
    } else{
        printf("%d nao e um numero primo", num);
    }

    return 0;
}