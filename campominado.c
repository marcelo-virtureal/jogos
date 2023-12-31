#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

typedef struct{
    char mapa[TAM][TAM]; // Estrutura com um mapa para localização das minas;
    int qtdMinas[TAM][TAM]; // Uma matriz que aponta quantas minas estão ao redor de um local sem minas;
    int atualTab[TAM][TAM]; // Uma matriz auxiliar para atualizar o tabuleiro impresso;
    int qtMinas; // Um inteiro que guarda a quantidade de minas calculada de acordo com o tamanho do tabuleiro.
} Tabuleiro;

int posicMinasL(){ // Função responsável pela posição da mina na linha.

    srand(time(NULL)); // usa funções randomicas para o posicionamento.

    return rand() % TAM;
}

int posicMinasC(){ // Função responsável pela posição da mina na coluna.

    srand(time(NULL)); // usa funções randomicas para o posicionamento.

    return rand() % TAM;
}

Tabuleiro criaJogo(Tabuleiro t){ // Preenche a estrutura Tabuleiro.

    int l, c, c1, c2, minas = 1;

    t.qtMinas = TAM * TAM * 0.1; // a quantidade de minas é +- 10% do número de células da tabela.

    for (l = 0; l < TAM; l++){
        for (c = 0; c < TAM; c++){
            t.mapa[l][c] = ' '; // preenche com espaço vazio.
        }
    }

    while (minas <= t.qtMinas){
        c1 = posicMinasL();
        c2 = posicMinasC();
        if (t.mapa[c1][c2] == 'm'){
            while (t.mapa[c1][c2] == 'm'){
                c1 = posicMinasL();
                c2 = posicMinasC();
            }
        }
        t.mapa[c1][c2] = 'm';
        minas++;
    }

    for (l = 0; l < TAM; l++){
        for (c = 0; c < TAM; c++){
            t.qtdMinas[l][c] = calcQtdMinas(t, l, c); // usa a função de cálculo de qtd de minas próximas para preencher a quantidade.
        }
    }

    for (l = 0; l < TAM; l++){
        for (c = 0; c < TAM; c++){
            t.atualTab[l][c] = -1; // a matriz auxiliar recebe -1 que será condição na impressão do tabuleiro.
        }
    }
    return t;
}

void desenhaTabuleiro(Tabuleiro t){ // imprime na tela o tabuleiro de jogo.

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
                    else{
                        if (t.atualTab[l / 2 - 1][c / 2 - 1] > -1) // busca posições preenchidas com qtd de minas para imprimir.
                            printf(" %d ", t.atualTab[l / 2 - 1][c / 2 - 1]);
                        else
                            printf("   ");
                        }
                    }
                }
        }
        printf("\n"); // quebra a linha.
    }
}

Tabuleiro atualizaTab(Tabuleiro t, int c1, int c2){ // função que atualiza a cada jogada o valor na matriz auxiliar.

    t.atualTab[c1-1][c2-1] = t.qtdMinas[c1-1][c2-1];

    return t;
}

void imprimeFimJogo(Tabuleiro t){ // quando o jogo termina, o tabuleiro é aberto.


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
                    else{
                        if (t.mapa[l / 2 - 1][c / 2 - 1] == 'm') // a posição da mina é revelada.
                            printf(" m ");
                        else
                            printf(" %d ", t.qtdMinas[l / 2 - 1][c / 2 - 1]); // as posições sem minas contem o número de minas ao redor.
                    }
                }
            }
        }
        printf("\n"); // quebra a linha.
    }
}

int calcQtdMinas(Tabuleiro t, int c1, int c2){ // função para retornar a quantidade de minas ao redor de uma posição.

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
        } else if (c1 == 0 && c2 > 0 && c2 < (TAM - 1)){ //linha superior
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

int confereMina(Tabuleiro t, int cd1, int cd2){ // condição de derrota.

    if (t.mapa[cd1-1][cd2-1] == 'm'){
        printf("\n");
        printf("KABUUUMMMM\n");
        printf("Havia uma mina na posicao %d , %d. Voce explodiu.\n\n", cd1, cd2);
        return 1;
    }
    return 0;
}

int vitoria(Tabuleiro t, int qtJ){ // condição de vitória.

    if (qtJ >= TAM*TAM - t.qtMinas){
        printf("\n");
        printf("Ufa!!\n");
        printf("Parabens, voce encontrou todas as minas.\n");
        return 1;
    }
    return 0;
}

int main(void){

    Tabuleiro tabuleiro, preJogo;
    int coord1 = 0, coord2 = 0, qtdJ = 0;

    tabuleiro = criaJogo(preJogo); // preenche as matrizes da estrutura.

    do{ // começa jogo.
        desenhaTabuleiro(tabuleiro); // em cada rodada o tabuleiro atualizado é impresso.
        printf("Este tabuleiro contem %d minas.\n\n", tabuleiro.qtMinas);
        printf("Esta e a jogada %d.\n\n", qtdJ + 1);
        printf("Faltam %d jogadas para vitoria.\n\n", TAM*TAM - tabuleiro.qtMinas - (qtdJ + 1));
        do {
            printf("Digite os dois numeros (linha e coluna) de coordenada separados por espaço onde deseja jogar.\n\n");
            scanf("%d %d", &coord1, &coord2);
            if ((coord1 > TAM || coord1 < 1) && (coord2 > TAM || coord2 < 1))
                printf("Coordenadas invalidas.\n");
        } while ((coord1 > TAM || coord1 < 1) && (coord2 > TAM || coord2 < 1) );
        qtdJ++;
        tabuleiro = atualizaTab(tabuleiro, coord1, coord2);
    } while (confereMina(tabuleiro, coord1, coord2) == 0 && vitoria(tabuleiro, qtdJ) == 0);
    imprimeFimJogo(tabuleiro);
    printf("Fim do jogo.");
}
