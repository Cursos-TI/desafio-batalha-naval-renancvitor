#include <stdio.h>

void game()
{
    int tabuleiro[10][10];
    char indiceColuna[10] = {'A'};

    // Estrutura limpa/zerada do tabuleiro (somente com 0)
    printf(" ~*~ ### TABULEIRO DE BATALHA NAVAL ### ~*~\n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    // Trecho do cabeçalho
    printf("  "); // Espaço para alinha cabeçalho
    for (int j = 0; j < 10; j++)
    {
        printf("   %c", 'A' + j);
    }
    printf("\n");

    // Posicionamento do navioH
    int navioH[3] = {3, 3, 3};
    int linha = 2, coluna = 1;

    for (int i = 0; i < 3; i++)
    {
        tabuleiro[linha][coluna + i] = navioH[i];
    }

    // Posicionamento do navioV
    int navioV[3] = {3, 3, 3};
    linha = 5;
    coluna = 7;

    for (int i = 0; i < 3; i++)
    {
        tabuleiro[linha + i][coluna] = navioV[i];
    }

    // Tabuleiro montado e atualizado com os navios H e V
    for (int i = 0; i < 10; i++)
    {
        printf("%2d ", 1 + i); // Cria as linhas numeradas de 1 a i (no caso é 10) - 2d alinha à direita
        for (int j = 0; j < 10; j++)
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
