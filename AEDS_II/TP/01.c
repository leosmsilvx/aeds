#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

typedef struct monte{ 
	int valor;
	char naip;
	struct monte *prox;
	struct monte *ant;
} Monte;

typedef struct jogador{
    Monte *ini, *fim;
    char nome[100];
    int tam;
} Jogador;

void freeJogador(Jogador *p, int tam) {
    for (int i = 0; i < tam; i++) {
        Monte *monte, *temp;
        monte = p[i].ini;
        if(monte != NULL) {
            while(monte->prox != NULL) {
                temp = monte;
                monte = monte->prox;
                free(temp);
            }
        }
        free(monte);
    }
    free(p);
}


int estaVazio (Jogador *p, int i) {
    if(p[i].ini == NULL)
        return 1;
    return 0;
}

int comparaPlayers(Jogador *p, int vez, int q, int i) {
    Monte *aux1, *aux2;
    aux1 = p[vez].fim;
    for (int j = i; j < q; j++) {
        aux2 = p[j].fim;
        if (estaVazio(p, j) == 0 && j != vez) {
            if (aux1->valor == aux2->valor) {
                    return j;
            }
        }
    }
    return -1;
}

Monte* achaPosJogador(Jogador *m, int tam, int q) {
    Monte *aux;
    aux = m[tam].ini;
    for (int i = 1; i<= q; i++) {
        if (i != 1){
            aux = aux->prox;
        }
    }
    return aux;
}

Monte* removeIni(Jogador *area) {
    Monte *aux, *aux2;
    aux = area->ini;
    area->ini = aux->prox;
    aux2 = area->ini;
    aux2->ant = NULL;
    return aux;
}

Monte* removeFim(Jogador *area, int vez) { 
    Monte *aux, *aux2;
    aux = area[vez].fim;
    aux2 = aux->ant;
    area[vez].fim = aux2;
    aux2->prox = NULL;
    return aux;
}

Monte* removeMid(Jogador *area, int pd) {
    Monte *aux, *auxant, *auxPosterior;
    aux = achaPosJogador(area, 0, pd);
    auxant = achaPosJogador(area, 0, pd-1);
    auxPosterior = achaPosJogador(area, 0,pd+1);
    auxant->prox = auxPosterior;
    auxPosterior->ant = auxant;
    return aux;
}

Monte* removeAll(Jogador *area, int vez) {
    Monte *aux;
    aux = area[vez].fim;
    area[vez].ini = NULL;
    area[vez].fim = NULL;
    return aux;
}

void roubaMonte(Jogador *p, int vez, int escolha) {
    Monte *aux, *aux2;
    aux = p[vez].fim;
    aux2 = p[escolha].ini;

    aux->prox = p[escolha].ini;
    aux2->ant = p[vez].fim;
    aux2 = p[escolha].fim;

    p[vez].fim = aux2;
    p[escolha].fim = NULL;
    p[escolha].ini = NULL;

    p[vez].tam += p[escolha].tam;
    p[escolha].tam = 0;
}

int trocaMonte(Jogador *p, int vez, int escolha) {
    int comparacao = comparaPlayers(p, vez, escolha+1, escolha);

    Monte *aux, *aux2;
    aux = p[vez].fim;
    aux2 = p[escolha].fim;
    if (comparacao == -1){
        return 0;

    } else {
        roubaMonte(p, vez, escolha);
        return 1;
    }
}

void verificaPosicao(Jogador *p, Jogador *area, int pd, int vez, int quantos) { 
    Monte *aux, *aux2;
    if(area->tam == 1) {
        aux = removeAll(area, 0);
    }
    else if (area->tam == pd) {
        aux = removeFim(area, 0);
    }
    else if (pd == 1) {
        aux = removeIni(area);
    }
    else {
        aux = removeMid(area, pd);
    }
    aux->ant = p[vez].fim;
    aux2 = aux->ant;
    aux2->prox = aux;
    aux->ant = aux2;
    aux->prox = NULL;
    p[vez].fim = aux;
    p[vez].tam++;
    area->tam--;
}

void escolhaPlayer(Jogador *p, Jogador *area, int pd, int vez, int quantos, int igualPlayer) {
    int escolha, igual = 0;
    scanf("%d", &escolha);
    switch (escolha) {
        case 0:
            verificaPosicao(p, area, pd, vez, quantos);
            break;
        default:
            escolha--;
            igual = trocaMonte(p, vez, escolha);
            if(igual == 0) {
                printf("\nEsse jogador não tem o topo igual o seu.");
                printf("\nVocê pode trocar com o jogador %d.", igualPlayer+1);
                printf("\n1 = Trocar\n2 = Nao trocar.\nEscolha: ");
                scanf("%d", &escolha);
                if(escolha == 1)
                    trocaMonte(p, vez, igualPlayer);
            }
            break;
    }
}

