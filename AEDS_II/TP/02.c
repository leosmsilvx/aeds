#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define MAXVETA 1000
#define MAXVETB 10000
#define MAXVETC 100000
#define MAXVETD 200000

typedef struct aluno {
    int num_matricula;
    char nm_aluno[255];
    char nm_curso[255];
    double num_rendimento;
    int num_periodo;
} Aluno;

int comparaAlunos(Aluno a, Aluno b, int *numComparacoes) {
    (*numComparacoes)++;
    if(a.num_rendimento > b.num_rendimento)
        return -1;
    else if(a.num_rendimento < b.num_rendimento)
        return 1;
    else {
        if (strcmp(a.nm_aluno, b.nm_aluno) < 0) {
            return -1;
        } else if (strcmp(a.nm_aluno, b.nm_aluno) > 0) {
            return 1;
        } else {
            if (strcmp(a.nm_curso, b.nm_curso) < 0) {
                return -1;
            } else if (strcmp(a.nm_curso, b.nm_curso) > 0) {
                return 1;
            } else {
                if (a.num_matricula > b.num_matricula) {
                    return 1;
                } else if (a.num_matricula < b.num_matricula) {
                    return -1;
                } else {
                    return 0;
                }
            }
        }
    }
}

void trocaAlunos(Aluno *a, Aluno *b) {
  Aluno temp = *a;
  *a = *b;
  *b = temp;
}

void selectsort(Aluno *v, int tamVet, int *numComparacoes, int *numTrocas) {
  int i, j, min;
  for (i = 0; i < tamVet - 1; i++) {
    min = i;
    for (j = i + 1; j < tamVet; j++) {
      if (comparaAlunos(v[j], v[min], numComparacoes) < 0) {
        (*numComparacoes)++;
        min = j;
      }
    }

    if (min != i) {
      (*numTrocas)++;
      trocaAlunos(&v[i], &v[min]);
    }
  }
}


void insertsort(Aluno *v, int n, int *numComparacoes, int *numTrocas) {
  int i, j;

  for (i = 1; i < n; i++) {
    Aluno aux = v[i];

    j = i - 1;
    while (j >= 0 && comparaAlunos(v[j], aux, numComparacoes) > 0) {
      (*numTrocas)++;
      trocaAlunos(&v[j + 1], &v[j]);
      j--;
    }

    v[j + 1] = aux;
  }
}

int getPivo(int inicio, int fim, int mid, Aluno *v){
    double a = v[inicio].num_rendimento;
    double b = v[mid].num_rendimento;
    double c = v[fim].num_rendimento;

    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    if (a > c) {
        int temp = a;
        a = c;
        c = temp;
    }

    if(a == v[inicio].num_rendimento) return inicio;
    if(a == v[mid].num_rendimento) return mid;
    if(a == v[fim].num_rendimento) return fim;
}

void particionar(int ini, int fim, int *i, int *j, Aluno *v, int *numComparacoes, int *numTrocas){
    int pivo, temp;
    *i = ini;
    *j = fim;
    int mid = (*i+*j)/2;
    pivo = getPivo(*i, *j, mid, v);
    do{
        while(comparaAlunos(v[pivo], v[*i], numComparacoes) > 0){
            ++(*i);
        }

        while(comparaAlunos(v[pivo], v[*j], numComparacoes) < 0){
            --(*j);
        }

        if(*i <= *j){
            (*numTrocas)++;
            trocaAlunos(&v[*i], &v[*j]);
            ++(*i);
            --(*j);
        }
    } while(*i <= *j);
}

void quicksort(int ini, int fim, Aluno *v, int *numComparacoes, int *numTrocas){
    int i, j;
    particionar(ini, fim, &i, &j, v, numComparacoes, numTrocas);
    if(ini < j) quicksort(ini, j, v, numComparacoes, numTrocas);
    if(i < fim) quicksort(i, fim, v, numComparacoes, numTrocas);
}

void intercala (int p, int q, int r, Aluno *v, int *numComparacoes, int *numTrocas){
   int i, j;
   Aluno *w = malloc((r-p)*sizeof(Aluno));

   for (i = p; i < q; ++i) w[i-p] = v[i];
   for (j = q; j < r; ++j) w[r-p+q-j-1] = v[j];
   i = 0; j = r-p-1;
   for (int k = p; k < r; ++k)
      if (comparaAlunos(w[i], w[j], numComparacoes) <= 0){
        v[k] = w[i++];
        (*numTrocas)++;
      } 
      else {
        v[k] = w[j--];        
        (*numTrocas)++;
      } 
   free (w);
}

