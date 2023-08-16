#include <stdio.h>

int main(){
    int cont, val, i = 0;
    float p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0;
    int total = 0;

    printf("Quantas idades deseja digitar? ");
    scanf("%d", &cont);

    while(i < cont){
        printf("Digite um numero: ");
        scanf("%d", &val);

        if(val >= 1 && val <= 15){
            p1++;
        } else if(val > 15 && val <= 30){
            p2++;
        } else if(val > 30 && val <= 45){
            p3++;
        } else if(val > 45 && val <= 60){
            p4++;
        } else{
            p5++;
        }
        i++;
    }

    printf("Faixa etaria:\n1 a 15 anos - %.2f\n16 a 30 anos - %.2f\n31 a 45 anos - %.2f\n46 a 60 anos - %.2f\nMais de 60 anos - %.2f", (p1*100)/cont, (p2*100)/cont, (p3*100)/cont, (p4*100)/cont, (p5*100)/cont);

    return 0;
}