void imprimeElementos(Jogador *l, int vez) { 
	Monte *aux;
	int i = 1;
	aux = l[vez].ini;
    printf("| ");
	while (aux != NULL) {
		printf ("%d de %c | ", aux->valor, aux->naip);
		aux = aux->prox;
		i++;
	}
}

void imprimeDescarte(Jogador *area) {
    printf("\nArea de Descarte:\n");
    imprimeElementos(area, 0);
    printf("\n");
}

void imprimeTopo(Jogador *p, int vez) {
    Monte *aux;
    aux = p[vez].fim;
    printf("| %d de %c |\n", aux->valor, aux->naip);
}

void addPrimeiraCarta(Jogador *area, Monte *aux, int vez) {
    aux->prox = area[vez].ini;
    aux->ant = NULL;
    area[vez].ini = aux;
    area[vez].fim = aux;
}

void addFinal(Jogador *area, Monte *aux, int vez) {
    Monte *aux2;
    aux2 = area[vez].fim;
    aux->ant = area[vez].fim;
    area[vez].fim = aux;
    aux2->prox = area[vez].fim;
}

void addIni(Jogador *area, Monte *aux) {
    aux->prox = area->ini;
    aux->ant = NULL;
    area->ini = aux;
}

void addDescarte(Jogador *area, Jogador *p,int vez) {
    Monte *aux, *aux2;
    aux2 = p[vez].ini;
    if(aux2->prox != NULL){
        aux = removeFim(p,vez);
    }
    else {
        aux = removeAll(p,vez);
    }

    if(area->tam == 0){
        area->ini = aux;
        area->fim = aux;
        aux->prox = NULL;
        aux->ant = NULL;
    }
    else {
        aux2 = area->ini;
        aux->prox = area->ini;
        aux->ant = NULL;
        area->ini = aux;
        aux2->ant = area->ini;
    }
    area->tam++;
    p[vez].tam--;
}

int comparaDescarte(Jogador *p, int vez, Jogador *area) { 
    if (estaVazio(area, 0) == 1)
        return -1;

    Monte *aux1, *aux2;
    aux1 = p[vez].fim;
    aux2 = area->ini;

    for (int i = 1; i <= area->tam; i++) {
        if (aux1->valor == aux2->valor) {
            return i;
        }
        aux2 = aux2->prox;
    }

    return -1;
}

void puxaCarta(Jogador *p, Jogador *m, int vez){
    Monte *aux;

    if(m->tam == 1)
        aux = removeAll(m, 0);
    else
        aux = removeFim(m, 0);

    if(p[vez].ini == NULL)
        addPrimeiraCarta(p, aux, vez);
    else
        addFinal(p, aux, vez);

    m->tam--;
    p[vez].tam++;
}

void embaralhaCartas (Jogador *m, int q) { 
    srand(time(NULL));
    Monte *aux1, *aux2;
    int troca;
    char trocaN;
    for (int i = 0; i <= 2*q; i++) {
        int random = rand() % q+1;
        int r = rand() % q+1;
        aux1 = achaPosJogador(m, 0, random);
        aux2 = achaPosJogador(m, 0, r);
        troca = aux1->valor;
        trocaN = aux1->naip;
        aux1->valor = aux2->valor;
        aux1->naip = aux2->naip;
        aux2->valor = troca;
        aux2->naip = trocaN;
    }
}

void transformaNaips(Monte *c ,int i,int q) {
    int aux;
    aux = ((i+q) % 4)+1;
    switch (aux){
        case 1:
            c->naip = 'P';
            break;
        case 2:
            c->naip = 'O';
            break;
        case 3:
            c->naip = 'E';
            break;
        case 4:
            c->naip = 'C';
            break;
    }
}

void primeiraCartaMonte(Jogador *m, int q) {
    Monte *cartas;
    cartas = (Monte*) malloc(sizeof(Monte));
    m->tam = q;
    cartas->ant = NULL;
    cartas->prox = NULL;
    cartas->valor = 1;
    transformaNaips(cartas ,1, q);
    m->ini = cartas;
    m->fim = cartas;
}

void criaMonte(Jogador *m, int q) {
    primeiraCartaMonte(m, q);
    int naipe, i = 1;
    while (i < q) {
        Monte *carta, *auxiliar;
        carta = (Monte*) malloc(sizeof(Monte));
        auxiliar = m->fim;
        auxiliar->prox = carta;
        carta->ant = auxiliar;
        carta->prox = NULL;
        carta->valor = (i%13)+1;
        transformaNaips(carta ,i, q);
        m->fim = carta;
        i++;
    }

}

