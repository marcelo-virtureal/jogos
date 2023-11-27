#include <stdio.h>

#define TAM 3

typedef struct{
    char mapa[TAM][TAM];
    int qtdMinas[TAM][TAM];
} Tabuleiro;


Tabuleiro criaJogo(){

    Tabuleiro t;

    int l, c;
    for (l = 0; l < TAM; l++){
        for (c = 0; c < TAM ; c++){
            if (l == c)
                t.mapa[1][1] = 'm';
            else
                t.mapa[l][c] = ' ';

            t.qtdMinas[l][c] = calcQtdMinas(t);
        }
    }
    return t;
}

void desenhaTabuleiro(Tabuleiro t){

    int l, c;

    for (l = 0; l <= TAM * 2 + 1; l++){
        for (c = 0; c <= TAM * 2 + 1; c++){
            if (l == 0 && c == 0)
                printf("0");
            if (l == 0 && c > 0){
                if (c % 2 == 0)
                    printf("%d ", c / 2);
                else
                    printf("   ");
            }
            if (c == 0 && l > 0){
                if (l % 2 == 0)
                    printf("%d ", l / 2);
                else
                    printf("  ");
            }
            if (l > 0 && c > 0){
                if (l % 2 != 0)
                    printf("--");
                else{
                    if (c % 2 != 0)
                        printf("| ");
                    else
                        printf(" %d ", t.qtdMinas[l / 2 - 1][c / 2 - 1]);
                }
            }
        }
        printf("\n");
    }
}

int calcQtdMinas(Tabuleiro t){

    int l, c, minas = 0;

    for (l = 0; l < TAM; l++){
        for (c = 0; c < TAM; c++){
            if (l == 0 && c == 0){ // canto superior esquerdo
                if (t.mapa[l+1][c] == 'm')
                    minas++;
                else if (t.mapa[l][c+1] == 'm')
                    minas++;
                else if (t.mapa[l+1][c+1] == 'm')
                    minas++;
            } else if (l == 0 && c == TAM - 1){ // canto superior direito
                if (t.mapa[l][c-1] == 'm')
                else if (t.mapa[l+1][c-1] == 'm')
                    minas++;
                    minas++;
                else if (t.mapa[l+1][c] == 'm')
                    minas++;
            } else if (l == 0 && c > 0 && c < TAM -1){ //linha superior
                if (t.mapa[l][c-1] == 'm')
                    minas++;
                else if (t.mapa[l+1][c-1] == 'm')
                    minas++;
                else if (t.mapa[l+1][c] == 'm')
                    minas++;
                else if (t.mapa[l+1][c+1] == 'm')
                    minas++;
                else if (t.mapa[l][c+1])
                    minas++;
            } else if (l == TAM - 1 && c == 0){ // canto inferior esquerdo
                if (t.mapa[l-1][c] == 'm')
                    minas++;
                else if (t.mapa[l-1][c+1] == 'm')
                    minas++;
                else if (t.mapa[l][c+1] == 'm')
                    minas++;
            } else if (l == TAM - 1 && c == TAM - 1){ // canto inferior direito
                if (t.mapa[l-1][c-1] == 'm')
                    minas++;
                else if (t.mapa[l][c-1] == 'm')
                    minas++;
                else if (t.mapa[l-1][c] == 'm')
                    minas++;
            } else if (l = TAM - 1 && c > 0 && c < TAM -1){ // linha inferior
                if (t.mapa[l][c-1] == 'm')
                    minas++;
                else if (t.mapa[l-1][c-1] == 'm')
                    minas++;
                else if (t.mapa[l-1][c] == 'm')
                    minas++;
                else if (t.mapa[l-1][c+1] == 'm')
                    minas++;
                else if (t.mapa[l][c+1])
                    minas++;
            }else if (c == 0 && l > 0 && l < TAM - 1){ // coluna esquerda
                if (t.mapa[l-1][c] == 'm')
                    minas++;
                else if (t.mapa[l-1][c+1] == 'm')
                    minas++;
                else if (t.mapa[l][c+1] == 'm')
                    minas++;
                else if (t.mapa[l+1][c+1] == 'm')
                    minas++;
                else if (t.mapa[l+1][c])
                    minas++;
            } else if (c == TAM - 1 && l > 0 && l < TAM - 1){ // coluna direita
                if (t.mapa[l-1][c] == 'm')
                    minas++;
                else if (t.mapa[l-1][c-1] == 'm')
                    minas++;
                else if (t.mapa[l][c-1] == 'm')
                    minas++;
                else if (t.mapa[l+1][c-1] == 'm')
                    minas++;
                else if (t.mapa[l+1][c])
                    minas++;
            } else if (l > 0 && l < TAM - 1 && c > 0 && l < TAM - 1){ // celulas internas
                if (t.mapa[l-1][c-1] == 'm')
                    minas++;
                else if (t.mapa[l-1][c] == 'm')
                    minas++;
                else if (t.mapa[l-1][c+1] == 'm')
                    minas++;
                else if (t.mapa[l][c+1] == 'm')
                    minas++;
                else if (t.mapa[l][c-1] == 'm')
                    minas++;
                else if (t.mapa[l+1][c-1] == 'm')
                    minas++;
                else if (t.mapa[l+1][c] == 'm')
                    minas++;
                else if (t.mapa[l+1][c+1] == 'm')
                    minas++;
            }
        }
    }
    return minas;
}



int main(void){

    Tabuleiro tabuleiro;

    tabuleiro = criaJogo();
    desenhaTabuleiro(tabuleiro);

}
