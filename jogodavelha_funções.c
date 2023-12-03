#include <stdio.h>

// Variáveis globais: matriz de referência e tabuleiro vazio;
int matriz[3][3];
char jogodavelha[3][3];

// Função que imprime o estágio atual do jogo.
void atualizando(){

    int l, c;

    printf("Jogo atual\n");
    for (l = 0; l < 3; l++){
        for (c = 0; c < 3; c++){
            printf("| %c ", jogodavelha[l][c]);
        }
        printf("|");
        printf("\n");
    }

    printf("Com base na matriz abaixo escolha um local para jogar.\n"); // imprime a matriz de referência.
    printf("Se 0 a posicao esta ocupada.\n");
    for (l = 0; l < 3; l++){
        for (c = 0; c < 3; c++){
            printf("%d ", matriz[l][c]);
        }
    printf("\n");
    }
}

// A partir das coordenadas apresentadas, atualiza a matriz e o tabuleiro com as jogadas.
int jogada(char j1, char j2, int c, int jogando){ // Recebe como variáveis, os dois jogadores, a posição, e a jogada.

    switch (c){
        case 1:
            if (jogodavelha[0][0] == ' '){ // testa a posição livre.
                if (jogando % 2 != 0){ // O jogador 1 estará sempre na jogada impar
                    jogodavelha[0][0] = j1;
                    matriz[0][0] = 0;
                } else {
                    jogodavelha[0][0] = j2; // O jogador 2 na jogada par.
                    matriz[0][0] = 0;
                }
                jogando++; // Se a jogada foi realizada, atualiza e retorna a rodada.
                return jogando;
            } else {
                printf("Posicao ocupada."); // Se a posição está ocupada, retorna 0 indicando invalidade.
                return 0;
            }
            break;
        case 2:
            if (jogodavelha[0][1] == ' '){
                if (jogando % 2 != 0){
                    jogodavelha[0][1] = j1;
                    matriz[0][1] = 0;
                } else {
                    jogodavelha[0][1] = j2;
                    matriz[0][1] = 0;
                }
                jogando++;
                return jogando;
            } else{
                printf("Posicao ocupada.");
                return 0;
            }
            break;
        case 3:
            if (jogodavelha[0][2] == ' '){
                if (jogando % 2 != 0){
                    jogodavelha[0][2] = j1;
                    matriz[0][2] = 0;
                } else {
                    jogodavelha[0][2] = j2;
                    matriz[0][2] = 0;
                }
                jogando++;
                return jogando;
            } else{
                printf("Posicao ocupada.");
                return 0;
            }
            break;
        case 4:
            if (jogodavelha[1][0] == ' '){
                if (jogando % 2 != 0){
                    jogodavelha[1][0] = j1;
                    matriz[1][0] = 0;
                } else {
                    jogodavelha[1][0] = j2;
                    matriz[1][0] = 0;
                }
                jogando++;
                return jogando;
            } else{
                printf("Posicao ocupada.");
                return 0;
            }
            break;
        case 5:
            if (jogodavelha[1][1] == ' '){
                if (jogando % 2 != 0){
                    jogodavelha[1][1] = j1;
                    matriz[1][1] = 0;
                } else{
                    jogodavelha[1][1] = j2;
                    matriz[1][1] = 0;
                }
                jogando++;
                return jogando;
            } else{
                printf("Posicao ocupada.");
                return 0;
            }
            break;
        case 6:
            if (jogodavelha[1][2] == ' '){
                if (jogando % 2 != 0){
                    jogodavelha[1][2] = j1;
                    matriz[1][2] = 0;
                } else {
                    jogodavelha[1][2] = j2;
                    matriz[1][2] = 0;
                }
                jogando++;
                return jogando;
            } else{
                printf("Posicao ocupada.");
                return 0;
            }
            break;
        case 7:
            if (jogodavelha[2][0] == ' '){
                if (jogando % 2 != 0){
                    jogodavelha[2][0] = j1;
                    matriz[2][0] = 0;
                } else{
                    jogodavelha[2][0] = j2;
                    matriz[2][0] = 0;
                }
                jogando++;
                return jogando;
            } else{
                printf("Posicao ocupada.");
                return 0;
            }
            break;
        case 8:
            if (jogodavelha[2][1] == ' '){
                if (jogando % 2 != 0){
                    jogodavelha[2][1] = j1;
                    matriz[2][1] = 0;
                } else {
                    jogodavelha[2][1] = j2;
                    matriz[2][1] = 0;
                }
                jogando++;
                return jogando;
            } else{
                printf("Posicao ocupada.");
                return 0;
            }
            break;
        case 9:
            if (jogodavelha[2][2] == ' '){
                if (jogando % 2 != 0){
                    jogodavelha[2][2] = j1;
                    matriz[2][2] = 0;
                } else{
                    jogodavelha[2][2] = j2;
                    matriz[2][2] = 0;
                }
                jogando++;
                return jogando;
            } else{
                printf("Posicao ocupada.");
                return 0;
            }
            break;
        default:
            printf("Jogada invalida.\n"); // se for usada coordenada invalida, também retorna o erro.
            return 0;
            break;
    }
}