void mergesort (int p, int r, Aluno *v, int *numComparacoes, int *numTrocas) {
   if (p < r-1) {                
      int q = (p + r)/2;          
      mergesort (p, q, v, numComparacoes, numTrocas);        
      mergesort (q, r, v, numComparacoes, numTrocas);        
      intercala (p, q, r, v, numComparacoes, numTrocas);     
   }
}

void gerarAlunosAleatorios(Aluno *v, int n) {
    for (int i = 0; i < n; i++) {
        v[i].num_matricula = rand() % n;
        
        char nomeAluno[255];
        int numLetras = 3;
        for(int j = 0; j < numLetras; j++){
            nomeAluno[j] = 'A' + rand() % 26;
        }
        strcpy(v[i].nm_aluno, nomeAluno);
        v[i].nm_aluno[numLetras] = '\0';

        char nomeCurso[255];
        for(int j = 0; j < numLetras; j++){
            nomeCurso[j] = 'A' + rand() % 26;
        }
        strcpy(v[i].nm_curso, nomeCurso);
        v[i].nm_curso[numLetras] = '\0';

        v[i].num_rendimento = rand() % 10;

        v[i].num_periodo = rand() % 10;
    }
}

void gerarAlunosOrdenados(Aluno *v, int n) {
    gerarAlunosAleatorios(v, n);
    int i = 0, j = 0;
    quicksort(0, n, v, &i, &j);
}

void gerarAlunosInvOrdenados(Aluno *v, int n) {
    gerarAlunosOrdenados(v, n);

    for (int i = 0; i < n / 2; i++) {
        trocaAlunos(&v[i], &v[n - 1 - i]);
    }
}


void imprimeAlunos(Aluno *v, int tamVet){
    for(int i = 0; i < tamVet; i++){
        printf("Aluno %d: %s | %.2f | %s | %d |\n", 
            v[i].num_matricula,
            v[i].nm_aluno,
            v[i].num_rendimento,
            v[i].nm_curso,
            v[i].num_periodo);
    }
}

void copiaVetor(Aluno *v1, Aluno *v2, int tamVet){
    for(int i = 0; i < tamVet; i++){
        v2[i] = v1[i];
    }
}

int tipoVetor(){
    bool opt = true;
    int optEscolha;
    do {
        printf("\nOpcoes:\n");
        printf("1 - Aleatorio;\n");        
        printf("2 - Ordenado;\n");        
        printf("3 - Inversamente ordenado;\n");        
        printf("Selecione um tipo de vetor:\n");   
        scanf("%d", &optEscolha);        
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        if(optEscolha == 1){
            opt = false;
        } else if(optEscolha == 2){
            opt = false;
        } else if(optEscolha == 3){
            opt = false;
        } else {
            printf("Escolha uma opcao valida.\n");
            continue;
        }
    } while(opt);
    return optEscolha;
}

void alunos1k(int tipoVetor){
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    Aluno alunos1000[MAXVETA];
    int tipoAleatorio = 1;
    int tipoOrdenado = 2;
    int tipoInvOrdenado = 3;
    if(tipoVetor == tipoAleatorio){
        gerarAlunosAleatorios(alunos1000, MAXVETA);
        printf("Vetor aleatorio");
    } else if (tipoVetor == tipoOrdenado){
        gerarAlunosOrdenados(alunos1000, MAXVETA);
        printf("Vetor ordenado");
    } else if(tipoVetor == tipoInvOrdenado){
        printf("Vetor inversamente ordenado");
        gerarAlunosInvOrdenados(alunos1000, MAXVETA);
    }
    
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    imprimeAlunos(alunos1000, MAXVETA);

    bool opt = true;
    int optEscolha;
    do {
        printf("\nOpcoes:\n");
        printf("1 - Select sort;\n");        
        printf("2 - Insert sort;\n");        
        printf("3 - Quick sort;\n");        
        printf("4 - Merge sort;\n");
        printf("0 - Sair;\n");     
        printf("Selecione um metodo de ordenacao:\n");   
        scanf("%d", &optEscolha);        
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        if(optEscolha == 0){
            opt = false;
            continue;
        }

        Aluno alunos1000Copia[MAXVETA];
        copiaVetor(alunos1000, alunos1000Copia, MAXVETA);
        int numComparacoes = 0;        
        int numTrocas = 0;
        
        if(optEscolha == 1){
            printf("SelectSort\n");
            selectsort(alunos1000Copia, MAXVETA, &numComparacoes, &numTrocas);
        }
        else if(optEscolha == 2){
            printf("InsertSort\n");
            insertsort(alunos1000Copia, MAXVETA, &numComparacoes, &numTrocas);
        }
        else if(optEscolha == 3){
            printf("QuickSort\n");
            quicksort(0, MAXVETA, alunos1000Copia, &numComparacoes, &numTrocas);
        }
        else if(optEscolha == 4){
            printf("MergeSort\n");
            mergesort(0, MAXVETA, alunos1000Copia, &numComparacoes, &numTrocas);
        } else {
            printf("Selecione uma opcao valida.\n");
            continue;
        }
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        imprimeAlunos(alunos1000Copia, MAXVETA);
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("Numero de comparacoes: %d | Numero de trocas: %d\n", numComparacoes, numTrocas);
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    } while(opt);
}

