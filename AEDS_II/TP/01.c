#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

typedef struct Monte{ 
	int valor;
	char naip;
	struct Monte *proximo;
	struct Monte *anterior;
} monte;

typedef struct Jogador{
    monte *inicio, *fim;
    char nome[100];
    int tam;
}jogador;

void freeCarta(jogador *p, int tam) {
    for (int i = 0; i < tam; i++) {
        monte *monte, *temp;
        monte = p[i].inicio;
        if(monte != NULL) {
            while(monte->proximo != NULL) {
                temp = monte;
                monte = monte->proximo;
                free(temp);
            }
        }
        free(monte);
    }
    free(p);
}

void organizaRanking (jogador *p, int qp){ //usa o método bubblesorte para ordenar o vetor de players de acordo com o maior numero de cartas
    jogador aux;
    int i;
    int j;

    for (i = 0; i < qp; i++) {
        for (j = i ; j < qp-i; j++) {
            if(p[j].tam > p[j-1].tam) {
                aux = p[j];
                p[j] = p[j-1];
                p[j-1] = aux;
            }
        }
    }

}

int contaVencedores(jogador *p, int qp) {
    int qc = 0;
    int qg = 0;
    for (int i = 0; i < qp; i++) {
        if(p[i].tam > qc) {
            qc = p[i].tam;
            qg = 1;
        }
        if (p[i].tam == qc) {
            qg++;
        }
    }
    return qg;
}

