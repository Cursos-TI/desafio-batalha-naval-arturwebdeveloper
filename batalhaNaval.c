#include <stdio.h>

#define TAMANHO 10

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void aplicarHabilidadeCruz(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO)
        tabuleiro[linha][coluna] = 5;
    if (linha - 1 >= 0) tabuleiro[linha - 1][coluna] = 5;
    if (linha + 1 < TAMANHO) tabuleiro[linha + 1][coluna] = 5;
    if (coluna - 1 >= 0) tabuleiro[linha][coluna - 1] = 5;
    if (coluna + 1 < TAMANHO) tabuleiro[linha][coluna + 1] = 5;
}

void aplicarHabilidadeCone(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO)
        tabuleiro[linha][coluna] = 5;
    if (linha + 1 < TAMANHO) {
        if (coluna - 1 >= 0) tabuleiro[linha + 1][coluna - 1] = 5;
        tabuleiro[linha + 1][coluna] = 5;
        if (coluna + 1 < TAMANHO) tabuleiro[linha + 1][coluna + 1] = 5;
    }
    if (linha + 2 < TAMANHO) {
        if (coluna - 2 >= 0) tabuleiro[linha + 2][coluna - 2] = 5;
        if (coluna - 1 >= 0) tabuleiro[linha + 2][coluna - 1] = 5;
        tabuleiro[linha + 2][coluna] = 5;
        if (coluna + 1 < TAMANHO) tabuleiro[linha + 2][coluna + 1] = 5;
        if (coluna + 2 < TAMANHO) tabuleiro[linha + 2][coluna + 2] = 5;
    }
}

void aplicarHabilidadeOctaedro(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO)
        tabuleiro[linha][coluna] = 5;
    if (linha - 1 >= 0) tabuleiro[linha - 1][coluna] = 5;
    if (linha + 1 < TAMANHO) tabuleiro[linha + 1][coluna] = 5;
    if (coluna - 1 >= 0) tabuleiro[linha][coluna - 1] = 5;
    if (coluna + 1 < TAMANHO) tabuleiro[linha][coluna + 1] = 5;
    if (linha - 2 >= 0) tabuleiro[linha - 2][coluna] = 5;
    if (linha + 2 < TAMANHO) tabuleiro[linha + 2][coluna] = 5;
    if (coluna - 2 >= 0) tabuleiro[linha][coluna - 2] = 5;
    if (coluna + 2 < TAMANHO) tabuleiro[linha][coluna + 2] = 5;
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);
    aplicarHabilidadeCruz(tabuleiro, 5, 5);
    aplicarHabilidadeCone(tabuleiro, 3, 3);
    aplicarHabilidadeOctaedro(tabuleiro, 4, 4);
    exibirTabuleiro(tabuleiro);
    return 0;
}
