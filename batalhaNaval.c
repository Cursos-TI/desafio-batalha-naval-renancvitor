#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10
#define INDICE 10
#define INDICE_HABILIDADES 5
#define TAMANHO_NAVIO 3
#define LINHA_HABILIDADE 3
#define COLUNA_HABILIDADE 5
#define LINHA_HABILIDADE_OCTAEDRO 5

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
    linha = 4;
    coluna = 2;

    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        if (linha + i < 10 && coluna - i >= 0) // Validação para confirmar posicionamento dentro do tabuleiro
            tabuleiro[linha + i][coluna - i] = navioDiagonalEsquerdaSul[i];
    }

    // Posicionamento do navioDiagonalDireitaNorte
    int navioDiagonalDireitaNorte[TAMANHO_NAVIO] = {3, 3, 3};
    linha = 2;
    coluna = 5;

    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        if (linha - i >= 0 && coluna + i < 10) // Validação para confirmar posicionamento dentro do tabuleiro
            tabuleiro[linha - i][coluna + i] = navioDiagonalDireitaNorte[i];
    }

    // Formando cone
    int linhaCone = 0;
    int colunaCone = 7;
    char posicaoCone[100][3];

    for (int i = 0; i < LINHA_HABILIDADE; i++)
    {
        for (int j = -i; j <= i; j++)
        {
            int L = linhaCone + i;
            int C = colunaCone + j;
            if (L >= 0 && L < LINHAS && C >= 0 && C < COLUNAS)
            {
                tabuleiro[L][C] = 1;
            }
        }
    }

    // Formando cruz
    int linhaCruz = 6;   // centro da cruz horizontal
    int colunaCruz = 7;  // centro da cruz vertical
    int tamanhoCruz = 2; // distância braços ref centro
    char posicaoCruz[100][3];

    // Vertical
    for (int i = -tamanhoCruz; i <= tamanhoCruz; i++)
    {
        tabuleiro[linhaCruz + i][colunaCruz] = 5;
    }

    // Horizontal
    for (int j = -tamanhoCruz; j <= tamanhoCruz; j++)
    {
        tabuleiro[linhaCruz][colunaCruz + j] = 5;
    }

    // Formando octaedro
    int centroL = 6; // linha central do octaedro
    int centroC = 2; // coluna central
    int altura = 3;  // metade superior
    char posicaoOctaedro[100][3];

    // Metade superior
    for (int i = 0; i < altura; i++)
    {
        int linha = centroL - altura + 1 + i;
        for (int j = -i; j <= i; j++)
        {
            tabuleiro[linha][centroC + j] = 8;
        }
    }

    // Metade inferior
    for (int i = altura - 2; i >= 0; i--)
    {
        int linha = centroL + (altura - i - 1);
        for (int j = -i; j <= i; j++)
        {
            tabuleiro[linha][centroC + j] = 8;
        }
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

    int cone = 0;
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            if (tabuleiro[i][j] == 1)
            {
                posicaoCone[cone][0] = 'A' + j;
                posicaoCone[cone][1] = '1' + i;
                posicaoCone[cone][2] = '\0';
                cone++;
            }
        }
    }

    printf("Habilidade cone:\n");
    printf("Onda de impacto em linha reta cobrindo a área ");
    for (int i = 0; i < cone; i++)
    {
        printf("%s", posicaoCone[i]);
        if (i < cone - 1)
        {
            printf(", ");
        }
        else
        {
            printf("!\n");
        }
    }

    int cruz = 0;
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            if (tabuleiro[i][j] == 5)
            {
                posicaoCruz[cruz][0] = 'A' + j;
                posicaoCruz[cruz][1] = '1' + i;
                posicaoCruz[cruz][2] = '\0';
                cruz++;
            }
        }
    }

    printf("Habilidade cruz:\n");
    printf("Explosão em cruz atingindo ");
    for (int i = 0; i < cruz; i++)
    {
        printf("%s", posicaoCruz[i]);
        if (i < cruz - 1)
        {
            printf(", ");
        }
        else
        {
            printf("!\n");
        }
    }

    int octaedro = 0;
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            if (tabuleiro[i][j] == 8)
            {
                posicaoOctaedro[octaedro][0] = 'A' + j;
                posicaoOctaedro[octaedro][1] = '1' + i;
                posicaoOctaedro[octaedro][2] = '\0';
                octaedro++;
            }
        }
    }

    printf("Habilidade octaedro:\n");
    printf("Chama em forma de diamante abrangendo ");
    for (int i = 0; i < octaedro; i++)
    {
        printf("%s", posicaoOctaedro[i]);
        if (i < octaedro - 1)
        {
            printf(", ");
        }
        else
        {
            printf("!\n");
        }
    }
}

int main()
{
    game();

    return 0;
}