int comparaPlayers(jogador *p, int vez, int q, int i) { //Compara a carta da vez com o monte dos outros players

    monte *aux1, *aux2;
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

monte *achaPosicao(jogador *m, int tam, int q) { //acha a posição de um objeto na lista dinâmica

    monte *aux;
    aux = m[tam].inicio;
    for (int i = 1; i<= q; i++) {
        if (i != 1)
            aux = aux->proximo;
    }
    return aux;
}

monte *retiraInicio(jogador *area) { //encontra e "retira" do monte a primeira carta
    monte *aux, *aux2;
    aux = area->inicio;
    area->inicio = aux->proximo;
    aux2 = area->inicio;
    aux2->anterior = NULL;
    return aux;
}

monte *retiraFim(jogador *area, int vez) { //encontra e "retira" do monte a última carta
    monte *aux, *aux2;
    aux = area[vez].fim;
    aux2 = aux->anterior;
    area[vez].fim = aux2;
    aux2->proximo = NULL;
    return aux;
}

monte *retiraMeio(jogador *area, int pd) { //encontra e "retira" do monte alguma carta do meio
    monte *aux, *auxAnterior, *auxPosterior;
    aux = achaPosicao(area, 0, pd);
    auxAnterior = achaPosicao(area, 0, pd-1);
    auxPosterior = achaPosicao(area, 0,pd+1);
    auxAnterior->proximo = auxPosterior;
    auxPosterior->anterior = auxAnterior;
    return aux;
}

monte *retiraTudo(jogador *area, int vez) { //encontra e "retira" do monte a única carta
    monte *aux;
    aux = area[vez].fim;
    area[vez].inicio = NULL;
    area[vez].fim = NULL;
    return aux;
}

void roubaMonte(jogador *p, int vez, int escolha) { //efetivamente rouba o monte do jogador escolhido

    monte *aux, *aux2;
    aux = p[vez].fim;
    aux2 = p[escolha].inicio;

    aux->proximo = p[escolha].inicio;
    aux2->anterior = p[vez].fim;
    aux2 = p[escolha].fim;

    p[vez].fim = aux2;
    p[escolha].fim = NULL;
    p[escolha].inicio = NULL;

    p[vez].tam += p[escolha].tam;
    p[escolha].tam = 0;

}

int trocaPlayer(jogador *p, int vez, int escolha) { //verifica se a carta do player escolhido para trocar o monte realmente é igual a carta da vez, caso seja, rouba o monte

    int comparacao = comparaPlayers(p, vez, escolha+1, escolha);

    monte *aux, *aux2;
    aux = p[vez].fim;
    aux2 = p[escolha].fim;

    if (comparacao == -1)
        return 0;
    else {
        roubaMonte(p, vez, escolha);
        return 1;
    }
}

void verificaPosicao(jogador *p, jogador *area, int pd, int vez, int quantos) { //Verifica se a carta retirada do monte está no início, meio, fim, ou, se ela é a única. E a coloca no fim do monte do player
    monte *aux, *aux2;
    if(area->tam == 1) { //se a area de descarte tiver somente um elemento, deverá ter um código diferente
        aux = retiraTudo(area, 0);
    }
    else if (area->tam == pd) { //se a posição em que a carta é igual na area de descarte for a última, deverá ter um código diferente
        aux = retiraFim(area, 0);
    }
    else if (pd == 1) { //se a posição em que a carta é igual na area de descarte for a primeira, deverá ter um código diferente
        aux = retiraInicio(area);
    }
    else {
        aux = retiraMeio(area, pd); //caso não seja a ultima nem a primeira, ela estará no meio
    }
    aux->anterior = p[vez].fim;
    aux2 = aux->anterior;
    aux2->proximo = aux;
    aux->anterior = aux2;
    aux->proximo = NULL;
    p[vez].fim = aux;
    p[vez].tam++;
    area->tam--;
}

void escolhaPlayer(jogador *p, jogador *area, int pd, int vez, int quantos, int igualPlayer) { //executa a escolha do player

    int escolha, igual = 0;
    scanf("%d", &escolha);
    switch (escolha) {
        case 0:
            verificaPosicao(p, area, pd, vez, quantos);
            break;
        default:
            escolha--;
            igual = trocaPlayer(p, vez, escolha);
            if(igual == 0) {
                printf("\nImpossível trocar, este player não tem o topo igual o seu! ");
                printf("\nMas você pode trocar com o jogador %d se quiser", igualPlayer+1);
                printf("\n1 = QUERO\n2 = NÃO QUERO.\nEscolha: ");
                scanf("%d", &escolha);
                if(escolha == 1)
                    trocaPlayer(p, vez, igualPlayer);
            }
            break;
    }
}

void imprimeDescarte(jogador *area) { //Imprime os elementos da area de descarte
    printf("\nCartas da Area de Descarte:\n");
    imprimeElementos(area, 0);
    printf("\n");
}

void imprimeTopo(jogador *p, int vez) {//imprime o topo do monte de cada jogador
    monte *aux;
    aux = p[vez].fim;
    printf("%d de %c\n", aux->valor, aux->naip);
}

void incluiPrimeiraCarta(jogador *area, monte *aux, int vez) { //inclui a primeira carta no monte
    aux->proximo = area[vez].inicio;
    aux->anterior = NULL;
    area[vez].inicio = aux;
    area[vez].fim = aux;
}

void incluiFinal(jogador *area, monte *aux, int vez) {
    monte *aux2;
    aux2 = area[vez].fim;
    aux->anterior = area[vez].fim;
    area[vez].fim = aux;
    aux2->proximo = area[vez].fim;
}

void incluiInicio(jogador *area, monte *aux) { //inclui uma carta no início do monte
    aux->proximo = area->inicio;
    aux->anterior = NULL;
    area->inicio = aux;
}

void incluirDescarte(jogador *area, jogador *p,int vez) { //inclui a carta da vez na zona de descarte caso ela ão seja igual a de nenhum player
    monte *aux, *aux2;
    aux2 = p[vez].inicio;
    if(aux2->proximo != NULL){
        aux = retiraFim(p,vez);
    }
    else {
        aux = retiraTudo(p,vez);
    }

    if(area->tam == 0){
        area->inicio = aux;
        area->fim = aux;
        aux->proximo = NULL;
        aux->anterior = NULL;
    }
    else {
        aux2 = area->inicio;
        aux->proximo = area->inicio;
        aux->anterior = NULL;
        area->inicio = aux;
        aux2->anterior = area->inicio;
    }
    area->tam++;
    p[vez].tam--;
}

int comparaDescarte(jogador *p, int vez, jogador *area) { //compara a carta da vez com todas as cartas da area de descarte
    if (estaVazio(area, 0) == 1)
        return -1;

    monte *aux1, *aux2;
    aux1 = p[vez].fim;
    aux2 = area->inicio;

    for (int i = 1; i <= area->tam; i++) {
        if (aux1->valor == aux2->valor) {
            return i;
        }
        aux2 = aux2->proximo;
    }

    return -1;
}

int estaVazio (jogador *p, int i) { //verifica se o monte está vazio
    if(p[i].inicio == NULL)
        return 1;
    return 0;
}

void puxaCarta(jogador *p, jogador *m, int vez){ //responsável por puxar uma carta para o jogador
    monte *aux;

    if(m->tam == 1)
        aux = retiraTudo(m, 0);
    else
        aux = retiraFim(m, 0);

    if(p[vez].inicio == NULL)
        incluiPrimeiraCarta(p, aux, vez);
    else
        incluiFinal(p, aux, vez);



    m->tam--;
    p[vez].tam++;
}

int reiniciaLoop(int vez, int quantos) { //faz o loop voltar no primeiro jogador depois do ultimo
    if (vez == quantos-1)
        vez = 0;
    else
        vez++;
    return vez;
}

void imprimeElementos(jogador *l, int vez) { //imprime os elementos
	monte *aux;
	int i = 1;
	aux = l[vez].inicio;
	while (aux != NULL) {
		printf ("%d carta --> %d de %c  ||  ", i, aux->valor, aux->naip);
		aux = aux->proximo;
		i++;
	}

	return 1;
}

void embaralhaCartas (jogador *m, int q) { //Responsável por embaralhar as cartas do monte
    srand(time(NULL));
    monte *aux1, *aux2;
    int troca;
    char trocaN;
    for (int i = 0; i <= 2*q; i++) {
        int random = rand() % q+1;
        int r = rand() % q+1;
        aux1 = achaPosicao(m, 0, random);
        aux2 = achaPosicao(m, 0, r);
        troca = aux1->valor;
        trocaN = aux1->naip;
        aux1->valor = aux2->valor;
        aux1->naip = aux2->naip;
        aux2->valor = troca;
        aux2->naip = trocaN;
    }
}

void transformaNaips(monte *c ,int i,int q) { //Adiciona um simbolo de naip para as cartas
    int aux;
    aux = ((i+q) % 4)+1;
    switch (aux){
        case 1:
            c->naip = 3;
            break;
        case 2:
            c->naip = 4;
            break;
        case 3:
            c->naip = 5;
            break;
        case 4:
            c->naip = 6;
            break;
    }
}

void primeiraCartaMonte(jogador *m, int q) { //essa parte so cria a primeira carta do monte, ja que para se incluir a primeira carta, é diferente
    monte *cartas;
    cartas = (monte*) malloc(sizeof(monte));
    m->tam = q;
    cartas->anterior = NULL;
    cartas->proximo = NULL;
    cartas->valor = 1;
    transformaNaips(cartas ,1, q);
    m->inicio = cartas;
    m->fim = cartas;
}

void criaMonte(jogador *m, int q){//Cria a pilha de cartas do centro da mesa
    primeiraCartaMonte(m, q);
    int naipe, i = 1;
    while (i < q) {
        monte *carta, *auxiliar;
        carta = (monte*) malloc(sizeof(monte));
        auxiliar = m->fim;
        auxiliar->proximo = carta;
        carta->anterior = auxiliar;
        carta->proximo = NULL;
        carta->valor = (i%13)+1;
        transformaNaips(carta ,i, q);
        m->fim = carta;
        i++;
    }

}

jogador *criaJogadores(int q) { //aloca dinamicamente um vetor de acordo com a quantidade de jogadores escolhida
	jogador *l;
	l = (jogador*) malloc(q * sizeof(jogador));
	if (l == NULL)
		exit(1);
	else {
        for (int i = 0; i < q; i++) {
            l[i].inicio = NULL;
            l[i].tam = 0;
            l[i].fim = NULL;
        }
		return l;
	}
}

void jogo() { //função principal do jogo

    int quantosPlayers; //armazena o numero de pessoas que vão jogar
    int vezdeQuem = 0; //armazena a posição, no vetor, do jogador que está jogando no loop atual
    int quantasCartas; // armazena a quantidade de cartas terão em jogo
    int sair = 1; //define se o jogo acabou
    int opcao; //é a opção que o jogador escolhe
    int maiorQuantidade; //guarda a quantidade de cartas do jogador com mais cartas
    jogador *players; //cria um ponteiro do tipo jogador para representar cada jogador em jogo
    jogador *montePrincipal; //cria um ponteiro do tipo jogador para representar o monte central do game
    jogador *areadeDescarte;//cria um ponteiro do tipo jogador para representar a área de descarte

    printf("Quantos jogadores irão jogar? "); //Salva a quantidade de jogadores
    scanf("%d", &quantosPlayers);

    players = criaJogadores(quantosPlayers); //aloca dinamicamente os players com base na escolha do usuário
    montePrincipal = criaJogadores(1); //aloca o monte principal
    areadeDescarte = criaJogadores(1); //aloca a zona de descarte

    for (int i = 0; i < quantosPlayers; i++) { //Salva o nome dos jogadores
        printf("jogador %d, qual seu nome? ", i+1);
        setbuf(stdin, NULL);
        fgets(players[i].nome, 100, stdin);
    }

    printf("Quantas cartas terão em jogo? ");
    scanf("%d", &quantasCartas);
    criaMonte(montePrincipal, quantasCartas);
    embaralhaCartas (montePrincipal, quantasCartas);

    while (sair != 0) { //cria o loop do jogo

        int igualPlayer = -1; // é a posição em que o último jogador com a carta igual a do player tem
        int posicaoIgual = 0; //é a posição no vetor do player que tem a carta igual a carta principal
        int posicaoIgualDescarte; //é a posição no monte da carta igual a do player na area de descarte
        puxaCarta(players, montePrincipal, vezdeQuem); //jogador da vez puxa a carta

        printf("\nJogador %sA carta que você tirou foi:\n---->", players[vezdeQuem].nome);
        imprimeTopo(players, vezdeQuem);

        for (int j = 0; j < quantosPlayers; j++) {
            if (j != vezdeQuem) {
                if (estaVazio(players, j) == 0){
                    printf("\nCarta do topo do monte do jogador %s", players[j].nome);
                    imprimeTopo(players, j);
                }
            }
        }
        if (estaVazio(areadeDescarte, 0) == 0)
            imprimeDescarte(areadeDescarte);

        for (int i = 0; i < quantosPlayers; i++) {
            if (i != vezdeQuem) {
                posicaoIgual = comparaPlayers(players, vezdeQuem, quantosPlayers, i);
                if(posicaoIgual != -1) {
                    i = posicaoIgual;
                    printf("\nA sua carta é igual a do jogador %s\n---->", players[i].nome);
                    imprimeTopo(players, i);
                    printf("\nEle possui %d cartas.\nPressione %d para pegar o monte dele: ", players[i].tam, i+1);
                    igualPlayer = i;

                    monte *teste, *teste2;
                    teste = players[igualPlayer].fim;
                    teste2 = players[vezdeQuem].fim;
                }
            }
        }

        posicaoIgualDescarte = comparaDescarte(players, vezdeQuem, areadeDescarte);

        if(posicaoIgualDescarte != -1) {
            printf("\nA sua carta é igual a uma carta da zona de descarte, pressione 0 para pega-la: ");
        }

        if(posicaoIgualDescarte != -1 || igualPlayer != -1) { //caso ele tenha a carta igual a de algum lugar possivel, ele tera a opcao de escolher o que quer fazer
            opcao = 0;
        }
        else { //se a variavel opcao for -1, significa que não ha nenhuma carta igual a carta da vez em jogo
            opcao = -1;
        }

        switch(opcao) {
            case -1:
                printf("\nSua carta não é igual a nenhuma outra. Ela irá para a zona de descarte.");
                incluirDescarte(areadeDescarte, players, vezdeQuem);
                printf("\nPressione qualquer tecla para continuar.");
                setbuf(stdin, NULL);
                getchar();
                break;
            case 0:
                escolhaPlayer(players, areadeDescarte ,posicaoIgualDescarte, vezdeQuem, quantosPlayers, igualPlayer);
                break;
        }
        system("cls");

        if(opcao == -1) //so reinicia o loop caso a carta da vez não seja igual a nenhuma outra
            vezdeQuem = reiniciaLoop(vezdeQuem, quantosPlayers);

        if(montePrincipal->inicio == NULL) {
            sair = 0;
        }
    }

    int i = 0;
    organizaRanking(players, quantosPlayers);
    maiorQuantidade = players[0].tam;

    for (int i = 0; i < quantosPlayers; i++) { //printa o nome e a quantidade de cartas dos players que venceram
        if(players[i].tam == maiorQuantidade) {
            printf("\n\nJogador %sVocê ", players[i].nome);
            if(i > 0)
                printf("também ");
            printf("ganhou!\nSuas cartas são:\n\n ");
            imprimeElementos(players, i);
        }
    }

    for (i = 0; i < quantosPlayers; i++) {//coloca os jogadores na ordem do ranking
        printf("\n\nO %d lugar foi o jogador %sEle possui %d cartas.\n", i+1, players[i].nome, players[i].tam);
    }

    freeCarta(players, quantosPlayers);
    free(montePrincipal);
    freeCarta(areadeDescarte, 1);
}

void lerRegras() { //printa todas as regras do jogo
    printf("Regras do Jogo 'Rouba Mentes':\n\n");
    printf("1. As cartas são embaralhadas e colocadas na pilha de compra, com a face voltada para baixo.\n");
    printf("2. Cada jogador mantém um monte de cartas com a face voltada para cima.\n");
    printf("3. No início, todos os montes dos jogadores têm zero cartas.\n");
    printf("4. Ao lado da pilha de compras, há uma área de descarte inicialmente vazia.\n");
    printf("5. Os jogadores jogam em sequência, no sentido horário.\n");
    printf("6. O jogador da vez retira a carta de cima da pilha de compras, mostrando-a aos outros jogadores.\n");
    printf("7. Se a carta da vez for igual a alguma carta na área de descarte, o jogador a retira junto com a carta da vez e as coloca no topo de seu monte.\n");
    printf("8. Se a carta da vez for igual à carta no topo de um monte de outro jogador, o jogador 'rouba' esse monte, adicionando-o ao seu próprio monte.\n");
    printf("9. Se a carta da vez for igual à carta no topo de seu próprio monte, o jogador coloca a carta da vez no topo de seu monte.\n");
    printf("10. Se a carta da vez for diferente das cartas na área de descarte e nos topos dos montes, ela é colocada na área de descarte.\n");
    printf("11. O jogo termina quando não há mais cartas na pilha de compra.\n");
    printf("12. O jogador com o maior monte ao final do jogo é o vencedor.\n");
    printf("13. Em caso de empate, todos os jogadores com o maior monte ganham o jogo.\n");
    printf("14. As cartas são enumeradas de 1 à 13, sendo o 1 = ÁS, 11 = VALETE, 12 = DAMA, 13 = REI.\n");
}

int main() {

    int escolha;
    printf("[̲̅R][̲̅O][̲̅U][̲̅B][̲̅A] [̲̅M][̲̅E][̲̅N][̲̅T][̲̅E][̲̅S]\n");

    do {
        printf("\nO quê você deseja fazer?\n");
        printf("1. Jogar\n");
        printf("2. Ler as Regras\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");

        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                jogo();
                escolha = 3;
                printf("\nObrigado por jogar 'Rouba Mentes'. Até a próxima!\n");
                break;
            case 2:
                lerRegras();
                break;
            case 3:
                printf("Obrigado por jogar 'Rouba Mentes'. Até a próxima!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 3);

	return 0;
}