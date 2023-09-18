#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

bool conjuntoVazio(int* conjunto){
    return (sizeof(conjunto) / sizeof(conjunto[0])) == 0;        
}

int tamanhoDoConjunto(int* conjunto) {
    return sizeof(conjunto) / sizeof(conjunto[0]);
}

bool conjuntosSaoIguais(int* conjunto1, int* conjunto2, int tam1, int tam2){
    if(tam1 != tam2)
        return false;

    for(int i = 0; i < tam1; i++){
        if(conjunto1[i] != conjunto2[i])
            return false;
    }
    return true;
}

int maiorValorConjunto(int* conjunto, int tam){
    int maiorValor = conjunto[0];
    for(int i = 0; i < tam; i++){
        if(conjunto[i] > maiorValor)
            maiorValor = conjunto[i];
    }
    return maiorValor;
}

int menorValorConjunto(int* conjunto, int tam){
    int menorValor = conjunto[0];
    for(int i = 0; i < tam; i++){
        if(conjunto[i] < menorValor)
            menorValor = conjunto[i];
    }
    return menorValor;
}

bool numeroNoConjunto(int* conjunto, int tam, int valor){
    for(int i = 0; i < tam; i++){
        if(conjunto[i] == valor)
            return true;
    }
    return false;
}

int* diferencaConjuntos(int* conjunto1, int* conjunto2, int tam1, int tam2, int* tamDiferenca) {    
    *tamDiferenca = 0;    
    int * conjuntoDiferenca = (int*) malloc((tam1 + tam2) * sizeof(int));
    if(conjuntoDiferenca == NULL)
        return NULL;

    for (int i = 0; i < tam1; i++) {
        int encontrado = false;
        for (int j = 0; j < tam2; j++) {
            if (conjunto1[i] == conjunto2[j]) {
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            conjuntoDiferenca[*tamDiferenca] = conjunto1[i];
            (*tamDiferenca)++;
        }
    }
    return realloc(conjuntoDiferenca, *tamDiferenca*sizeof(int));;
}

int* intersecaoConjuntos(int* conjunto1, int* conjunto2, int tam1, int tam2, int* tamIntersecao){
    *tamIntersecao = 0;    
    int * conjuntoIntersecao = (int*) malloc(tam1 * sizeof(int));
    if(conjuntoIntersecao == NULL)
        return NULL;

    for(int i = 0; i < tam1; i++){
        for(int j = 0; j < tam2; j++){
            if(conjunto1[i] == conjunto2[j]){                
                conjuntoIntersecao[*tamIntersecao] = conjunto1[i];
                (*tamIntersecao)++;
                break;
            }
        }
    }
    return realloc(conjuntoIntersecao, *tamIntersecao*sizeof(int));
}

void removeDoConjunto(int* conjunto, int* tam, int elemento) {
    int encontrado = false;
    for (int i = 0; i < *tam; i++) {
        if (conjunto[i] == elemento) {
            encontrado = true;
            for (int j = i; j < (*tam - 1); j++) {
                conjunto[j] = conjunto[j + 1];
            }
            (*tam)--;
            break;
        }
    }

    realloc(conjunto, (*tam) * sizeof(int));

    if (!encontrado) {
        printf("Elemento '%d' nao encontrado no conjunto\n", elemento);
    }
}

void insereEmConjunto(int* conjunto, int* tam, int valor){
    (*tam)++;
    conjunto = (int*) realloc(conjunto, (*tam)*sizeof(int));

    if(conjunto == NULL){
        return;
    }

    conjunto[*tam - 1] = valor;
}

int* criarConjuntoVazio(){
    int* conjuntoVazio = (int*) malloc(0);
    if(conjuntoVazio == NULL){
        return NULL;
    }
    return conjuntoVazio;
}

int* unirConjuntos(int* conjunto1, int* conjunto2, int tamc1, int tamc2, int* tamConjuntoUnido){
    *tamConjuntoUnido = tamc1 + tamc2;
    int* conjuntoUnido = (int*) malloc((tamc1 + tamc2)*sizeof(int));

     if (conjuntoUnido == NULL)
        return NULL;

    for(int i = 0; i < tamc1; i++){
        conjuntoUnido[i] = conjunto1[i];
    }

    for(int i = 0; i < tamc2; i++){
        conjuntoUnido[tamc1 + i] = conjunto2[i];
    }

    return conjuntoUnido;
}

int main(){
    int conjunto1[5] = {1, 2, 3, 4, 5};
    int conjunto2[5] = {6, 3, 8, 9, 5};

    int tamConjuntoUnido;
    int* conjuntoUnido = unirConjuntos(conjunto1, conjunto2, 5, 5, &tamConjuntoUnido);

    criarConjuntoVazio();

    int tamConjuntoRealocar = 5;
    int* conjuntoParaRealocar = (int*) malloc(tamConjuntoRealocar*sizeof(int));
    for(int i = 0; i < tamConjuntoRealocar; i++){
        conjuntoParaRealocar[i] = i + 1;
    }
    insereEmConjunto(conjuntoParaRealocar, &tamConjuntoRealocar, 10);

    removeDoConjunto(conjuntoParaRealocar, &tamConjuntoRealocar, 3);

    int tamConjuntoIntersecao;
    int* conjuntoIntersecao = intersecaoConjuntos(conjunto1, conjunto2, 5, 5, &tamConjuntoIntersecao);

    int tamConjuntoDiferenca;
    int* conjuntoDiferenca = diferencaConjuntos(conjunto1, conjunto2, 5, 5, &tamConjuntoDiferenca);


    return 0;
}