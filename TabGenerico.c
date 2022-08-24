#include <stdio.h>

#define TAM_MAX 7

static char tabuleiro1[5][TAM_MAX] = {
    {'a', 'D', 'D', 'b'},
    {'a', 'D', 'D', 'b'},
    {'c', 'd', 'd', 'e'},
    {'c', 'g', 'h', 'e'},
    {'f', ' ', ' ', 'i'}};
    
static char tabuleiro2[5][TAM_MAX] = {
    {'D', 'D', ' ', 'a', 'a', 'b'},
    {'D', 'D', ' ', 'a', 'c', 'd'},
    {'e', 'e', 'f', 'g', 'd', 'd'},
    {'h', 'h', 'i', 'j', 'k', 'l'},
    {'h', 'i', 'i', 'm', 'k', 'l'}};

char jogo[5][TAM_MAX];

void criaTabuleiro(int num)
{
    num == 1 ? printf("* * * * * *\n") : printf("* * * * * * * *\n");
    
    int cont = 0;
    for (int i = 0; i < 5; i++)
    {
        printf("*");
        for (int j = 0; j < TAM_MAX; j++)
        {
          if(jogo[i][j] == '\0') continue;
          printf(" %c", jogo[i][j]);
        }
        (num == 2 && (cont == 3 || cont == 4)) ? printf("\n") : printf(" *\n");
        cont++;
    }
    num == 1 ? printf("* *     * *\n") : printf("* * * * * * * *\n");
}

void copiarMatriz(char matriz[TAM_MAX][TAM_MAX]){  
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < TAM_MAX; j++)
        {
            jogo[i][j] = matriz[i][j];
        }
    } 
}

int main() {
  int num = 2;
  num == 1 ? copiarMatriz(tabuleiro1) : copiarMatriz(tabuleiro2);
  criaTabuleiro(num);
  return 0;
}