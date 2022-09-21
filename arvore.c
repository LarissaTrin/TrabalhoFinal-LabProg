#include <stdio.h>
#include <stdlib.h>

// cria a struct
typedef struct nodeTree
{
    int fotoTabuleiroAtual;
    int numTabuleiro;
    struct nodeTree *filhos[8];
    struct nodeTree *pai;
    int quantChaves;
} NodeTree;

// cria um novo no e inicializa seus campos zerados
NodeTree *inserirRaizTree(NodeTree *arvore, int tab, int numTab, NodeTree *ptPai)
{
    // printf("\nInserir raiz\n");
    NodeTree *novoNode = malloc(sizeof(NodeTree));
    if (arvore == NULL)
    {
        // printf("arvore NULL\n");
        // é verdadeira penas a primeira vez para criar a raiz primaria
        novoNode->fotoTabuleiroAtual = tab;
        novoNode->numTabuleiro = numTab;
        novoNode->pai = ptPai;
        novoNode->filhos[0] = NULL;
        novoNode->filhos[1] = NULL;
        novoNode->filhos[2] = NULL;
        novoNode->filhos[3] = NULL;
        novoNode->filhos[4] = NULL;
        novoNode->filhos[5] = NULL;
        novoNode->filhos[6] = NULL;
        novoNode->filhos[7] = NULL;
    }
    // printf("foto tab atual: %d\n", novoNode->fotoTabuleiroAtual);
    return novoNode;
}

NodeTree *inserirFilhoTree(NodeTree *arvore, int numTab, int sugest[8])
{
    int i = 0;
    while (i < 8 && sugest[i] != 0)
    {
        if (i == 0)
        {
            arvore->filhos[i] = inserirRaizTree(arvore->filhos[i], sugest[i], numTab, arvore);
        }
        if (i == 1)
        {
            arvore->filhos[i] = inserirRaizTree(arvore->filhos[i], sugest[i], numTab, arvore);
        }
        if (i == 2)
        {
            arvore->filhos[i] = inserirRaizTree(arvore->filhos[i], sugest[i], numTab, arvore);
        }
        if (i == 3)
        {
            arvore->filhos[i] = inserirRaizTree(arvore->filhos[i], sugest[i], numTab, arvore);
        }
        if (i == 4)
        {
            arvore->filhos[i] = inserirRaizTree(arvore->filhos[i], sugest[i], numTab, arvore);
        }
        if (i == 5)
        {
            arvore->filhos[i] = inserirRaizTree(arvore->filhos[i], sugest[i], numTab, arvore);
        }
        if (i == 6)
        {
            arvore->filhos[i] = inserirRaizTree(arvore->filhos[i], sugest[i], numTab, arvore);
        }
        if (i == 7)
        {
            arvore->filhos[i] = inserirRaizTree(arvore->filhos[i], sugest[i], numTab, arvore);
        }
        ++i;
    }
    return arvore;
}

int testFim(int sugestaoTest[8], char test, int testFim)
{
    int fim = 1;
    // for (int i = 0; i < 8; i++)
    // {
    //     sugestaoTest[i] = sugestaoTest[i] * 10;
    // }
    if (testFim == 3) return 0;
    
    return fim;
}

void imprimir(NodeTree *raiz) {
    if (raiz)
    {
        printf("%d   ", raiz->fotoTabuleiroAtual);
        for (int i = 0; i < 8; i++)
        {
            imprimir(raiz->filhos[i]);
        }
    }
    // printf("\n");    
}


int recursividade(NodeTree *arvore, int sugestaoTest[8], int cont) {
    int fim = 0;
    if (cont == 0)
    {
        return 1;
    }

    NodeTree *aux = arvore;
    aux = inserirFilhoTree(aux, 1, sugestaoTest);

    int sugestaoTestinho[8] = {0,0,0,0,0,0,0,0};
    
    for (int i = 0; i < 8; i++)
    {
        sugestaoTestinho[i] = sugestaoTest[i] * 10;
    }

    for (int i = 0; i < 8; i++)
    {
        fim = recursividade(aux->filhos[i], sugestaoTestinho, cont - 1);
    }
    
    return 0;
}

int main()
{

    // char sugestao[8] = {'1','2','3','4','5','6','7','8'};
    int fim = 1;
    int tabuleiro = 20;
    int sugestao[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    NodeTree *arvore = NULL;

    arvore = inserirRaizTree(arvore, tabuleiro, 1, NULL);
    printf("TEST: %d\n", arvore->fotoTabuleiroAtual);
    NodeTree *aux = arvore;
    int i = 0;

    int x = recursividade(aux, sugestao, 3);

    // NodeTree *colega = arvore;

    // colega = colega->filhos[4];
    // printf("colega = colega->filhos[4]: %d\n",colega->fotoTabuleiroAtual);
    // printf("colega->pai: %d\n",colega->pai->fotoTabuleiroAtual);
    // colega = colega->filhos[5];
    // printf("colega = colega->filhos[5]: %d\n",colega->fotoTabuleiroAtual);
    // printf("colega->pai: %d\n",colega->pai->fotoTabuleiroAtual);

    // printf("\n\nVOLTA\n");
    // colega = colega->pai;
    // printf("colega = colega->pai: %d\n",colega->fotoTabuleiroAtual);
    // colega = colega->pai;
    // printf("colega = colega->pai: %d\n",colega->fotoTabuleiroAtual);

    // printf("\n\nIDA NOVA\n");
    // colega = colega->filhos[3];
    // printf("colega = colega->filhos[3]: %d\n",colega->fotoTabuleiroAtual);
    // printf("colega->pai: %d\n",colega->pai->fotoTabuleiroAtual);


    // imprimir(arvore);
    return 0;
}