// Define as condições de vitória e retorna parâmetro de fim de jogo.
int vitoria(int matriz[3][3], char jogodavelha[3][3], char j1, char j2, int joguei){

    char vitorioso;

    if(joguei % 2 != 0)
        vitorioso = j1;
    else
        vitorioso = j2;

    if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]){
        if (jogodavelha[0][0] == jogodavelha[1][1] && jogodavelha[1][1] == jogodavelha[2][2]){
            printf("Vitoria do %c na diagonal principal.\n\n", vitorioso);
            return 1; //Vitoria na diagonal principal
        }
    } else if (matriz[0][0] == matriz[0][1] && matriz[0][1] == matriz[0][2]){
        if (jogodavelha[0][0] == jogodavelha[0][1] && jogodavelha[0][1] == jogodavelha[0][2]){
            printf("Vitoria do %c na linha superior.\n\n", vitorioso);
            return 2; //Vitoria na linha superior
        }
    } else if (matriz[0][0] == matriz[1][0] && matriz[1][0] == matriz[2][0]){
        if (jogodavelha[0][0] == jogodavelha[1][0] && jogodavelha[1][0] == jogodavelha[2][0]){
            printf("Vitoria do %c na coluna esquerda.\n\n", vitorioso);
            return 3; //Vitoria na coluna esquerda
        }
    } else if (matriz[0][1] == matriz[1][1] && matriz[1][1] == matriz[2][1]){
        if (jogodavelha[0][1] == jogodavelha[1][1] && jogodavelha[1][1] == jogodavelha[2][1]){
            printf("Vitoria do %c na coluna central.\n\n", vitorioso);
            return 4; //Vitoria na coluna central
        }
    } else if (matriz[0][2] == matriz[1][2] && matriz[1][2] == matriz[2][2]){
        if (jogodavelha[0][2] == jogodavelha[1][2] && jogodavelha[1][2] == jogodavelha[2][2]){
            printf("Vitoria do %c na coluna direita.\n\n", vitorioso);
            return 5; //Vitoria na coluna direinta
        }
    } else if (matriz[1][0] == matriz[1][1] && matriz[1][1] == matriz[1][2]){
        if (jogodavelha[1][0] == jogodavelha[1][1] && jogodavelha[1][1] == jogodavelha[1][2]){
            printf("Vitoria do %c na linha central.\n\n", vitorioso);
            return 6; //Vitoria na linha central
        }
    } else if (matriz[2][0] == matriz[2][1] && matriz[2][1] == matriz[2][2]){
        if (jogodavelha[2][0] == jogodavelha[2][1] && jogodavelha[2][1] == jogodavelha[2][2]){
            printf("Vitoria do %c na linha inferior.\n\n", vitorioso);
            return 7; //Vitoria na linha inferior
        }
    } else if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0]){
        if (jogodavelha[0][2] == jogodavelha[1][1] && jogodavelha[1][1] == jogodavelha[2][0]){
            printf("Vitoria do %c na diagonal oposta.\n\n", vitorioso);
            return 8; //Vitoria na diagonal oposta
        }
    }
    return 9;
}

int main(void){

    char jogador1, jogador2;
    int posicao, rodada = 1, valido, num = 1, l, c, escolheJogador, fim;

    for (l = 0; l < 3; l++){ // cria a matriz de referência e o tabuleiro.
        for (c = 0; c < 3; c++){
            matriz[l][c] = num;
            jogodavelha[l][c] = ' ';
            num++;
        }
    }

    do {
        printf("Escolha o jogador (1 = X ou 2 = O)\n");
        scanf("%d", &escolheJogador);
        printf("\n");
        if (escolheJogador == 1){
            jogador1 = 'X';
            jogador2 = 'O';
        } else if (escolheJogador == 2){
            jogador2 = 'X';
            jogador1 = 'O';
        } else
            printf("Escolha invalida.\n\n");
    } while (escolheJogador != 1 && escolheJogador != 2);

    // Este loop controla o fim do jogo.
    do{
        atualizando();
        // Este loop controla a validade da jogada.
        do{
            printf("------------------\n");
            printf("Rodada: %d !!!\n", rodada);
            printf("------------------\n");
            if (rodada % 2 != 0)
                printf("Jogador: %c !!!\n", jogador1);
            else
                printf("Jogador: %c !!!\n", jogador2);
            printf("------------------\n");
            printf("Digite a posicao desejada.\n");
            scanf("%d", &posicao);
            printf("\n");
            valido = jogada(jogador1, jogador2, posicao, rodada); // a variavel recebe o retorno da função, de maneira que contrla o loop e a rodada.
        } while (valido == 0);
        fim = vitoria(matriz, jogodavelha, jogador1, jogador2, rodada);
        if (valido != 0)
            rodada = valido;
    } while (fim == 9 && rodada <= 9);

    for (l = 0; l < 3; l++){
        for (c = 0; c < 3; c++){
            printf("| %c ", jogodavelha[l][c]);
        }
        printf("|");
        printf("\n");
    }
    printf("\n");

    if (rodada >= 9)
        printf("Empate.\n\n");
    printf("Jogo encerrado.");
}
