#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10
#define INDICE 10
#define TAMANHO_NAVIO 3

void game()
{
    int tabuleiro[LINHAS][COLUNAS];
    char indiceColuna[INDICE] = {'A'};

    // Estrutura limpa/zerada do tabuleiro (somente com 0)
    printf(" <*~ ### TABULEIRO DE BATALHA NAVAL ### ~*>\n");
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    // Trecho do índice
    printf("  "); // Espaço para alinhar índice
    for (int j = 0; j < INDICE; j++)
    {
        printf("   %c", 'A' + j);
    }
    printf("\n");

    // Posicionamento do navioHorizontal
    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int linha = 2, coluna = 1;

    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        if (coluna + i < 10) // Validação para confirmar posicionamento dentro do tabuleiro
            tabuleiro[linha][coluna + i] = navioHorizontal[i];
    }

    // Posicionamento do navioVertical
    int navioVertical[TAMANHO_NAVIO] = {3, 3, 3};
    linha = 5;
    coluna = 7;

    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        if (linha + i < 10) // Validação para confirmar posicionamento dentro do tabuleiro
            tabuleiro[linha + i][coluna] = navioVertical[i];
    }

    // Posicionamento do navioDiagonalEsquerdaSul
    int navioDiagonalEsquerdaSul[TAMANHO_NAVIO] = {3, 3, 3};
    linha = 5;
    coluna = 2;

    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        if (linha + i < 10 && coluna - i >= 0) // Validação para confirmar posicionamento dentro do tabuleiro
            tabuleiro[linha + i][coluna - i] = navioDiagonalEsquerdaSul[i];
    }

    // Posicionamento do navioDiagonalDireitaNorte
    int navioDiagonalDireitaNorte[TAMANHO_NAVIO] = {3, 3, 3};
    linha = 2;
    coluna = 7;

    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        if (linha - i >= 0 && coluna + i < 10) // Validação para confirmar posicionamento dentro do tabuleiro
            tabuleiro[linha - i][coluna + i] = navioDiagonalDireitaNorte[i];
    }

    // Tabuleiro montado e atualizado com os navios H e V
    for (int i = 0; i < LINHAS; i++)
    {
        printf("%2d ", 1 + i); // Cria as linhas numeradas de 1 a i (no caso é 10) - 2d alinha à direita
        for (int j = 0; j < COLUNAS; j++)
        {
            printf(" %2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    game();

    return 0;
}
