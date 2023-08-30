#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct ponto {
    int x, y;
} Ponto;

Ponto setPonto(int x, int y){
    Ponto p;
    p.x = x;
    p.y = y;
    return p;
}

Ponto setPontoIO(){
    Ponto p;
    printf("Digite os pontos: x e y: ");
    scanf("%d %d", &p.x, &p.y);
    return p;
}

int quadranteDoPonto(Ponto p){
    if(p.x > 0 && p.y > 0)
        return 1;
    if(p.x < 0 && p.y > 0)
        return 2;
    if(p.x < 0 && p.y < 0)
        return 3;
    if(p.x > 0 && p.y < 0)
        return 4;
}

bool isInQuadrante(Ponto p, int quadrante){
    if(quadranteDoPonto(p) == quadrante)
        return true;
    else
        return false;
}

void changePonto(Ponto *p, int x, int y){
    p->x = x;
    p->y = y;
}

float distanciaPontos(Ponto p1, Ponto p2){
    return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
}

int maiorCord(Ponto p){
    if(p.x > p.y)
        return p.x;
    else if (p.y > p.x)
        return p.y;
    else 
        return 0;
}

int main(){
    Ponto p1 = setPonto(10, 5);
    printf("P1 (%d, %d)\n", p1.x, p1.y);
    Ponto p2 = setPontoIO();
    printf("P2 (%d, %d)\n", p2.x, p2.y);

    printf("Quadrante do p1: %d\n", quadranteDoPonto(p1));
    printf("Quadrante do p2: %d\n", quadranteDoPonto(p2));

    if(isInQuadrante(p1, quadranteDoPonto(p2)))
        printf("Eles estão no mesmo quadrante\n");

    changePonto(&p1, 20, 10);
    printf("Ponto alterado P1 (%d, %d)\n", p1.x, p1.y);

    printf("Distancia entre os pontos p1 e p2 = %.2f\n", distanciaPontos(p1, p2));

    printf("A maior coordenada de p1= %d\n", maiorCord(p1));
    printf("A maior coordenada de p2 = %d\n ", maiorCord(p2));

    pow(2, 2);
    return 0;
}