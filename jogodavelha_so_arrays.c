#include <stdio.h>

#define tam 3

int main(void){

    int i, j, num = 1, op, matriz[tam][tam], vitoria = 0, jogada = 1;
    char jogodavelha[tam][tam] = {' '};

// O algoritmo usa uma matriz de referência para guiar as jogadas. Essa matriz é criada abaixo e desenhada em cada rodada.

    for (i = 0; i < tam; i++){
        for (j = 0; j < tam; j++){
            matriz[i][j] = num;
            num++;
        }
    }

// A partir daqui o jogo começa. Em cada jogada é verificada a variável de vitória e a quantidade de jogadas realizadas.

    do {
        // Pede a jogada.
        if (vitoria != 1 && jogada <= 9){
            printf("Jogada %d\n", jogada);
            printf("Jogador X\n");
            printf("Com base nesta matriz escolha um local para jogar. Se 0 a posição está ocupada.\n");
            for (i = 0; i < tam; i++){
                for (j = 0; j < tam; j++){
                    printf("%d ", matriz[i][j]);
                }
                printf("\n");
            }
            scanf("%d", &op); // Escolhe a posição.

// A partir da matriz que representa as coordenadas, é feita a opção de jogada. Esta opção indica ao programa que deve seguir para um dos casos abaixo. Em cada caso é testada a vitória na jogada. Se ocorrer, a variável de vitória recebe 1 e quebra a repetição das jogadas.

        switch (op){
            case 1:
                jogodavelha[0][0] = 'X';
                matriz[0][0] = 0;
                if (jogodavelha[1][1] == 'X' && jogodavelha[2][2] == 'X'){
                    vitoria = 1;
                    printf("Vitoria do X na diagonal principal.\n");
                } else if (jogodavelha[0][1] == 'X' && jogodavelha[0][2] == 'X'){
                    vitoria = 1;
                    printf("Vitoria do X na linha 1.\n");
                } else if (jogodavelha[1][0] == 'X' && jogodavelha[2][0] == 'X'){
                    vitoria = 1;
                    printf("Vitoria do X na coluna 1.\n");
                }
                break;
            case 2:
                jogodavelha[0][1] = 'X';
                matriz[0][1] = 0;
                if (jogodavelha[0][0] == 'X' && jogodavelha[0][2] == 'X'){
                    vitoria = 1;
                    printf("Vitoria do X na linha 1.\n");
                } else if (jogodavelha[1][1] == 'X' && jogodavelha[2][1] == 'X'){
                    vitoria = 1;
                    printf("Vitoria do X na coluna 2.\n");
                }
                break;
            case 3:
                jogodavelha[0][2] = 'X';
                matriz[0][2] = 0;
                if (jogodavelha[0][0] == 'X' && jogodavelha[0][1] == 'X'){
                    vitoria = 1;
                    printf("Vitoria do X na linha 1.\n");
                } else if (jogodavelha[1][2] == 'X' && jogodavelha[2][2] == 'X'){
                    vitoria = 1;
                    printf("Vitoria do X na coluna 3.\n");
                }
                break;
            case 4:
                jogodavelha[1][0] = 'X';
                matriz[1][0] = 0;
                if (jogodavelha[1][1] == 'X' && jogodavelha[1][2] == 'X'){
                    vitoria = 1;
                    printf("Vitoria do X na linha 2.\n");
                } else if (jogodavelha[0][0] == 'X' && jogodavelha[2][0] == 'X'){
                    vitoria = 1;
                    printf("Vitoria do X na coluna 1.\n");
                }
                break;
            case 5:
                jogodavelha[1][1] = 'X';
                matriz[1][1] = 0;
                if (jogodavelha[1][1] == 'X' && jogodavelha[2][2] == 'X'){
                    vitoria = 1;
                    printf("Vitoria do X na diagonal principal.\n");
                } else if (jogodavelha[0][2] == 'X' && jogodavelha[2][0] == 'X'){
                    vitoria = 1;
                    printf("Vitoria do X na diagonal secundaria.\n");
                } else if (jogodavelha[1][0] == 'X' && jogodavelha[1][2] == 'X'){
                    vitoria = 1;
                    printf("Vitoria do X na linha 2.\n");
                } else if (jogodavelha[0][1] == 'X' && jogodavelha[2][1] == 'X'){
                    vitoria = 1;
                    printf("Vitoria do X na coluna 2.\n");
                }
                break;
            case 6:
                jogodavelha[1][2] = 'X';
                matriz[1][2] = 0;
                if (jogodavelha[1][0] == 'X' && jogodavelha[1][1] == 'X'){
                    vitoria = 1;
                    printf("Vitoria do X na linha 2.\n");
                } else if (jogodavelha[0][2] == 'X' && jogodavelha[2][2] == 'X'){
                    vitoria = 1;
                    printf("Vitoria do X na coluna 3.\n");
                }
                break;
            case 7:
                jogodavelha[2][0] = 'X';
                matriz[2][0] = 0;
                if (jogodavelha[1][1] == 'X' && jogodavelha[0][2] == 'X'){
                    vitoria = 1;
                    printf("Vitoria do X na diagonal secundaria.\n");
                } else if (jogodavelha[2][1] == 'X' && jogodavelha[2][2] == 'X'){
                    printf("Vitoria do X na linha 2.\n");
                    vitoria = 1;
                } else if (jogodavelha[0][0] == 'X' && jogodavelha[1][0] == 'X'){
                    vitoria = 1;
                    printf("Vitoria do X na coluna 1.\n");
                }
                break;
            case 8:
                jogodavelha[2][1] = 'X';
                matriz[2][1] = 0;
                if (jogodavelha[2][0] == 'X' && jogodavelha[2][2] == 'X'){
                    vitoria = 1;
                    printf("Vitoria do X na linha 2.\n");
                } else if (jogodavelha[0][1] == 'X' && jogodavelha[1][1] == 'X'){
                    vitoria = 1;
                    printf("Vitoria do X na coluna 2.\n");
                }
                break;
            case 9:
                jogodavelha[2][2] = 'X';
                matriz[2][2] = 0;
                if (jogodavelha[0][0] == 'X' && jogodavelha[1][1] == 'X'){
                    vitoria = 1;
                    printf("Vitoria do X na diagonal principal.\n");
                } else if (jogodavelha[2][0] == 'X' && jogodavelha[2][1] == 'X'){
                    vitoria = 1;
                    printf("Vitoria do X na linha 3.\n");
                } else if (jogodavelha[0][2] == 'X' && jogodavelha[1][2] == 'X'){
                    vitoria = 1;
                    printf("Vitoria do X na coluna 3.\n");
                }
                break;
            default:
                printf("Jogada invalida.\n");
                break;
        }

// O jogo atualizado é impresso aqui, bem como a atualização da jogada.

        printf("Jogo atual\n");
            for (i = 0; i < tam; i++){
                for (j = 0; j < tam; j++){
                    printf("| %c ", jogodavelha[i][j]);
                }
                printf("|");
                printf("\n");
            }
            jogada++;
        }

// Caso não haja vitorioso, o próximo jogador escolhe a opção e o processo acima é realizado novamente, porém para o jogador O.

        if (vitoria != 1 && jogada <= 9){
            printf("Jogada %d\n", jogada);
            printf("Jogador O\n");
            printf("Com base nesta matriz escolha um local para jogar. Se 0 a posição está ocupada.\n");
            for (i = 0; i < tam; i++){
                for (j = 0; j < tam; j++){
                    printf("%d ", matriz[i][j]);
                }
                printf("\n");
            }
            scanf("%d", &op); // Escolhe a posição.

        switch (op){
            case 1:
                jogodavelha[0][0] = 'O';
                matriz[0][0] = 0;
                if (jogodavelha[1][1] == 'O' && jogodavelha[2][2] == 'O'){
                    vitoria = 1;
                    printf("Vitoria do O na diagonal principal.\n");
                } else if (jogodavelha[0][1] == 'O' && jogodavelha[0][2] == 'O'){
                    vitoria = 1;
                    printf("Vitoria do O na linha 1.\n");
                } else if (jogodavelha[1][0] == 'O' && jogodavelha[2][0] == 'O'){
                    vitoria = 1;
                    printf("Vitoria do O na coluna 1.\n");
                }
                break;
            case 2:
                jogodavelha[0][1] = 'O';
                matriz[0][1] = 0;
                if (jogodavelha[0][0] == 'O' && jogodavelha[0][2] == 'O'){
                    vitoria = 1;
                    printf("Vitoria do O na linha 1.\n");
                } else if (jogodavelha[1][1] == 'O' && jogodavelha[2][1] == 'O'){
                    vitoria = 1;
                    printf("Vitoria do O na coluna 2.\n");
                }
                break;
            case 3:
                jogodavelha[0][2] = 'O';
                matriz[0][2] = 0;
                if (jogodavelha[0][0] == 'O' && jogodavelha[0][1] == 'O'){
                    vitoria = 1;
                    printf("Vitoria do O na linha 1.\n");
                } else if (jogodavelha[1][2] == 'O' && jogodavelha[2][2] == 'O'){
                    vitoria = 1;
                    printf("Vitoria do O na coluna 3.\n");
                }
                break;
            case 4:
                jogodavelha[1][0] = 'O';
                matriz[1][0] = 0;
                if (jogodavelha[1][1] == 'O' && jogodavelha[1][2] == 'O'){
                    vitoria = 1;
                    printf("Vitoria do O na linha 2.\n");
                } else if (jogodavelha[0][0] == 'O' && jogodavelha[2][0] == 'O'){
                    vitoria = 1;
                    printf("Vitoria do O na coluna 1.\n");
                }
                break;
            case 5:
                jogodavelha[1][1] = 'O';
                matriz[1][2] = 0;
                if (jogodavelha[1][1] == 'O' && jogodavelha[2][2] == 'O'){
                    vitoria = 1;
                    printf("Vitoria do O na diagonal principal.\n");
                } else if (jogodavelha[0][2] == 'O' && jogodavelha[2][0] == 'O'){
                    vitoria = 1;
                    printf("Vitoria do O na diagonal secundaria.\n");
                } else if (jogodavelha[1][0] == 'O' && jogodavelha[1][2] == 'O'){
                    vitoria = 1;
                    printf("Vitoria do O na linha 2.\n");
                } else if (jogodavelha[0][1] == 'O' && jogodavelha[2][1] == 'O'){
                    vitoria = 1;
                    printf("Vitoria do O na coluna 2.\n");
                }
                break;
            case 6:
                jogodavelha[1][2] = 'O';
                matriz[1][2] = 0;
                if (jogodavelha[1][0] == 'O' && jogodavelha[1][1] == 'O'){
                    vitoria = 1;
                    printf("Vitoria do O na linha 2.\n");
                } else if (jogodavelha[0][2] == 'O' && jogodavelha[2][2] == 'O'){
                    vitoria = 1;
                    printf("Vitoria do O na coluna 3.\n");
                }
                break;
            case 7:
                jogodavelha[2][0] = 'O';
                matriz[2][0] = 0;
                if (jogodavelha[1][1] == 'O' && jogodavelha[0][2] == 'O'){
                    vitoria = 1;
                    printf("Vitoria do O na diagonal secundaria.\n");
                } else if (jogodavelha[2][1] == 'O' && jogodavelha[2][2] == 'O'){
                    vitoria = 1;
                    printf("Vitoria do O na linha 2.\n");
                } else if (jogodavelha[0][0] == 'O' && jogodavelha[1][0] == 'O'){
                    vitoria = 1;
                    printf("Vitoria do O na coluna 1.\n");
                }
                break;
            case 8:
                jogodavelha[2][1] = 'O';
                matriz[2][1] = 0;
                if (jogodavelha[2][0] == 'O' && jogodavelha[2][2] == 'O'){
                    vitoria = 1;
                    printf("Vitoria do O na linha 2.\n");
                } else if (jogodavelha[0][1] == 'O' && jogodavelha[1][1] == 'O'){
                    vitoria = 1;
                    printf("Vitoria do O na coluna 2.\n");
                }
                break;
            case 9:
                jogodavelha[2][2] = 'O';
                matriz[2][2] = 0;
                if (jogodavelha[0][0] == 'O' && jogodavelha[1][1] == 'O'){
                    vitoria = 1;
                    printf("Vitoria do O na diagonal principal.\n");
                } else if (jogodavelha[2][0] == 'O' && jogodavelha[2][1] == 'O'){
                    vitoria = 1;
                    printf("Vitoria do O na linha 3.\n");
                } else if (jogodavelha[0][2] == 'O' && jogodavelha[1][2] == 'O'){
                    vitoria = 1;
                    printf("Vitoria do O na coluna 3.\n");
                }
                break;
            default:
                printf("Jogada invalida.\n");
                break;
        }
    
        printf("Jogo atual\n");
                    for (i = 0; i < tam; i++){
                        for (j = 0; j < tam; j++){
                            printf("| %c ", jogodavelha[i][j]);
                        }
                        printf("|");
                        printf("\n");
                    }
                    jogada++;
                }
// O loop do jogo é interronpido com a vitória, ou quando o jogo chega a nona rodada. Com isso é impresso o jogo finalizado.

    } while (vitoria != 1 && jogada <= 9);
    printf("Jogo Finalizado\n");
        for (i = 0; i < tam; i++){
            for (j = 0; j < tam; j++){
                printf("| %c ", jogodavelha[i][j]);
            }
            printf("|");
            printf("\n");
        }
}
