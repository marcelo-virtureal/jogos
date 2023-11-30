#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 3

typedef struct{
    char mapa[TAM][TAM];
    int qtdMinas[TAM][TAM];
    int qtMinas;
} Tabuleiro;

Tabuleiro posicMinas(Tabuleiro t){

    int cL, cC;
    t.qtMinas = 0;

    while (t.qtMinas <= TAM*TAM*0.1){
        srand(time(NULL));
        cL = rand() % TAM;
        cC = rand() % TAM;
        t.mapa[cL][cC] = 'm';
        t.qtMinas++;
    }
    return t;
}

Tabuleiro criaJogo(Tabuleiro t){ // Preenche a estrutura Tabuleiro.

    int l, c;

    for (l = 0; l < TAM; l++){
        for (c = 0; c < TAM; c++){
            if (t.mapa[l][c] != 'm') // se não houver mina no espaço.
                t.mapa[l][c] = ' '; // preenche com espaço vazio.
        }
    }

    for (l = 0; l < TAM; l++){
        for (c = 0; c < TAM; c++){
            t.qtdMinas[l][c] = calcQtdMinas(t, l, c); // usa a função de cálculo de qrd de minas próximas para preencher a quantidade.
        }
    }
    return t;
}

void desenhaTabuleiro(Tabuleiro t, int c1, int c2){ // imprime na tela o tabuleiro de jogo.

    int l, c;

    for (l = 0; l <= TAM * 2 + 1; l++){ // o loop for de impressão usa o tamanho dobrado para divisórias e uma posição mais para as coordenadas.
        for (c = 0; c <= TAM * 2 + 1; c++){
            if (l == 0 && c == 0) // A posição 0,0 é neutra.
                printf("0");
            if (l == 0 && c > 0){ // imprime as coordenadas da linha superior.
                if (c % 2 == 0) // somente nas posições pares.
                    printf("%d ", c / 2); // a coordenada obedece ao tamanho do tabuleiro sem divisórias.
                else
                    printf("   "); // nas posições impares imprime espaço em branco.
            }
            if (c == 0 && l > 0){ // realiza o mesmo processo para a coluna da esquerda
                if (l % 2 == 0)
                    printf("%d ", l / 2);
                else
                    printf("  ");
            }
            if (l > 0 && c > 0){ // impressão do tabuleiro propriamente.
                if (l % 2 != 0) // Nas linhas impares, imprime divisória.
                    printf("--");
                else{ // nas linhas pares alterna divisória nas colunas impares e a quantidade de minas na colunas pares.
                    if (c % 2 != 0)
                        printf("| ");
                    else
                        printf("   ");
                }
            }
        }
        printf("\n"); // quebra a linha.
    }
    /*if (jogada(t, l / 2 - 1, c / 2 - 1) == 1)
                            printf(" %c ", t.mapa[l / 2 - 1][c / 2 - 1]);
                        else if (jogada(t, l / 2 - 1, c / 2 - 1) == 2)
                            printf(" %d ", t.qtdMinas[l / 2 - 1][c / 2 - 1]);*/ // a quantidade de minas é buscada na matriz de acordo com o tamanho sem divisórias.
}