Jogador *criaJogadores(int q) {
	Jogador *l;
	l = (Jogador*) malloc(q * sizeof(Jogador));
	if (l == NULL)
		exit(1);
	else {
        for (int i = 0; i < q; i++) {
            l[i].ini = NULL;
            l[i].tam = 0;
            l[i].fim = NULL;
        }
		return l;
	}
}

void sortRank(Jogador *p, int qp){ 
    Jogador aux;
    for (int i = 0; i < qp; i++) {
        for (int j = i ; j < qp-i; j++) {
            if(p[j].tam > p[j-1].tam) {
                aux = p[j];
                p[j] = p[j-1];
                p[j-1] = aux;
            }
        }
    }
}

int main() {    
    Jogador *players;
    Jogador *montePrincipal;
    Jogador *monteDescarte;

    int qntsPlayers;
    int vezJogador = 0;
    int qntsCartasMonte;
    int opt;
    int maxCartasJogadores;

    printf("Numero de jogadores: ");
    scanf("%d", &qntsPlayers);

    players = criaJogadores(qntsPlayers);
    montePrincipal = criaJogadores(1);
    monteDescarte = criaJogadores(1);

    for (int i = 0; i < qntsPlayers; i++) {
        printf("Nome do jogador %d: ", i+1);
        setbuf(stdin, NULL);
        fgets(players[i].nome, 100, stdin);
    }

    printf("Numero de cartas do baralho: ");
    scanf("%d", &qntsCartasMonte);
    criaMonte(montePrincipal, qntsCartasMonte);
    embaralhaCartas (montePrincipal, qntsCartasMonte);

    while (true) {
        int igualPlayer = -1;
        int posicaoIgual = 0;
        int posicaoIgualDescarte;
        puxaCarta(players, montePrincipal, vezJogador);
        printf("\n--------------------------------------");
        printf("\nVez de %sCarta tirada: ", players[vezJogador].nome);
        imprimeTopo(players, vezJogador);

        for (int j = 0; j < qntsPlayers; j++) {
            if (j != vezJogador) {
                if (estaVazio(players, j) == 0){
                    printf("\nTopo do jogador %s", players[j].nome);
                    imprimeTopo(players, j);
                }
            }
        }
        if (estaVazio(monteDescarte, 0) == 0)
            imprimeDescarte(monteDescarte);

        for (int i = 0; i < qntsPlayers; i++) {
            if (i != vezJogador) {
                posicaoIgual = comparaPlayers(players, vezJogador, qntsPlayers, i);
                if(posicaoIgual != -1) {
                    i = posicaoIgual;
                    printf("\nA sua carta é igual a do jogador %s: ", players[i].nome);
                    imprimeTopo(players, i);
                    printf("\nO jogador %s possui %d cartas.\nPressione %d para pegar o monte dele: ",players[i].nome, players[i].tam, i+1);
                    igualPlayer = i;
                }
            }
        }

        posicaoIgualDescarte = comparaDescarte(players, vezJogador, monteDescarte);

        if(posicaoIgualDescarte != -1) {
            printf("\nVocê tirou uma carta que está no descarte, pressione 0 para pega-la: ");
        }

        if(posicaoIgualDescarte != -1 || igualPlayer != -1) {
            opt = 0;
        }
        else {
            opt = -1;
        }

        switch(opt) {
            case -1:
                printf("\nSua carta foi para a zona de descarte.");
                addDescarte(monteDescarte, players, vezJogador);
                printf("\nPressione qualquer tecla para continuar.");
                setbuf(stdin, NULL);
                getchar();
                break;
            case 0:
                escolhaPlayer(players, monteDescarte ,posicaoIgualDescarte, vezJogador, qntsPlayers, igualPlayer);
                break;
        }

        if(opt == -1){
            if (vezJogador == qntsPlayers-1)
                vezJogador = 0;
            else
                vezJogador++;
        }

        if(montePrincipal->ini == NULL) {
            break;
        }
    }

    int i = 0;
    sortRank(players, qntsPlayers);
    maxCartasJogadores = players[0].tam;

    for (int i = 0; i < qntsPlayers; i++) {
        if(players[i].tam == maxCartasJogadores) {
            printf("\n\n%sVocê ganhou!", players[i].nome);
        }
    }

    freeJogador(players, qntsPlayers);
    free(montePrincipal);
    freeJogador(monteDescarte, 1);

	return 0;
}