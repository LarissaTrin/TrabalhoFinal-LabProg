#include <stdio.h>
#include <stdlib.h>
   
static char tabuleiro2[5][7] = {
    {'D', 'D', ' ', 'a', 'a', 'b', '\0'},
    {'D', 'D', ' ', 'a', 'c', 'd', '\0'},
    {'e', 'e', 'f', 'g', 'd', 'd', '\0'},
    {'h', 'h', 'i', 'j', 'k', 'l', '\0'},
    {'h', 'i', 'i', 'm', 'k', 'l', '\0'}};

typedef struct node{
    char fotoTabuleiroAtual[5][7];
    struct node *proximo;
}Node;

void printarTabuleiro(int num, char tabuleiro[5][7])
{
    num == 1 ? printf("    1 2 3 4  \n") : printf("    1 2 3 4 5 6  \n");
    num == 1 ? printf("  * * * * * *\n") : printf("  * * * * * * * *\n");

    int cont = 0;
    for (int i = 0; i < 5; i++)
    {
        printf("%d *", i + 1);
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

void copiarMatriz(char matriz[5][7], char tabuleiroJogo[5][7])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            tabuleiroJogo[i][j] = matriz[i][j];
        }
    }
}

Node* criarNode(){
    Node *novo = (Node*)malloc(sizeof(Node));
    return novo;
}

Node* inserirNodeNoFim(Node* historico, char matriz[5][7]){
    Node *novoNode = criarNode();
    copiarMatriz(tabuleiro2, novoNode -> fotoTabuleiroAtual);

    if (historico == NULL){
        historico = novoNode;
        novoNode -> proximo = NULL;
    } else {
        Node *auxiliar = historico;

        while ((auxiliar -> proximo) != NULL){
            auxiliar = auxiliar -> proximo;
        }

        auxiliar -> proximo = novoNode;
        novoNode -> proximo = NULL;
    }

    return historico;
}

void mostrarHistorico(Node* historico){
    Node *auxiliar = historico;

    while (auxiliar != NULL){
        printarTabuleiro(2, auxiliar -> fotoTabuleiroAtual);
        printf("\n");
        auxiliar = auxiliar -> proximo;
    }
}

int main(){

    Node *historico = NULL;

    historico = inserirNodeNoFim(historico, tabuleiro2);
    historico = inserirNodeNoFim(historico, tabuleiro2);
   
    mostrarHistorico(historico);

    return 0;
}