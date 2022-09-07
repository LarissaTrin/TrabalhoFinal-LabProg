#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printarTabuleiro(int num, char tabuleiro[5][7])
{
    num == 1 ? printf("    1 2 3 4  \n") : printf("    1 2 3 4 5 6  \n");
    num == 1 ? printf("  * * * * * *\n") : printf("  * * * * * * * *\n");

    int cont = 0;
    for (int i = 0; i < 5; i++)
    {
        printf("%d *", i+1);
        for (int j = 0; j < 7; j++)
        {
            if (tabuleiro[i][j] == '\0')
                continue;
            printf(" %c", tabuleiro[i][j]);
        }
        (num == 2 && (cont == 3 || cont == 4)) ? printf("\n") : printf(" *\n");
        cont++;
    }
    num == 1 ? printf("  * *     * *\n") : printf("  * * * * * * * *\n");
}

int main() {

    char* nomeArquivoTxt = "haikori.txt";
    FILE *arqTxtTabuleiros;
    char str1;
    
    arqTxtTabuleiros = fopen(nomeArquivoTxt,"r");

    printf("\n Nome do arquivo: %s\n", nomeArquivoTxt);

    char tabuleiro1[5][7] = {
    {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
    {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
    {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
    {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
    {'\0', '\0', '\0', '\0', '\0', '\0', '\0'}};

    char tabuleiro2[5][7] = {
    {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
    {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
    {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
    {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
    {'\0', '\0', '\0', '\0', '\0', '\0', '\0'}};

	// char titulo1[14];
    // titulo1 n escrito
    char titulo1Nome[14];
    int titulo1 = 0;
    int i = 0;
    int j = 0;
    // char titulo1[15];
    // titulo2 n escrito
    char titulo2Nome[15];
    int titulo2 = 0;

    int contN = 0;

    str1 = fgetc(arqTxtTabuleiros);
	while (str1 != EOF)
		{            
            if (str1 != '\n' && str1 != '*' && str1 != '\0')
            {
                if (titulo1 == 0)
                {
                    titulo1Nome[i] = str1;
                    ++i;
                }
                if ((titulo2 == 0) && (titulo1 == 1) && (contN == 9))
                {
                    titulo2Nome[i] = str1;
                    ++i;
                }
                if ((titulo1 == 1) && (titulo2 == 0) && (contN < 7))
                {
                    tabuleiro1[i][j] = str1;
                    ++j;
                }
                if ((titulo2 == 1) && (contN >= 11))
                {
                    tabuleiro2[i][j] = str1;
                    ++j;
                }
            }
            if (str1 == '\n')
            {
                ++contN;
                if (titulo1 == 0)
                {
                    titulo1 = 1;
                    titulo1Nome[i] = '\0';
                    i = 0;
                }
                if ((titulo2 == 0) && (titulo1 == 1) && (contN == 10))
                {
                    titulo2 = 1;
                    titulo2Nome[i] = '\0';
                    i = 0;
                }
                if ((titulo1 == 1) && (titulo2 == 0) && (contN > 2) && (contN < 7))
                {
                    ++i;
                    j = 0;
                }
                if (contN == 7)
                {
                    i = 0;
                    j = 0;
                }
                if ((titulo2 == 1) && (contN > 11) && (contN < 16))
                {
                    ++i;
                    j = 0;
                }
            }
			str1 = fgetc(arqTxtTabuleiros);
		}
    printf("\n\n");

    // printf("TESTE 1: %s\n", titulo1Nome);
    // printf("TESTE 2: %s\n", titulo2Nome);
    // printf("TABULEIRO 1:\n");
    // printarTabuleiro(1,tabuleiro1);
    printf("\n\nTABULEIRO 2:\n");
    printarTabuleiro(2,tabuleiro2);
    fclose (arqTxtTabuleiros);
}