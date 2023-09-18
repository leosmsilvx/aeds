#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct aluno {
    char nome[20];
    int matricula;
    float notas[3];
    float media;
} Aluno;


void ordenaVetor(int* vetor, int tam){
    int i, j, aux;
    for(j = tam-1; j > 0; j--){
        for(i = 0; i < j; i++){
            if(vetor[i + 1] < vetor[i]){
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
            }
        }
    }
}

int buscaSequencial(int* vetor, int tam, int valor){
    for(int i = 0; i < tam; i++){
        if(valor == vetor[i]){
            return i;
        }
    }
    return -1;
}

int buscaBinaria(int* vetor, int tam, int valor){
    char ordenado;
    printf("O vetor esta ordenado? [s/n]: ");
    scanf(" %c", &ordenado);
    if(ordenado == 'n' || ordenado == 'N'){
        ordenaVetor(vetor, tam);
    }

    int i;
    int l = 0, r = tam - 1;
    do {
        i = (l + r) / 2;
        if(valor > vetor[i]){
            l = i + 1;
        } else {
            r = i - 1;  
        }
    } while (valor != vetor[i] && l <= r);
    if(valor == vetor[i])
        return i;
    else
        return -1;
    
}


int buscaSequencialAluno(Aluno* vetor, int tam, int valor){
    for(int i = 0; i < tam; i++){
        if(valor == vetor[i].matricula){
            return i;
        }
    }
    return -1;
}

int buscaBinariaAluno(Aluno* vetor, int tam, int valor){
    int i;
    int l = 0, r = tam - 1;
    do {
        i = (l + r) / 2;
        if(valor > vetor[i].matricula){
            l = i + 1;
        } else {
            r = i - 1;  
        }
    } while (valor != vetor[i].matricula && l <= r);
    if(valor == vetor[i].matricula)
        return i;
    else
        return -1;
    
}

void preencheVetor(int* vetor, int tam){
    printf("Preenche vetor\n");
    for(int i = 0; i < tam; i++){
        printf("Digite o valor do el %d: ", i);
        scanf("%d", &vetor[i]);
    }
}

void preencheAlunos(Aluno* vetor, int tam){
    printf("Preenche alunos\n");
    for(int i = 0; i < tam; i++){
        vetor[i].matricula = i + 1;
        printf("Matricula aluno: %d\n", vetor[i].matricula);
        printf("Digite o nome do aluno: ");
        getchar();
        fgets(vetor[i].nome, 20, stdin);
        float totalNotas = 0;
        for(int j = 0; j < 3; j++){
            printf("Digite a nota %d: ", j + 1);
            scanf("%f", &vetor[i].notas[j]);
            totalNotas += vetor[i].notas[j];
        }
        vetor[i].media = totalNotas / 3;
        printf("Media: %.2f\n\n", vetor[i].media);
    }
}


int main(){
    printf("Digite o tamanho do vetor: ");
    int tamv1;
    scanf("%d", &tamv1);
    int* v1 = (int*) malloc(tamv1*sizeof(int));
    preencheVetor(v1, tamv1);

    printf("\nDigite o valor para usar a busca sequencial: ");
    int val;
    scanf("%d", &val);
    int pos = buscaSequencial(v1, tamv1, val);
    printf("\nPosicao: %d", pos);

    printf("\nDigite o valor para usar a busca binaria: ");
    scanf("%d", &val);
    pos = buscaBinaria(v1, tamv1, val);
    printf("\nPosicao: %d\n--------\n\n", pos);

    printf("Digite o numero de alunos: ");
    int tamv2;
    scanf("%d", &tamv2);
    Aluno* alunos = (Aluno*) malloc(tamv2 * sizeof(Aluno));
    preencheAlunos(alunos, tamv2);

    printf("\nDigite o valor para usar a busca sequencial (Matricula Alunos): ");
    scanf("%d", &val);
    pos = buscaSequencialAluno(alunos, tamv2, val);
    printf("\nPosicao: %d", pos);

    printf("\nDigite o valor para usar a busca binaria (Matricula Alunos): ");
    scanf("%d", &val);
    pos = buscaBinariaAluno(alunos, tamv2, val);
    printf("\nPosicao: %d\n\n", pos);

    free(v1); free(alunos);
    return 0;
}