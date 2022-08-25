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

void moverDireita(char tipo, char letra) // Funcional para tabuleiro 2
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (tabuleiro2[i][j] == letra)
            {
                if (tipo == 'D' && tabuleiro2[i][j + 2] == ' ' && tabuleiro2[i + 1][j + 2] == ' ')
                {
                    tabuleiro2[i][j + 2] = letra;
                    tabuleiro2[i + 1][j + 2] = letra;
                    tabuleiro2[i][j] = ' ';
                    tabuleiro2[i + 1][j] = ' ';
                    return;
                } else if (tipo == 'D') {
                    printf("\n Donzela - Nao e possivel mover peca\n");
                    return;
                }
                
                if (tipo == 'B' && tabuleiro2[i][j + 2] == ' ' && tabuleiro2[i + 1][j + 1] == ' ')
                {
                    tabuleiro2[i][j + 2] = letra;
                    tabuleiro2[i + 1][j + 1] = letra;
                    tabuleiro2[i][j] = ' ';
                    tabuleiro2[i + 1][j] = ' ';
                    return;
                } else if (tipo == 'B') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (tipo == 'P' && tabuleiro2[i][j + 1] == ' ' && tabuleiro2[i + 1][j + 1] == ' ')
                {
                    tabuleiro2[i][j + 1] = letra;
                    tabuleiro2[i + 1][j + 1] = letra;
                    tabuleiro2[i][j] = ' ';
                    tabuleiro2[i + 1][j] = ' ';
                    return;
                } else if (tipo == 'P') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (tipo == 'Q' && tabuleiro2[i][j + 1] == ' ')
                {
                    tabuleiro2[i][j + 1] = letra;
                    tabuleiro2[i][j] = ' ';
                    return;
                } else if (tipo == 'Q') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (tipo == 'S' && tabuleiro2[i][j + 2] == ' ')
                {
                    tabuleiro2[i][j + 2] = letra;
                    tabuleiro2[i][j] = ' ';
                    return;
                } else if (tipo == 'S') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (tipo = 'C' && tabuleiro2[i][j + 1] == ' ' && tabuleiro2[i + 1][j + 1] == ' ')
                {
                    tabuleiro2[i][j + 1] = letra;
                    tabuleiro2[i + 1][j + 1] = letra;
                    tabuleiro2[i][j] = ' ';
                    tabuleiro2[i + 1][j - 1] = ' ';
                    return;
                } else {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
            }
        }
    }
    criaTabuleiroDois();
}

char checarTipoPeca(char letra) //Funcional - tabuleiro2
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (tabuleiro2[i][j] == letra) {
                // avalia repetição de letras horizontais
                // tipo 1 / tipo 2 / tipo 3
                if (tabuleiro2[i][j + 1]  == letra)
                {
                    // verifica se possui pelo menos 1 letra abaixo
                    if(tabuleiro2[i + 1][j]  == letra) {
                        // verifica se é a donzela
                        if (tabuleiro2[i + 1][j + 1]  == letra)
                        {
                           return 'D';
                        }
                        return 'B';                        
                    }
                    return 'S';
                } else if (tabuleiro2[i + 1][j]  == letra) // avalia repetição de letras verticais sem a primeira linha horizontal
                {
                    if (j != 0 && tabuleiro2[i + 1][j - 1]  == letra)
                    {
                        return 'C';
                    }
                    
                    return 'P';
                } else return 'Q'; // avalia se é peça única                
            }
        }
    }
}


int main()
{
    char letra = 'k';
    printf("%s", "Configuracao 2 \n\n");
    criaTabuleiroDois();
    char tipo = checarTipoPeca(letra);
    printf("\npeca movida - tipo: %c\n", tipo);
    moverDireita(tipo, letra);
    criaTabuleiroDois();

    return 0;
}