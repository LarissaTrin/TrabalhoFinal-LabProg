#include <stdio.h>

#define TAM_MAX_COL 7

static char tabuleiro1[5][TAM_MAX_COL] = {
    {'a', 'D', 'D', 'b', '\0', '\0', '\0'},
    {'a', 'D', 'D', 'b', '\0', '\0', '\0'},
    {'c', 'd', 'd', 'e', '\0', '\0', '\0'},
    {'c', 'g', 'h', 'e', '\0', '\0', '\0'},
    {'f', ' ', ' ', 'i', '\0', '\0', '\0'}};
    
static char tabuleiro2[5][TAM_MAX_COL] = {
    {'D', 'D', ' ', 'a', 'a', 'b', '\0'},
    {'D', 'D', ' ', 'a', 'c', 'd', '\0'},
    {'e', 'e', 'f', 'g', 'd', 'd', '\0'},
    {'h', 'h', 'i', 'j', 'k', 'l', '\0'},
    {'h', 'i', 'i', 'm', 'k', 'l', '\0'}};

char tabuleiroJogo[5][TAM_MAX_COL];

void printaTabuleiro(int num)
{
    num == 1 ? printf("* * * * * *\n") : printf("* * * * * * * *\n");
    
    int cont = 0;
    for (int i = 0; i < 5; i++)
    {
        printf("*");
        for (int j = 0; j < TAM_MAX_COL; j++)
        {
          if(tabuleiroJogo[i][j] == '\0') continue;
          printf(" %c", tabuleiroJogo[i][j]);
        }
        (num == 2 && (cont == 3 || cont == 4)) ? printf("\n") : printf(" *\n");
        cont++;
    }
    num == 1 ? printf("* *     * *\n") : printf("* * * * * * * *\n");
}

void copiarMatriz(char matriz[5][TAM_MAX_COL]){  
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < TAM_MAX_COL; j++)
        {
            tabuleiroJogo[i][j] = matriz[i][j];
        }
    } 
}

int main() {
  int num = 1;
  num == 1 ? copiarMatriz(tabuleiro1) : copiarMatriz(tabuleiro2);
  printaTabuleiro(num);
  return 0;
}