void alunos10k(int tipoVetor){
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    Aluno alunos10k[MAXVETB];
    int tipoAleatorio = 1;
    int tipoOrdenado = 2;
    int tipoInvOrdenado = 3;
    if(tipoVetor == tipoAleatorio){
        gerarAlunosAleatorios(alunos10k, MAXVETB);
        printf("Vetor aleatorio");
    } else if (tipoVetor == tipoOrdenado){
        gerarAlunosOrdenados(alunos10k, MAXVETB);
        printf("Vetor ordenado");
    } else if(tipoVetor == tipoInvOrdenado){
        printf("Vetor inversamente ordenado");
        gerarAlunosInvOrdenados(alunos10k, MAXVETB);
    }
    
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    imprimeAlunos(alunos10k, MAXVETB);

    bool opt = true;
    int optEscolha;
    do {
        printf("\nOpcoes:\n");
        printf("1 - Select sort;\n");        
        printf("2 - Insert sort;\n");        
        printf("3 - Quick sort;\n");        
        printf("4 - Merge sort;\n");
        printf("0 - Sair;\n");     
        printf("Selecione um metodo de ordenacao:\n");   
        scanf("%d", &optEscolha);        
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        if(optEscolha == 0){
            opt = false;
            continue;
        }

        Aluno alunos10kCopia[MAXVETB];
        copiaVetor(alunos10k, alunos10kCopia, MAXVETB);
        int numComparacoes = 0;        
        int numTrocas = 0;
        
        if(optEscolha == 1){
            printf("SelectSort\n");
            selectsort(alunos10kCopia, MAXVETB, &numComparacoes, &numTrocas);
        }
        else if(optEscolha == 2){
            printf("InsertSort\n");
            insertsort(alunos10kCopia, MAXVETB, &numComparacoes, &numTrocas);
        }
        else if(optEscolha == 3){
            printf("QuickSort\n");
            quicksort(0, MAXVETB, alunos10kCopia, &numComparacoes, &numTrocas);
        }
        else if(optEscolha == 4){
            printf("MergeSort\n");
            mergesort(0, MAXVETB, alunos10kCopia, &numComparacoes, &numTrocas);
        } else {
            printf("Selecione uma opcao valida.\n");
            continue;
        }
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        imprimeAlunos(alunos10kCopia, MAXVETB);
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("Numero de comparacoes: %d | Numero de trocas: %d\n", numComparacoes, numTrocas);
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    } while(opt);
}

void alunos100k(int tipoVetor){
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    Aluno alunos100k[MAXVETC];
    int tipoAleatorio = 1;
    int tipoOrdenado = 2;
    int tipoInvOrdenado = 3;
    if(tipoVetor == tipoAleatorio){
        gerarAlunosAleatorios(alunos100k, MAXVETC);
        printf("Vetor aleatorio");
    } else if (tipoVetor == tipoOrdenado){
        gerarAlunosOrdenados(alunos100k, MAXVETC);
        printf("Vetor ordenado");
    } else if(tipoVetor == tipoInvOrdenado){
        printf("Vetor inversamente ordenado");
        gerarAlunosInvOrdenados(alunos100k, MAXVETC);
    }
    
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    imprimeAlunos(alunos100k, MAXVETC);

    bool opt = true;
    int optEscolha;
    do {
        printf("\nOpcoes:\n");
        printf("1 - Select sort;\n");        
        printf("2 - Insert sort;\n");        
        printf("3 - Quick sort;\n");        
        printf("4 - Merge sort;\n");
        printf("0 - Sair;\n");     
        printf("Selecione um metodo de ordenacao:\n");   
        scanf("%d", &optEscolha);        
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        if(optEscolha == 0){
            opt = false;
            continue;
        }

        Aluno alunos100kCopia[MAXVETC];
        copiaVetor(alunos100k, alunos100kCopia, MAXVETC);
        int numComparacoes = 0;        
        int numTrocas = 0;
        
        if(optEscolha == 1){
            printf("SelectSort\n");
            selectsort(alunos100kCopia, MAXVETC, &numComparacoes, &numTrocas);
        }
        else if(optEscolha == 2){
            printf("InsertSort\n");
            insertsort(alunos100kCopia, MAXVETC, &numComparacoes, &numTrocas);
        }
        else if(optEscolha == 3){
            printf("QuickSort\n");
            quicksort(0, MAXVETC, alunos100kCopia, &numComparacoes, &numTrocas);
        }
        else if(optEscolha == 4){
            printf("MergeSort\n");
            mergesort(0, MAXVETC, alunos100kCopia, &numComparacoes, &numTrocas);
        } else {
            printf("Selecione uma opcao valida.\n");
            continue;
        }
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        imprimeAlunos(alunos100kCopia, MAXVETC);
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("Numero de comparacoes: %d | Numero de trocas: %d\n", numComparacoes, numTrocas);
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    } while(opt);
}

