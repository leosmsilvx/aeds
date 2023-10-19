#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX 100

typedef struct fila {
    int primeiro;
    int ultimo;
    int tamanho;
    int dados[MAX];
} Fila;


Fila* inicializaFila(){
    Fila* novaFila = (Fila*) malloc(sizeof(Fila));
    novaFila->primeiro = 0;
    novaFila->ultimo = 0;
    novaFila->tamanho = 0;
    return novaFila;
}

bool isFilaEmpty(Fila* fila){
    return fila->tamanho == 0;
}

bool isFilaFull(Fila* fila){
    return fila->tamanho == MAX;
}

bool insert(Fila* fila, int valor){
    if(isFilaFull(fila))
        return false;
    fila->dados[fila->ultimo % MAX] = valor;
    fila->ultimo++;
    fila->tamanho++;
    return true;
}

bool remover(Fila* fila, int* valor){
    if(isFilaEmpty(fila))
        return false;
    *valor = fila->dados[fila->primeiro % MAX];
    fila->primeiro++;
    fila->tamanho--;
    return true;
}

void liberaFila(Fila* fila){
    free(fila);
}


int main(){
    Fila* fila = inicializaFila();
    int v;
    for(int i = 0; i < 3; i++){
        if(!insert(fila, i+1))
            printf("Nao e possivel adicionar na fila\n");  
        else
            printf("Valor adicionado: %d\n", i+1);  
    }
    for(int i = 0; i < 4; i++){
        if(!remover(fila, &v))
            printf("Nao e possivel tirar da fila\n");  
        else
            printf("Valor retirado: %d\n", v);  
    }
    for(int i = 0; i < MAX + 1; i++){
        if(!insert(fila, i+1))
            printf("Nao e possivel adicionar na fila\n");
    }

    liberaFila(fila);
    printf("\n\nFila Liberada\n\n\n");
    return 0;
}