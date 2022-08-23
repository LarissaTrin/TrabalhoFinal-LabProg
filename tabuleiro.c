#include <stdio.h>

static char tabuleiro1[5][4] = {
    {'a', 'D', 'D', 'b'},
    {'a', 'D', 'D', 'b'},
    {'c', 'd', 'd', 'e'},
    {'c', 'g', 'h', 'e'},
    {'f', ' ', ' ', 'i'}};

static char tabuleiro2[5][6] = {
    {'D', 'D', ' ', 'a', 'a', 'b'},
    {'D', 'D', ' ', 'a', 'c', 'd'},
    {'e', 'e', 'f', 'g', 'd', 'd'},
    {'h', 'h', 'i', 'j', 'k', 'l'},
    {'h', 'i', 'i', 'm', 'k', 'l'}};

char jogo[5][6];

void criaTabuleiroUm()
{
    printf("* * * * * *\n");
    for (int i = 0; i < 5; i++)
    {
        printf("*");
        for (int j = 0; j < 4; j++)
        {
            printf(" %c", tabuleiro1[i][j]);
        }
        printf(" *\n");
    }
    printf("* *     * *\n");
}

void criaTabuleiroDois()
{
    int cont = 0;
    printf("* * * * * * * *\n");
    for (int i = 0; i < 5; i++)
    {
        printf("*");
        for (int j = 0; j < 6; j++)
        {
            printf(" %c", tabuleiro2[i][j]);
        }
        cont == 3 || cont == 4 ? printf("\n") : printf(" *\n");
        cont++;
    }
    printf("* * * * * * * *\n");
}

void movimento()
{
}

int main()
{
    printf("%s", "Configuracao 1 \n\n");
    criaTabuleiroUm();
    printf("\n");
    printf("%s", "Configuracao 2 \n\n");
    criaTabuleiroDois();

    return 0;
}