void alunos200k(int tipoVetor){
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    Aluno alunos200k[MAXVETD];
    int tipoAleatorio = 1;
    int tipoOrdenado = 2;
    int tipoInvOrdenado = 3;
    if(tipoVetor == tipoAleatorio){
        gerarAlunosAleatorios(alunos200k, MAXVETD);
        printf("Vetor aleatorio");
    } else if (tipoVetor == tipoOrdenado){
        gerarAlunosOrdenados(alunos200k, MAXVETD);
        printf("Vetor ordenado");
    } else if(tipoVetor == tipoInvOrdenado){
        printf("Vetor inversamente ordenado");
        gerarAlunosInvOrdenados(alunos200k, MAXVETD);
    }
    
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    imprimeAlunos(alunos200k, MAXVETD);

    bool opt = true;
    int optEscolha;
    do {
        printf("\nOpcoes:\n");
        printf("1 - Select sort;\n");        
        printf("2 - Insert sort;\n");        
        printf("3 - Quick sort;\n");        
        printf("4 - Merge sort;\n");
        printf("0 - Sair;\n");     
        printf("Selecione um metodo de ordenacao:\n");   
        scanf("%d", &optEscolha);        
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        if(optEscolha == 0){
            opt = false;
            continue;
        }

        Aluno alunos200kCopia[MAXVETD];
        copiaVetor(alunos200k, alunos200kCopia, MAXVETD);
        int numComparacoes = 0;        
        int numTrocas = 0;
        
        if(optEscolha == 1){
            printf("SelectSort\n");
            selectsort(alunos200kCopia, MAXVETD, &numComparacoes, &numTrocas);
        }
        else if(optEscolha == 2){
            printf("InsertSort\n");
            insertsort(alunos200kCopia, MAXVETD, &numComparacoes, &numTrocas);
        }
        else if(optEscolha == 3){
            printf("QuickSort\n");
            quicksort(0, MAXVETD, alunos200kCopia, &numComparacoes, &numTrocas);
        }
        else if(optEscolha == 4){
            printf("MergeSort\n");
            mergesort(0, MAXVETD, alunos200kCopia, &numComparacoes, &numTrocas);
        } else {
            printf("Selecione uma opcao valida.\n");
            continue;
        }
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        imprimeAlunos(alunos200kCopia, MAXVETD);
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("Numero de comparacoes: %d | Numero de trocas: %d\n", numComparacoes, numTrocas);
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    } while(opt);
}


int main(){
    srand(time(NULL));
    bool opt = true;
    int optEscolha;
    do{        
        printf("\nOpcoes:\n");        
        printf("1 - 1000;\n");        
        printf("2 - 10000;\n");        
        printf("3 - 100000;\n");        
        printf("4 - 200000;\n");
        printf("0 - Sair;\n");       
        printf("\nSelecione o numero de elementos do vetor:\n"); 
        scanf("%d", &optEscolha);

        if(optEscolha == 0){
            opt = false;
            continue;
        }        

        if(optEscolha == 1){
            int i = tipoVetor();
            alunos1k(i);
        }
        if(optEscolha == 2){
            int i = tipoVetor();
            alunos10k(i);
        }
        if(optEscolha == 3){
            int i = tipoVetor();
            alunos100k(i);
        }
        if(optEscolha == 4){
            int i = tipoVetor();
            alunos200k(i);
        }
    }while(opt);
    system("cls");
    return 0;
}