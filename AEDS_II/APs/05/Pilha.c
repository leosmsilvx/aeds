#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct elPilha{
    int val;
    struct elPilha *ant;
} ElPilha;

typedef struct pilha{
    ElPilha *top;
} Pilha;

Pilha* inicializaPilha(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->top == NULL;
    return p;
}

bool isPilhaEmpty(Pilha *p){
    if(p->top == NULL)
        return true;
    return false;
}

void empilhar(Pilha* p, int val){
    ElPilha* el = (ElPilha*) malloc(sizeof(ElPilha));
    if(el == NULL)
        return;
    el->val = val;
    el->ant = p->top;
    p->top = el;
}

bool desempilhar(Pilha *p, int *val){
    if(isPilhaEmpty(p))
        return false;
    *val = p->top->val;
    ElPilha* elTop = p->top;    
    p->top = p->top->ant;
    free(elTop);
    return true;
}

void freePilha(Pilha *p){
    while(p->top != NULL){
        ElPilha* elTop = p->top;    
        p->top = p->top->ant;
        free(elTop);
    }
    free(p);
}

int main(){
    Pilha* p = inicializaPilha();
    empilhar(p, 10);
    empilhar(p, 30);
    empilhar(p, 50);

    int x;
    desempilhar(p, &x);
    printf("x: %d\n", x);
    desempilhar(p, &x);
    printf("x: %d\n", x);

    freePilha(p);
    return 0;
}