int calcQtdMinas(Tabuleiro t, int c1, int c2){

    int minas = 0;

    if (t.mapa[c1][c2] != 'm'){
        if (c1 == 0 && c2 == 0){ // canto superior esquerdo
            if (t.mapa[c1+1][c2] == 'm'){
                minas++;
            } else if (t.mapa[c1][c2+1] == 'm'){
                minas++;
            } else if (t.mapa[c1+1][c2+1] == 'm'){
                minas++;
            }
        return minas;
        } else if (c1 == 0 && c2 == (TAM - 1)){ // canto superior direito
            if (t.mapa[c1][c2-1] == 'm'){
                minas++;
            } else if (t.mapa[c1+1][c2-1] == 'm'){
                minas++;
            } else if (t.mapa[c1+1][c2] == 'm'){
                minas++;
            }
        return minas;
        } else if (c1 == 0 && c2 > 0 && c2 < (TAM -1)){ //linha superior
            if (t.mapa[c1][c2-1] == 'm'){
                minas++;
            } else if (t.mapa[c1+1][c2-1] == 'm'){
                minas++;
            } else if (t.mapa[c1+1][c2] == 'm'){
                minas++;
            } else if (t.mapa[c1+1][c2+1] == 'm'){
                minas++;
            } else if (t.mapa[c1][c2+1] == 'm'){
                minas++;
            }
        return minas;
        } else if (c1 == (TAM - 1) && c2 == 0){ // canto inferior esquerdo
            if (t.mapa[c1-1][c2] == 'm'){
                minas++;
            } else if (t.mapa[c1-1][c2+1] == 'm'){
                minas++;
            } else if (t.mapa[c1][c2+1] == 'm'){
                minas++;
            }
        return minas;
        } else if (c1 == (TAM - 1) && c2 == (TAM - 1)){ // canto inferior direito
            if (t.mapa[c1-1][c2-1] == 'm'){
                minas++;
            } else if (t.mapa[c1][c2-1] == 'm'){
                minas++;
            } else if (t.mapa[c1-1][c2] == 'm'){
                minas++;
            }
        return minas;
        } else if (c1 == (TAM - 1) && c2 > 0 && c2 < (TAM -1)){ // linha inferior
            if (t.mapa[c1][c2-1] == 'm'){
                minas++;
            } else if (t.mapa[c1-1][c2-1] == 'm'){
                minas++;
            } else if (t.mapa[c1-1][c2] == 'm'){
                minas++;
            } else if (t.mapa[c1-1][c2+1] == 'm'){
                minas++;
            } else if (t.mapa[c1][c2+1] == 'm'){
                minas++;
            }
        return minas;
        } else if (c2 == 0 && c1 > 0 && c1 < (TAM - 1)){ // coluna esquerda
            if (t.mapa[c1-1][c2] == 'm'){
                minas++;
            } else if (t.mapa[c1-1][c2+1] == 'm'){
                minas++;
            } else if (t.mapa[c1][c2+1] == 'm'){
                minas++;
            } else if (t.mapa[c1+1][c2+1] == 'm'){
                minas++;
            } else if (t.mapa[c1+1][c2] == 'm'){
                minas++;
            }
        return minas;
        } else if (c2 == (TAM - 1) && c1 > 0 && c1 < (TAM - 1)){ // coluna direita
            if (t.mapa[c1-1][c2] == 'm'){
                minas++;
            } else if (t.mapa[c1-1][c2-1] == 'm'){
                minas++;
            } else if (t.mapa[c1][c2-1] == 'm'){
                minas++;
            } else if (t.mapa[c1+1][c2-1] == 'm'){
                minas++;
            } else if (t.mapa[c1+1][c2] == 'm'){
                minas++;
            }
        return minas;
        } else if (c1 > 0 && c1 < (TAM - 1) && c2 > 0 && c2 < (TAM - 1)){ // celulas internas
            if (t.mapa[c1-1][c2-1] == 'm'){
                minas++;
            } else if (t.mapa[c1-1][c2] == 'm'){
                minas++;
            } else if (t.mapa[c1-1][c2+1] == 'm'){
                minas++;
            } else if (t.mapa[c1][c2+1] == 'm'){
                minas++;
            } else if (t.mapa[c1][c2-1] == 'm'){
                minas++;
            } else if (t.mapa[c1+1][c2-1] == 'm'){
                minas++;
            } else if (t.mapa[c1+1][c2] == 'm'){
                minas++;
            } else if (t.mapa[c1+1][c2+1] == 'm'){
                minas++;
            }
        return minas;
        }
    } else
        return NULL;
}

int jogada(Tabuleiro t, int c1, int c2){

    if (confereMina(t, c1, c2) == 1)
        return 1;
    else
        return 2;
    return 0;

}

int confereMina(Tabuleiro t, int cd1, int cd2){

    if (t.mapa[cd1-1][cd2-1] == 'm'){
        printf("Havia uma mina na posicao %d , %d. Voce explodiu.\n", cd1, cd2);
        return 1;
    }
    return 0;
}

int vitoria(Tabuleiro t, int qtJ){

    if (qtJ >= TAM*TAM - t.qtMinas){
        printf("Parabens, voce encontrou todas as minas.\n");
        return 1;
    }
    return 0;
}

int main(void){

    Tabuleiro tabuleiro, pM;
    int coord1, coord2, qtdJ = 0;

    pM = posicMinas(tabuleiro);

    tabuleiro = criaJogo(pM);

    do{
        desenhaTabuleiro(tabuleiro, coord1, coord2);
        printf("Este tabuleiro contem %d minas.\n", tabuleiro.qtMinas);
        printf("Esta e a jogada %d.\n", qtdJ + 1);
        printf("Faltam %d jogadas para vitoria.\n", TAM*TAM - tabuleiro.qtMinas - qtdJ - 1);
        do {
            printf("Digite os dois numeros (linha e coluna) de coordenada separados por espaço onde deseja jogar.\n");
            scanf("%d %d", &coord1, &coord2);
            if ((coord1 > TAM || coord1 < 1) && (coord2 > TAM || coord2 < 1))
                printf("Coordenadas invalidas.\n");
        } while ((coord1 > TAM || coord1 < 1) && (coord2 > TAM || coord2 < 1) );
        qtdJ++;
    } while (confereMina(tabuleiro, coord1, coord2) == 0 && vitoria(tabuleiro, qtdJ) == 0);
    printf("Fim do jogo.");
}
