#include <stdio.h>

//Definição das cores pelo console
// #define PRETO "\e[40m  \e[49m"
// #define VERMELHO  "\e[41m  \e[49m"
// #define VERMELHO "\x1b[31m"
// #define VERDE  "\e[42m  \e[49m"
// #define MARROM  "\e[43m  \e[49m"
// #define AZUL  "\e[44m  \e[49m"
// #define MAGENTA  "\e[45m  \e[49m"
// #define CIANO  "\e[46m  \e[49m"
// #define CINZA "\e[47m  \e[49m"

static char tabuleiro1[5][5] = {
    {'a','D','D','b'},
    {'a','D','D','b'},
    {'c','d','d','e'},
    {'c','g','h','e'},
    {'f',' ',' ','i'}
};

// * * * * * *
// * a D D b *
// * a D D b *
// * c d d e *
// * c g h e *
// * f     i *
// * *     * *

void criaTtabuleiro() {
    printf("* * * * * *\n"); 
    for (int i = 0; i < 5; i++)
    {
        printf("*");
        for (int j = 0; j < 5; j++)
        {
            printf(" %c",tabuleiro1[i][j]);
        }
        printf("*\n");
    }
    printf("* *     * *\n");
    
}

void movimento() {

}

int main() {
    criaTtabuleiro();

    // char test[4] = "oi\n";
    // printf(VERMELHO "oi");
    // printf(VERDE); 
    // printf(CINZA); 
    // printf(MARROM);
    // printf(AZUL); 
    // printf(PRETO); 
    // printf(MAGENTA); 
    // printf(CIANO); 
    // printf(CIANO);

    return 0;
}