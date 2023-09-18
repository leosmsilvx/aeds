#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    int num;
    int den;
} Racional;

bool saoIguais(Racional a, Racional b){
    return (a.num * b.den) == (b.num * a.den);
}

Racional multiplicaRacionais(Racional a, Racional b) {
    Racional resultado;
    resultado.num = a.num * b.num;
    resultado.den = a.den * b.den;
    return resultado;
}

Racional somaRacionais(Racional a, Racional b) {
    Racional resultado;
    resultado.num = (a.num * b.den) + (b.num * a.den);
    resultado.den = a.den * b.den;
    return resultado;
}

Racional criarRacional(int numerador, int denominador) {
    Racional racional;
    racional.num = numerador;
    racional.den = denominador;
    return racional;
}

int main(){
    Racional r1 = criarRacional(2, 3);
    Racional r2 = criarRacional(1, 3);

    Racional soma = somaRacionais(r1, r2);

    Racional mult = multiplicaRacionais(r1, r2);

    if(saoIguais(r1, r2))
        printf("Sao iguais");
    else 
        printf("Nao sao iguais");

    return 0;
}