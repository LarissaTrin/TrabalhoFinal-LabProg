#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_COL 7
#define MAX_INPUT_USER 10

void printarTabuleiro(int num, char tabuleiro[5][TAM_MAX_COL])
{
    num == 1 ? printf("    1 2 3 4  \n") : printf("    1 2 3 4 5 6  \n");
    num == 1 ? printf("  * * * * * *\n") : printf("  * * * * * * * *\n");

    int cont = 0;
    for (int i = 0; i < 5; i++)
    {
        printf("%d *", i + 1);
        for (int j = 0; j < TAM_MAX_COL; j++)
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

void copiarMatriz(char matriz[5][TAM_MAX_COL], char tabuleiroJogo[5][TAM_MAX_COL])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < TAM_MAX_COL; j++)
        {
            tabuleiroJogo[i][j] = matriz[i][j];
        }
    }
}

typedef struct node
{
    char fotoTabuleiroAtual[5][TAM_MAX_COL];
    int numTabuleiro;
    struct node *proximo;
} Node;

typedef struct nodeTree
{
    char fotoTabuleiroAtual[5][TAM_MAX_COL];
    int numTabuleiro;
    struct nodeTree *f1, *f2, *f3, *f4, *f5, *f6, *f7, *f8, *prev;
} NodeTree;

NodeTree *criarNodeTree()
{
    NodeTree *novoNode = (NodeTree *)malloc(sizeof(NodeTree));
    return novoNode;
}

NodeTree *inserirNodeTreeFilho(NodeTree *arvore, int configTabuleiro, char tabuleiroJogo[5][TAM_MAX_COL], Node *sugestao)
{
    NodeTree *novoNode = criarNodeTree();
    copiarMatriz(tabuleiroJogo, novoNode->fotoTabuleiroAtual);
    novoNode->numTabuleiro = configTabuleiro;
    int i = 1;

    if (arvore == NULL)
    {
        arvore = novoNode;
        novoNode->prev = NULL;
        novoNode->f1 = NULL;
        novoNode->f2 = NULL;
        novoNode->f3 = NULL;
        novoNode->f4 = NULL;
        novoNode->f5 = NULL;
        novoNode->f6 = NULL;
        novoNode->f7 = NULL;
        novoNode->f8 = NULL;
        copiarMatriz(novoNode->fotoTabuleiroAtual, tabuleiroJogo);


        while (sugestao->proximo != NULL)
        {
            if (i==1)
            {
                copiarMatriz(novoNode->f1->fotoTabuleiroAtual, tabuleiroJogo);
                novoNode->f1->prev = novoNode;
                novoNode->f1->numTabuleiro = configTabuleiro;
            } else if (i==2)
            {
                copiarMatriz(novoNode->f2->fotoTabuleiroAtual, tabuleiroJogo);
                novoNode->f2->prev = novoNode;
                novoNode->f2->numTabuleiro = configTabuleiro;
            } else if (i==3)
            {
                copiarMatriz(novoNode->f3->fotoTabuleiroAtual, tabuleiroJogo);
                novoNode->f3->prev = novoNode;
                novoNode->f3->numTabuleiro = configTabuleiro;
            } else if (i==4)
            {
                copiarMatriz(novoNode->f4->fotoTabuleiroAtual, tabuleiroJogo);
                novoNode->f4->prev = novoNode;
                novoNode->f4->numTabuleiro = configTabuleiro;
            } else if (i==5)
            {
                copiarMatriz(novoNode->f5->fotoTabuleiroAtual, tabuleiroJogo);
                novoNode->f5->prev = novoNode;
                novoNode->f5->numTabuleiro = configTabuleiro;
            } else if (i==6)
            {
                copiarMatriz(novoNode->f6->fotoTabuleiroAtual, tabuleiroJogo);
                novoNode->f6->prev = novoNode;
                novoNode->f6->numTabuleiro = configTabuleiro;
            } else if (i==7)
            {
                copiarMatriz(novoNode->f7->fotoTabuleiroAtual, tabuleiroJogo);
                novoNode->f7->prev = novoNode;
                novoNode->f7->numTabuleiro = configTabuleiro;
            } else if (i==8)
            {
                copiarMatriz(novoNode->f8->fotoTabuleiroAtual, tabuleiroJogo);
                novoNode->f8->prev = novoNode;
                novoNode->f8->numTabuleiro = configTabuleiro;
            }
            
            sugestao = sugestao->proximo;
            ++i;
        }
    }
    else
    {
        NodeTree *auxiliar = arvore;

        while ((auxiliar->proximo) != NULL) //percorrer a arvore
        {
            auxiliar = auxiliar->proximo;
        }

        auxiliar->proximo = novoNode;
        novoNode->proximo = NULL;
    }

    return arvore;
}


void recurssividade(NodeTree *arvore, NodeTree filho) {
    
}