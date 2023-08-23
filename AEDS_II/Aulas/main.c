#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

typedef struct aluno {
    char nome[30];
    int m;
    float notas[3];
    float med;
} Aluno;

void preencheDados(Aluno *aluno, int tam);
int quantidadeAprovados(Aluno *aluno, int tam);

int main (){
    int n;
    printf("Digite o numero de alunos: ");
    scanf("%d", &n);

    Aluno* alunos = (Aluno*) malloc(n*sizeof(Aluno));
    preencheDados(alunos, n);

    int numAprovados = quantidadeAprovados(alunos, n);
    printf("%d", numAprovados);

    return 0;
}

void preencheDados(Aluno *aluno, int tam){
    float soma = 0;
    for(int i = 0; i < tam; i++){
        aluno[i].m = i+1;
        for(int j = 0; j < 3; j++){
            aluno[i].notas[j] = j*i;
            soma += j*i;
        }
        strcpy(aluno[i].nome, "Nome"+i);
        aluno[i].med = soma/3;
    }
}

int quantidadeAprovados(Aluno *aluno, int tam){
    int c = 0;
    for(int i = 0; i < tam; i++){
        aluno[i].med >= 6.0 ? c++ : NULL;
    }
    return c;
}