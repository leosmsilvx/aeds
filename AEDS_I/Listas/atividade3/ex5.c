#include <stdio.h>

int main(){
    int num, div = 0;

    printf("Digite um numero limite: ");
    scanf("%d", &num);

    int i = 1;
    while(i <= num){

        //divisores do num
        int j = 1;
        printf("Os divisores de %d sao:", i);
        while(j <= i){;
            if(i % j == 0){
                printf(" %d", j);
            }
            j++;
        }
        printf("\n");
        i++;
    }

    return 0;
}