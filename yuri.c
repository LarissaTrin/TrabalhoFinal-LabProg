#include <stdio.h>

static char tabuleiro1[5][4] = {
    {'a', 'D', 'D', 'b'},
    {'a', 'D', 'D', 'b'},
    {'c', 'd', 'd', 'e'},
    {'c', 'g', 'h', 'e'},
    {'f', ' ', ' ', 'i'}};

char tabuleiro2[5][6] = {
    {'D', 'D', ' ', 'a', 'a', ' '},
    {'D', 'D', ' ', 'a', ' ', 'd'},
    {'e', 'e', ' ', 'g', 'd', 'd'},
    {'h', 'h', 'i', 'j', 'k', ' '},
    {'h', 'i', 'i', 'm', 'k', ' '}};

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

void moverDireita(char letra)
{
    int iDupla, jDupla = 0;
    int cont = 0;
    char tipo = ' ';
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (tabuleiro2[i][j] == letra)
            {

                if (tabuleiro2[i][j + 1] != ' ' && tabuleiro2[i][j + 1] != letra)
                {
                    break;
                }

                /// Caso seja duas letras iguais lado a lado
                if (tabuleiro2[i][j + 1] == letra)
                {
                    tipo = '2';
                    /// Caso seja duas letras iguais lado a lado
                    if (tabuleiro2[i][j + 2] == ' ')
                    {
                        cont++;
                        /// Caso seja peça maior de 4 letras 'D'
                        if (cont == 2)
                        {

                            tabuleiro2[i][j] = ' ';
                            tabuleiro2[i][j + 2] = letra;

                            tabuleiro2[iDupla][jDupla] = ' ';
                            tabuleiro2[iDupla][jDupla + 2] = letra;
                            break;
                        }

                        iDupla = i;
                        jDupla = j;
                    }
                    else
                    {
                        break;
                    }
                }

                if (tabuleiro2[i][j + 1] == ' ' && tipo != '2')
                {
                    tipo = '3';
                    cont++;

                    if (cont == 2)
                    {

                        tabuleiro2[i][j] = ' ';
                        tabuleiro2[i][j + 1] = letra;

                        tabuleiro2[iDupla][jDupla] = ' ';
                        tabuleiro2[iDupla][jDupla + 1] = letra;
                        break;
                    }

                    iDupla = i;
                    jDupla = j;
                }
            }
        }
    }

    if (tipo = '3' && cont == 1)
    {
        tipo = '4';
        tabuleiro2[iDupla][jDupla] = ' ';
        tabuleiro2[iDupla][jDupla + 1] = letra;
    }

    criaTabuleiroDois();
}
// D - tipo donzela - D
// L cabeça para baixo - tipo barraca - B
// i em pé - tipo poste - P
// quadrado unico - tipo quadrado - Q
// i deitado - tipo saco de dormir - S
// L invertido - tipo cadeira - C
char checarTipoPeca(char letra)
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
    // char letra = 'k';
    // printf("Movendo 'k' para direita \n");
    // moverDireita(letra);
    // printf("\n");
    // printf("Movendo 'j' para direita \n");
    // letra = 'j';
    // printf("\n");
    // moverDireita(letra);
    // printf("Tendando 'j' para direita (n deve funcionar) \n");
    // letra = 'j';
    // moverDireita(letra);
    // printf("\n");
    // printf("Movendo 'm' para direita ) \n");
    // letra = 'm';
    // moverDireita(letra);
    // printf("Movendo 'D' para direita ) \n");
    // letra = 'D';
    // moverDireita(letra);
    // printf("Movendo 'e' para direita ) \n");
    // letra = 'e';
    // moverDireita(letra);
    // printf("Movendo 'a' para direita ) \n");
    // letra = 'a';
    // moverDireita(letra);
    
    printf("Tipo da peca 'D': ");
    char tipo = checarTipoPeca('D');
    printf("%c\n", tipo);

    printf("Tipo da peca 'a': ");
    tipo = checarTipoPeca('a');
    printf("%c\n", tipo);

    printf("Tipo da peca 'k': ");
    tipo = checarTipoPeca('k');
    printf("%c\n", tipo);

    printf("Tipo da peca 'i': ");
    tipo = checarTipoPeca('i');
    printf("%c\n", tipo);

    printf("Tipo da peca 'j': ");
    tipo = checarTipoPeca('j');
    printf("%c\n", tipo);

    printf("Tipo da peca 'e': ");
    tipo = checarTipoPeca('e');
    printf("%c\n", tipo);
    return 0;
}