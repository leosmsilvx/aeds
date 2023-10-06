#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct elFila{
    int val;
    struct elFila *prox;
} ElFila;

typedef struct fila{
    ElFila *inicio;
    ElFila *final;
} Fila;

Fila* inicializaFila(){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->final = NULL;
    f->inicio = NULL;
}

bool isFilaEmpty(Fila *f){
    if(f->final == NULL && f->inicio == NULL)
        return true;
    return false;
}

void addInFila(Fila *f, int val){
    ElFila* el = (ElFila*) malloc(sizeof(ElFila));
    if(el == NULL)
        return;
        
    el->val = val;
    el->prox = NULL;

    if(isFilaEmpty(f)){
        f->inicio = el;
    } else {
        f->final->prox = el;
    }

    f->final = el;
}

bool removeFromFila(Fila *f, int *val){
    if(isFilaEmpty(f))
        return false;
    *val = f->inicio->val;

    ElFila* elInicio = f->inicio;
    f->inicio = elInicio->prox;
    if(elInicio->prox == NULL)
        f->final = NULL;
    free(elInicio);
    return true;
}

void freeFila(Fila *f){
    while(f->inicio != NULL){
         ElFila* elInicio = f->inicio;
        f->inicio = elInicio->prox;
        free(elInicio);
    }
    free(f);
}


int main(){
    Fila* f = inicializaFila();

    addInFila(f, 10);
    addInFila(f, 30);
    addInFila(f, 50);

    int x;
    removeFromFila(f, &x);
    printf("x: %d\n", x);
    removeFromFila(f, &x);
    printf("x: %d\n", x);

    freeFila(f);
    return 0;
}