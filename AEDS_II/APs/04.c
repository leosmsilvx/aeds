#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX 100

typedef struct plh {
    int topo;
    int dados[MAX];
} Pilha;

typedef struct fl {
    int dados[MAX];
    int primeiro;
    int ultimo;
} Fila;

Fila* inicializaFila(){
    Fila* novaFila = (Fila*) malloc(sizeof(Fila));
    novaFila->primeiro = -1;
    novaFila->ultimo = -1;
    return novaFila;
}

bool isFilaEmpty(Fila* fila){
    return fila->primeiro == fila->ultimo;
}

bool isFilaFull(Fila* fila){
    return fila->ultimo == MAX -1;
}

bool insert(Fila* fila, int valor){
    if(isFilaFull(fila))
        return false;
    fila->ultimo++;
    fila->dados[fila->ultimo] = valor;
    return true;
}

bool remover(Fila* fila, int* valor){
    if(isFilaEmpty(fila))
        return false;

    fila->primeiro++;
    *valor = fila->dados[fila->primeiro];
    return true;
}

void liberaFila(Fila* fila){
    free(fila);
}

Pilha* inicializaPilha(){
    Pilha* novaPilha = (Pilha*) malloc(sizeof(Pilha));
    novaPilha->topo = -1;
    return novaPilha;
}

void liberaPilha(Pilha* pilha){
    free(pilha);
}

bool isListaEmpty(Pilha* pilha){
    return pilha->topo == -1;
}

bool isListaFull(Pilha* pilha){
    return pilha->topo == MAX -1;
}

bool push(Pilha* pilha, int valor){
    if(isListaFull(pilha))
        return false;

    pilha->topo++;
    pilha->dados[pilha->topo] = valor;
    return true;
}

bool pop(Pilha* pilha, int* valor){
    if(isListaEmpty(pilha))
        return false;

    *valor = pilha->dados[pilha->topo];
    pilha->topo--;
    return true;
}

int peek(Pilha* pilha){
    return pilha->dados[pilha->topo];
}

int main(){
    int v;

    Pilha* pilha = inicializaPilha();
    for(int i = 0; i < 3; i++){
        if(!push(pilha, i+1))
            printf("Nao e possivel adicionar na pilha\n");  
        else
            printf("Valor adicionado: %d\n", i+1);  
    }
    for(int i = 0; i < 4; i++){
        if(!pop(pilha, &v))
            printf("Nao e possivel tirar da fila\n");  
        else
            printf("Valor retirado: %d\n", v);  
    }
    for(int i = 0; i < MAX + 1; i++){
        if(!push(pilha, i+1))
            printf("Nao e possivel adicionar na pilha\n");  
    }

    liberaPilha(pilha);
    printf("\n\nPilha Liberada\n\n\n");

    Fila* fila = inicializaFila();
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
    //-2 porque foi adicionado já 3 elementos e a fila não reorganiza
    for(int i = 0; i < MAX - 2; i++){
        if(!insert(fila, i+1))
            printf("Nao e possivel adicionar na fila\n");
    }

    liberaFila(fila);
    printf("\n\nFila Liberada\n\n\n");

    return 0;
}