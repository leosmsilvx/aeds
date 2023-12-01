#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define tamVet 5

void particionar(int esquerda, int direita, int* i, int* j, int vetor[]){
    int x;
    *i = esquerda;
    *j = direita;
    int pivoNum = rand() % direita+1;
    x = vetor[pivoNum];

    while(*i <= *j){
        while(x > vetor[*i]){
            ++*i;
        }

        while(x < vetor[*j]){
            --*j;
        }

        if(*i > *j){
            continue;            
        }

        if(*i != *j){
            int temp = vetor[*i];
            vetor[*i] = vetor[*j];
            vetor[*j] = temp;
        }
        ++*i;
        --*j;
    }
}

void ordenar(int esquerda, int direita, int vetor[]){
    int i, j;
    particionar(esquerda, direita, &i, &j, vetor);
    if(esquerda < j){
        ordenar(esquerda, j, vetor);
    }
    if(i < direita){
        ordenar(i, direita, vetor);
    }
}

void quicksort(int vet[], int tam){
    ordenar(0, tam-1, vet);
}

void printVet(int vet[], int tam){
    printf("Vetor: ");
    for(int i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main(){
    srand(time(NULL));

    int vet[tamVet] = {1, 37, 21, 12, 50, 49, 15, 12, 35, 9};
    int tam = tamVet;
    int esq = 0;
    int dir = 4;

    printVet(vet, tam);
    quicksort(vet, tam);
    printVet(vet, tam);
}