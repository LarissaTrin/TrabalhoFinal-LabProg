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

int moverDireita(char tipo, char letra, char tabuleiroJogo[5][TAM_MAX_COL])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (tabuleiroJogo[i][j] == letra)
            {
                if (tipo == 'D' && tabuleiroJogo[i][j + 2] == ' ' && tabuleiroJogo[i + 1][j + 2] == ' ')
                {
                    tabuleiroJogo[i][j + 2] = letra;
                    tabuleiroJogo[i + 1][j + 2] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return 1;
                }
                else if (tipo == 'D')
                {
                    return 0;
                }

                if (tipo == 'B' && tabuleiroJogo[i][j + 2] == ' ' && tabuleiroJogo[i + 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i][j + 2] = letra;
                    tabuleiroJogo[i + 1][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return 1;
                }
                else if (tipo == 'B')
                {
                    return 0;
                }
                if (tipo == 'P' && tabuleiroJogo[i][j + 1] == ' ' && tabuleiroJogo[i + 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i][j + 1] = letra;
                    tabuleiroJogo[i + 1][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return 1;
                }
                else if (tipo == 'P')
                {
                    return 0;
                }
                if (tipo == 'Q' && tabuleiroJogo[i][j + 1] == ' ')
                {
                    tabuleiroJogo[i][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    return 1;
                }
                else if (tipo == 'Q')
                {
                    return 0;
                }
                if (tipo == 'S' && tabuleiroJogo[i][j + 2] == ' ')
                {
                    tabuleiroJogo[i][j + 2] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    return 1;
                }
                else if (tipo == 'S')
                {
                    return 0;
                }
                if (tipo == 'C' && tabuleiroJogo[i][j + 1] == ' ' && tabuleiroJogo[i + 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i][j + 1] = letra;
                    tabuleiroJogo[i + 1][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j - 1] = ' ';
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    printf("INTERNAL ERROR");
    return 0;
}

int moverEsquerda(char tipo, char letra, char tabuleiroJogo[5][TAM_MAX_COL])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (tabuleiroJogo[i][j] == letra)
            {
                if (j > 0 && tipo == 'D' && tabuleiroJogo[i][j - 1] == ' ' && tabuleiroJogo[i + 1][j - 1] == ' ')
                {
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i + 1][j - 1] = letra;
                    tabuleiroJogo[i][j + 1] = ' ';
                    tabuleiroJogo[i + 1][j + 1] = ' ';
                    return 1;
                }
                else if (tipo == 'D')
                {
                    return 0;
                }

                if (j > 0 && tipo == 'B' && tabuleiroJogo[i][j - 1] == ' ' && tabuleiroJogo[i + 1][j - 1] == ' ')
                {
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i + 1][j - 1] = letra;
                    tabuleiroJogo[i][j + 1] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return 1;
                }
                else if (tipo == 'B')
                {
                    return 0;
                }
                if (j > 0 && tipo == 'P' && tabuleiroJogo[i][j - 1] == ' ' && tabuleiroJogo[i + 1][j - 1] == ' ')
                {
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i + 1][j - 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return 1;
                }
                else if (tipo == 'P')
                {
                    return 0;
                }
                if (j > 0 && tipo == 'Q' && tabuleiroJogo[i][j - 1] == ' ')
                {
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    return 1;
                }
                else if (tipo == 'Q')
                {
                    return 0;
                }
                if (j > 0 && tipo == 'S' && tabuleiroJogo[i][j - 1] == ' ')
                {
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i][j + 1] = ' ';
                    return 1;
                }
                else if (tipo == 'S')
                {
                    return 0;
                }
                if (j > 0 && tipo == 'C' && tabuleiroJogo[i][j - 1] == ' ' && tabuleiroJogo[i + 1][j - 2] == ' ')
                {
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i + 1][j - 2] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    printf("INTERNAL ERROR");
    return 0;
}

int moverTopo(char tipo, char letra, char tabuleiroJogo[5][TAM_MAX_COL])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (tabuleiroJogo[i][j] == letra)
            {
                if (i > 0 && tipo == 'D' && tabuleiroJogo[i - 1][j] == ' ' && tabuleiroJogo[i - 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i - 1][j] = letra;
                    tabuleiroJogo[i - 1][j + 1] = letra;
                    tabuleiroJogo[i + 1][j] = ' ';
                    tabuleiroJogo[i + 1][j + 1] = ' ';
                    return 1;
                }
                else if (tipo == 'D')
                {
                    return 0;
                }

                if (i > 0 && tipo == 'B' && tabuleiroJogo[i - 1][j] == ' ' && tabuleiroJogo[i - 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i - 1][j] = letra;
                    tabuleiroJogo[i - 1][j + 1] = letra;
                    tabuleiroJogo[i][j + 1] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return 1;
                }
                else if (tipo == 'B')
                {
                    return 0;
                }
                if (i > 0 && tipo == 'P' && tabuleiroJogo[i - 1][j] == ' ')
                {
                    tabuleiroJogo[i - 1][j] = letra;
                    tabuleiroJogo[i + 1][j] = ' ';
                    return 1;
                }
                else if (tipo == 'P')
                {
                    return 0;
                }
                if (i > 0 && tipo == 'Q' && tabuleiroJogo[i - 1][j] == ' ')
                {
                    tabuleiroJogo[i - 1][j] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    return 1;
                }
                else if (tipo == 'Q')
                {
                    return 0;
                }
                if (i > 0 && tipo == 'S' && tabuleiroJogo[i - 1][j] == ' ' && tabuleiroJogo[i - 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i - 1][j] = letra;
                    tabuleiroJogo[i - 1][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i][j + 1] = ' ';
                    return 1;
                }
                else if (tipo == 'S')
                {
                    return 0;
                }
                if (tipo == 'C' && tabuleiroJogo[i - 1][j] == ' ' && tabuleiroJogo[i][j - 1] == ' ')
                {
                    tabuleiroJogo[i - 1][j] = letra;
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i + 1][j] = ' ';
                    tabuleiroJogo[i + 1][j - 1] = ' ';
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    printf("INTERNAL ERROR");
    return 0;
}

int moverBaixo(char tipo, char letra, char tabuleiroJogo[5][TAM_MAX_COL])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (tabuleiroJogo[i][j] == letra)
            {
                if (i < 5 && tipo == 'D' && tabuleiroJogo[i + 2][j] == ' ' && tabuleiroJogo[i + 2][j + 1] == ' ')
                {
                    tabuleiroJogo[i + 2][j] = letra;
                    tabuleiroJogo[i + 2][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i][j + 1] = ' ';
                    return 1;
                }
                else if (tipo == 'D')
                {
                    return 0;
                }

                if (i < 5 && tipo == 'B' && tabuleiroJogo[i + 2][j] == ' ' && tabuleiroJogo[i + 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i + 2][j] = letra;
                    tabuleiroJogo[i + 1][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i][j + 1] = ' ';
                    return 1;
                }
                else if (tipo == 'B')
                {
                    return 0;
                }
                if (i < 5 && tipo == 'P' && tabuleiroJogo[i + 2][j] == ' ')
                {
                    if (i + 2 < 5)
                    {
                        tabuleiroJogo[i + 2][j] = letra;
                        tabuleiroJogo[i][j] = ' ';
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else if (tipo == 'P')
                {
                    return 0;
                }
                if (i < 5 && tipo == 'Q' && tabuleiroJogo[i + 1][j] == ' ')
                {
                    if (i + 1 < 5)
                    {
                        tabuleiroJogo[i + 1][j] = letra;
                        tabuleiroJogo[i][j] = ' ';
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else if (tipo == 'Q')
                {
                    return 0;
                }
                if (i < 5 && tipo == 'S' && tabuleiroJogo[i + 1][j] == ' ' && tabuleiroJogo[i + 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i + 1][j] = letra;
                    tabuleiroJogo[i + 1][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i][j + 1] = ' ';
                    return 1;
                }
                else if (tipo == 'S')
                {
                    return 0;
                }
                if (tipo == 'C' && tabuleiroJogo[i + 2][j] == ' ' && tabuleiroJogo[i + 2][j - 1] == ' ')
                {
                    tabuleiroJogo[i + 2][j] = letra;
                    tabuleiroJogo[i + 2][j - 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j - 1] = ' ';
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    printf("INTERNAL ERROR");
    return 0;
}

int moverDirecao(char direcao, char tipo, char letra, char tabuleiroJogo[5][TAM_MAX_COL])
{
    int pecaMov = 0;
    switch (direcao)
    {
    case 'D':
        pecaMov = moverDireita(tipo, letra, tabuleiroJogo);
        break;
    case 'E':
        pecaMov = moverEsquerda(tipo, letra, tabuleiroJogo);
        break;
    case 'T':
        pecaMov = moverTopo(tipo, letra, tabuleiroJogo);
        break;
    case 'B':
        pecaMov = moverBaixo(tipo, letra, tabuleiroJogo);
        break;
    default:
        printf("INTERNAL ERROR: DIRECAO INVALIDA");
        break;
    }
    return pecaMov;
}

char encontrarLetra(char char_i, char char_j, char tabuleiroJogo[5][TAM_MAX_COL])
{
    int i = (char_i - '0');
    int j = (char_j - '0');
    return tabuleiroJogo[i - 1][j - 1];
}

char checarTipoPeca(char letra, char tabuleiroJogo[5][TAM_MAX_COL])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (tabuleiroJogo[i][j] == letra)
            {
                if (tabuleiroJogo[i][j + 1] == letra)
                {
                    if (tabuleiroJogo[i + 1][j] == letra)
                    {
                        if (tabuleiroJogo[i + 1][j + 1] == letra)
                        {
                            return 'D';
                        }
                        return 'B';
                    }
                    return 'S';
                }
                else if (tabuleiroJogo[i + 1][j] == letra)
                {
                    if (j != 0 && tabuleiroJogo[i + 1][j - 1] == letra)
                    {
                        return 'C';
                    }

                    return 'P';
                }
                else
                    return 'Q';
            }
        }
    }
    printf("INTERNAL ERROR: TIPO INVALIDO");
    return 'e';
}
typedef struct node
{
    char fotoTabuleiroAtual[5][TAM_MAX_COL];
    int numTabuleiro;
    struct node *proximo;
} Node;

Node *criarNode()
{
    Node *novoNode = (Node *)malloc(sizeof(Node));
    return novoNode;
}

Node *inserirNodeNoFim(Node *historico, int configTabuleiro, char tabuleiroJogo[5][TAM_MAX_COL])
{ // insere novo node no fim do histórico

    printf("INSERIR NODE NO FIM ");

    Node *novoNode = criarNode();
    copiarMatriz(tabuleiroJogo, novoNode->fotoTabuleiroAtual);
    novoNode->numTabuleiro = configTabuleiro;

    if (historico == NULL)
    {
        historico = novoNode;
        novoNode->proximo = NULL;
    }
    else
    {
        Node *auxiliar = historico;

        while ((auxiliar->proximo) != NULL)
        {
            auxiliar = auxiliar->proximo;
        }

        auxiliar->proximo = novoNode;
        novoNode->proximo = NULL;
    }

    return historico;
}

typedef struct nodeTree
{
    char fotoTabuleiroAtual[5][TAM_MAX_COL];
    int numTabuleiro;
    struct nodeTree *f1, *f2, *f3, *f4, *f5, *f6, *f7, *f8, *pai;
} NodeTree;


NodeTree *criarNodeTree()
{
    printf("\nCRIAR NODE TREE\n");
    NodeTree *novoNode = (NodeTree *)malloc(sizeof(NodeTree));
    return novoNode;
}

NodeTree *inserirNodeTreeFilho(NodeTree *arvore, int configTabuleiro, char tabuleiroJogo[5][TAM_MAX_COL], Node *sugestao)
{
    NodeTree *novoNode = criarNodeTree();
    printf("\nInserirNodeTreeFilho\n");
    copiarMatriz(tabuleiroJogo, novoNode->fotoTabuleiroAtual);
    novoNode->numTabuleiro = configTabuleiro;
    int i = 1;

    if (arvore == NULL)
    {
        arvore = novoNode;
        novoNode->pai = NULL;
        novoNode->f1 = criarNodeTree();
        novoNode->f2 = criarNodeTree();
        novoNode->f3 = criarNodeTree();
        novoNode->f4 = criarNodeTree();
        novoNode->f5 = criarNodeTree();
        novoNode->f6 = criarNodeTree();
        novoNode->f7 = criarNodeTree();
        novoNode->f8 = criarNodeTree();

        while (sugestao->fotoTabuleiroAtual != NULL)
        {
            printf("\ni = %d", i);
            printf("\nIFS DO INSERIR NODE TREE FILHO\n");
            if (i == 1)
            {
                copiarMatriz(sugestao->fotoTabuleiroAtual, novoNode->f1->fotoTabuleiroAtual);
                novoNode->f1->pai = novoNode;
                novoNode->f1->numTabuleiro = configTabuleiro;
            }
            else if (i == 2)
            {
                copiarMatriz(sugestao->fotoTabuleiroAtual, novoNode->f2->fotoTabuleiroAtual);
                novoNode->f2->pai = novoNode;
                novoNode->f2->numTabuleiro = configTabuleiro;
            }
            else if (i == 3)
            {
                copiarMatriz(sugestao->fotoTabuleiroAtual, novoNode->f3->fotoTabuleiroAtual);
                novoNode->f3->pai = novoNode;
                novoNode->f3->numTabuleiro = configTabuleiro;
            }
            else if (i == 4)
            {
                copiarMatriz(sugestao->fotoTabuleiroAtual, novoNode->f4->fotoTabuleiroAtual);
                novoNode->f4->pai = novoNode;
                novoNode->f4->numTabuleiro = configTabuleiro;
            }
            else if (i == 5)
            {
                copiarMatriz(sugestao->fotoTabuleiroAtual, novoNode->f5->fotoTabuleiroAtual);
                novoNode->f5->pai = novoNode;
                novoNode->f5->numTabuleiro = configTabuleiro;
            }
            else if (i == 6)
            {
                copiarMatriz(sugestao->fotoTabuleiroAtual, novoNode->f6->fotoTabuleiroAtual);
                novoNode->f6->pai = novoNode;
                novoNode->f6->numTabuleiro = configTabuleiro;
            }
            else if (i == 7)
            {
                copiarMatriz(sugestao->fotoTabuleiroAtual, novoNode->f7->fotoTabuleiroAtual);
                novoNode->f7->pai = novoNode;
                novoNode->f7->numTabuleiro = configTabuleiro;
            }
            else if (i == 8)
            {
                copiarMatriz(sugestao->fotoTabuleiroAtual, novoNode->f8->fotoTabuleiroAtual);
                novoNode->f8->pai = novoNode;
                novoNode->f8->numTabuleiro = configTabuleiro;
            }

            sugestao = sugestao->proximo;
            ++i;
        }
    }
    else
    {
        novoNode->f1 = criarNodeTree();
        novoNode->f2 = criarNodeTree();
        novoNode->f3 = criarNodeTree();
        novoNode->f4 = criarNodeTree();
        novoNode->f5 = criarNodeTree();
        novoNode->f6 = criarNodeTree();
        novoNode->f7 = criarNodeTree();
        novoNode->f8 = criarNodeTree();

        printf("\nELSE DO INSERIR NODE TREE FILHO\n");
        while (sugestao->fotoTabuleiroAtual != NULL)
        {
            printf("\n %d", i);
            if (i == 1)
            {
                copiarMatriz(sugestao->fotoTabuleiroAtual, novoNode->f1->fotoTabuleiroAtual);
                printf("AAAAAAAAAAAAAAAAAAAAbbbbbbbb1, novoNode->f1->fotoTabuleiroAtual");
                printarTabuleiro(1, novoNode->f1->fotoTabuleiroAtual);
                novoNode->f1->pai = novoNode;
                novoNode->f1->numTabuleiro = configTabuleiro;
            }
            else if (i == 2)
            {
                copiarMatriz(sugestao->fotoTabuleiroAtual, novoNode->f2->fotoTabuleiroAtual);
                novoNode->f2->pai = novoNode;
                novoNode->f2->numTabuleiro = configTabuleiro;
            }
            else if (i == 3)
            {
                copiarMatriz(sugestao->fotoTabuleiroAtual, novoNode->f3->fotoTabuleiroAtual);
                novoNode->f3->pai = novoNode;
                novoNode->f3->numTabuleiro = configTabuleiro;
            }
            else if (i == 4)
            {
                copiarMatriz(sugestao->fotoTabuleiroAtual, novoNode->f4->fotoTabuleiroAtual);
                novoNode->f4->pai = novoNode;
                novoNode->f4->numTabuleiro = configTabuleiro;
            }
            else if (i == 5)
            {
                copiarMatriz(sugestao->fotoTabuleiroAtual, novoNode->f5->fotoTabuleiroAtual);
                novoNode->f5->pai = novoNode;
                novoNode->f5->numTabuleiro = configTabuleiro;
            }
            else if (i == 6)
            {
                copiarMatriz(sugestao->fotoTabuleiroAtual, novoNode->f6->fotoTabuleiroAtual);
                novoNode->f6->pai = novoNode;
                novoNode->f6->numTabuleiro = configTabuleiro;
            }
            else if (i == 7)
            {
                copiarMatriz(sugestao->fotoTabuleiroAtual, novoNode->f7->fotoTabuleiroAtual);
                novoNode->f7->pai = novoNode;
                novoNode->f7->numTabuleiro = configTabuleiro;
            }
            else if (i == 8)
            {
                copiarMatriz(sugestao->fotoTabuleiroAtual, novoNode->f8->fotoTabuleiroAtual);
                novoNode->f8->pai = novoNode;
                novoNode->f8->numTabuleiro = configTabuleiro;
            }

            sugestao = sugestao->proximo;
            ++i;
        }
    }

    return arvore;
}

int checaPaisIguais(NodeTree *no, char sugestao[5][TAM_MAX_COL])
{
    printf("\nCHECAPAPAIS\n");
    NodeTree *auxiliar = no;
    return 0;
    while ((auxiliar->pai) != NULL)
    {
        if (sugestao == auxiliar->fotoTabuleiroAtual)
        {
            // ignore
            return 1;
        }
        auxiliar = auxiliar->pai;
    }
    return 0;
}

Node *encontrarProxsJogadas(int configTabuleiro, char tabuleiroJogo[5][TAM_MAX_COL], Node *sugestoes, NodeTree *arvore) // Node* possiveisJogadas
{
    printf("\nEncontra proxs jogadas\n");
    Node *possiveisJogadas = sugestoes;
    NodeTree *auxiliarArvore = arvore;
    char tabuleiroAux[5][TAM_MAX_COL];
    copiarMatriz(tabuleiroJogo, tabuleiroAux);
    char tipoPeca = ' ';
    int movValido;
    int matrizRepetida;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (tabuleiroJogo[i][j] == ' ')
            {
                if (tabuleiroJogo[i][j + 1] == ' ')
                {
                    // vazio horizontal ['', '']
                    if (i > 0)
                    {
                        // Checando em cima
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i - 1][j], tabuleiroJogo);
                        movValido = moverDirecao('B', tipoPeca, tabuleiroJogo[i - 1][j], tabuleiroAux);
                        if (movValido)
                        {
                            // printf("Estive aqui 1\n");
                            matrizRepetida = checaPaisIguais(auxiliarArvore, tabuleiroAux);
                            if (!matrizRepetida)
                            {
                                possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            }
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                        if (tabuleiroJogo[i - 1][j] != tabuleiroJogo[i - 1][j + 1])
                        {
                            tipoPeca = checarTipoPeca(tabuleiroJogo[i - 1][j + 1], tabuleiroJogo);
                            movValido = moverDirecao('B', tipoPeca, tabuleiroJogo[i - 1][j + 1], tabuleiroAux);
                            if (movValido)
                            {
                                // printf("Estive aqui 2\n");
                                matrizRepetida = checaPaisIguais(auxiliarArvore, tabuleiroAux);
                                if (!matrizRepetida)
                                {
                                    possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                                }
                                copiarMatriz(tabuleiroJogo, tabuleiroAux);
                            }
                        }
                    }

                    if (i < 4)
                    {
                        // Checando embaixo
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i + 1][j], tabuleiroJogo);
                        movValido = moverDirecao('T', tipoPeca, tabuleiroJogo[i + 1][j], tabuleiroAux);
                        if (movValido)
                        {
                            // printf("Estive aqui 3 \n");
                            matrizRepetida = checaPaisIguais(auxiliarArvore, tabuleiroAux);
                            if (!matrizRepetida)
                            {
                                possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            }
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                        if (tabuleiroJogo[i + 1][j] != tabuleiroJogo[i + 1][j + 1])
                        {
                            tipoPeca = checarTipoPeca(tabuleiroJogo[i + 1][j + 1], tabuleiroJogo);
                            movValido = moverDirecao('T', tipoPeca, tabuleiroJogo[i + 1][j + 1], tabuleiroAux);
                            if (movValido)
                            {
                                // printf("Estive aqui 4 \n");
                                matrizRepetida = checaPaisIguais(auxiliarArvore, tabuleiroAux);
                                if (!matrizRepetida)
                                {
                                    possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                                }
                                copiarMatriz(tabuleiroJogo, tabuleiroAux);
                            }
                        }
                    }

                    if (j > 0)
                    {
                        // Checando esquerda
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i][j - 1], tabuleiroJogo);
                        movValido = moverDirecao('D', tipoPeca, tabuleiroJogo[i][j - 1], tabuleiroAux);
                        if (movValido)
                        {
                            // printf("Estive aqui 5\n");
                            matrizRepetida = checaPaisIguais(auxiliarArvore, tabuleiroAux);
                            if (!matrizRepetida)
                            {
                                possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            }
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                    }

                    int n = (configTabuleiro == 1 ? 3 : 5);

                    if (j < n)
                    {
                        // Checando direita
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i][j + 2], tabuleiroJogo);
                        movValido = moverDirecao('E', tipoPeca, tabuleiroJogo[i][j + 2], tabuleiroAux);
                        if (movValido)
                        {
                            // printf("Estive aqui 6\n");
                            matrizRepetida = checaPaisIguais(auxiliarArvore, tabuleiroAux);
                            if (!matrizRepetida)
                            {
                                possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            }
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                    }

                    return possiveisJogadas;
                }
                else if (tabuleiroJogo[i + 1][j] == ' ')
                {
                    if (i > 0)
                    {
                        // vazio Vertical ['']
                        //                ['']
                        // Checando em cima
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i - 1][j], tabuleiroJogo);
                        movValido = moverDirecao('B', tipoPeca, tabuleiroJogo[i - 1][j], tabuleiroAux);
                        if (movValido)
                        {
                            // printf("Estive aqui 7\n");
                            matrizRepetida = checaPaisIguais(auxiliarArvore, tabuleiroAux);
                            if (!matrizRepetida)
                            {
                                possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            }
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                    }

                    if (i < 3)
                    {
                        // Checando embaixo
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i + 2][j], tabuleiroJogo);
                        movValido = moverDirecao('T', tipoPeca, tabuleiroJogo[i + 2][j], tabuleiroAux);
                        if (movValido)
                        {
                            // printf("Estive aqui 8\n");
                            matrizRepetida = checaPaisIguais(auxiliarArvore, tabuleiroAux);
                            if (!matrizRepetida)
                            {
                                possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            }
                            possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                    }

                    if (j > 0)
                    {
                        // Checando esquerda
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i][j - 1], tabuleiroJogo);
                        movValido = moverDirecao('D', tipoPeca, tabuleiroJogo[i][j - 1], tabuleiroAux);
                        if (movValido)
                        {
                            // printf("Estive aqui 9\n");
                            matrizRepetida = checaPaisIguais(auxiliarArvore, tabuleiroAux);
                            if (!matrizRepetida)
                            {
                                possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            }
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                        if (tabuleiroJogo[i][j - 1] != tabuleiroJogo[i + 1][j - 1])
                        {
                            tipoPeca = checarTipoPeca(tabuleiroJogo[i + 1][j - 1], tabuleiroJogo);
                            movValido = moverDirecao('D', tipoPeca, tabuleiroJogo[i + 1][j - 1], tabuleiroAux);

                            if (movValido)
                            {
                                // printf("Estive aqui 10\n");
                                matrizRepetida = checaPaisIguais(auxiliarArvore, tabuleiroAux);
                                if (!matrizRepetida)
                                {
                                    possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                                }
                                copiarMatriz(tabuleiroJogo, tabuleiroAux);
                            }
                        }
                    }

                    int n = (configTabuleiro == 1 ? 3 : 5);

                    if (j < n)
                    {
                        // Checando direita
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i][j + 1], tabuleiroJogo);
                        movValido = moverDirecao('E', tipoPeca, tabuleiroJogo[i][j + 1], tabuleiroAux);
                        if (movValido)
                        {
                            // printf("Estive aqui 11\n");
                            matrizRepetida = checaPaisIguais(auxiliarArvore, tabuleiroAux);
                            if (!matrizRepetida)
                            {
                                possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            }
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                        if (tabuleiroJogo[i][j + 1] != tabuleiroJogo[i + 1][j + 1])
                        {
                            tipoPeca = checarTipoPeca(tabuleiroJogo[i + 1][j + 1], tabuleiroJogo);
                            movValido = moverDirecao('E', tipoPeca, tabuleiroJogo[i + 1][j + 1], tabuleiroAux);
                            if (movValido)
                            {
                                // printf("Estive aqui 12\n");
                                matrizRepetida = checaPaisIguais(auxiliarArvore, tabuleiroAux);
                                if (!matrizRepetida)
                                {
                                    possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                                }
                                copiarMatriz(tabuleiroJogo, tabuleiroAux);
                            }
                        }
                    }
                    return possiveisJogadas;
                }
                else
                {
                    if (i > 0)
                    {
                        // Checando em cima
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i - 1][j], tabuleiroJogo);
                        movValido = moverDirecao('B', tipoPeca, tabuleiroJogo[i - 1][j], tabuleiroAux);
                        if (movValido)
                        {
                            // printf("Estive aqui 13\n");
                            matrizRepetida = checaPaisIguais(auxiliarArvore, tabuleiroAux);
                            if (!matrizRepetida)
                            {
                                possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            }
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                    }

                    if (i < 4)
                    {
                        // Checando embaixo
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i + 1][j], tabuleiroJogo);
                        movValido = moverDirecao('T', tipoPeca, tabuleiroJogo[i + 1][j], tabuleiroAux);
                        if (movValido)
                        {
                            // printf("Estive aqui 14\n");
                            matrizRepetida = checaPaisIguais(auxiliarArvore, tabuleiroAux);
                            if (!matrizRepetida)
                            {
                                possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            }
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                    }

                    if (j > 0)
                    {
                        // Checando esquerda
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i][j - 1], tabuleiroJogo);
                        movValido = moverDirecao('D', tipoPeca, tabuleiroJogo[i][j - 1], tabuleiroAux);
                        if (movValido)
                        {
                            // printf("Estive aqui 15\n");
                            matrizRepetida = checaPaisIguais(auxiliarArvore, tabuleiroAux);
                            if (!matrizRepetida)
                            {
                                possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            }
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                    }

                    int n = (configTabuleiro == 1 ? 3 : 5);

                    if (j < n)
                    {
                        // Checando direita
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i][j + 1], tabuleiroJogo);
                        movValido = moverDirecao('E', tipoPeca, tabuleiroJogo[i][j + 1], tabuleiroAux);
                        if (movValido)
                        {
                            // printf("Estive aqui 16\n");
                            matrizRepetida = checaPaisIguais(auxiliarArvore, tabuleiroAux);
                            if (!matrizRepetida)
                            {
                                possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            }
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                    }
                }
            }
        }
    }
    return possiveisJogadas;
}

int verificaFim(int configTabuleiro, char tabuleiro[5][TAM_MAX_COL])
{
    printf("\nVERIFICA FIM????\n");
    printarTabuleiro(1, tabuleiro);
    if (configTabuleiro == 1)
    {
        if (tabuleiro[4][1] == 'D' && tabuleiro[4][2] == 'D')
        {
            return 1;
        }
    }
    else if (configTabuleiro == 2 && tabuleiro[4][5] == 'D')
    {
        return 1;
    }
    return 0;
}

void imprimeTudin(NodeTree *no)
{
    printf("\nIMPRIMETUDIN\n");
    NodeTree *auxiliar = no;
    while ((auxiliar->pai) != NULL)
    {
        printarTabuleiro(auxiliar->pai->numTabuleiro, auxiliar->pai->fotoTabuleiroAtual);
    }
}

int recursividade(NodeTree *arvore, char tabuleiroJogo[5][TAM_MAX_COL])
{
    int fim = verificaFim(1, tabuleiroJogo);

    if (fim)
    {
        imprimeTudin(arvore);
        return 1;
    }

    NodeTree *aux = criarNodeTree();
    aux = arvore;
    Node *sugestoes = NULL;

    printf("\nRECURSIVIDADE\n");

    sugestoes = encontrarProxsJogadas(1, tabuleiroJogo, sugestoes, arvore); // pega as sugestoes

    // copiarMatriz(sugestoes->fotoTabuleiroAtual, tabuleiroJogo);
    // chamar a arvore
    aux = inserirNodeTreeFilho(aux, 1, tabuleiroJogo, sugestoes);
    // chamar a rec
    printf("\n1, aux->f1->fotoTabuleiroAtual\n");
    printarTabuleiro(1, aux->f1->fotoTabuleiroAtual);
    fim = recursividade(aux->f1, aux->f1->fotoTabuleiroAtual);
    if (fim)
    {
        imprimeTudin(aux);
        return 1;
    }
    else
    {
        fim = recursividade(aux->f2, aux->f2->fotoTabuleiroAtual);
        if (fim)
        {
            imprimeTudin(aux);
            return 1;
        }
        else
        {
            fim = recursividade(aux->f3, aux->f3->fotoTabuleiroAtual);
            if (fim)
            {
                imprimeTudin(aux);
                return 1;
            }
            else
            {
                fim = recursividade(aux->f4, aux->f4->fotoTabuleiroAtual);
                if (fim)
                {
                    imprimeTudin(aux);
                    return 1;
                }
                else
                {
                    fim = recursividade(aux->f5, aux->f5->fotoTabuleiroAtual);
                    if (fim)
                    {
                        imprimeTudin(aux);
                        return 1;
                    }
                    else
                    {
                        fim = recursividade(aux->f6, aux->f6->fotoTabuleiroAtual);
                        if (fim)
                        {
                            imprimeTudin(aux);
                            return 1;
                        }
                        else
                        {
                            fim = recursividade(aux->f7, aux->f7->fotoTabuleiroAtual);
                            if (fim)
                            {
                                imprimeTudin(aux);
                                return 1;
                            }
                            else
                            {
                                fim = recursividade(aux->f8, aux->f8->fotoTabuleiroAtual);
                                if (fim)
                                {
                                    imprimeTudin(aux);
                                    return 1;
                                }
                                else
                                {
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int main()
{
    char tabuleiro1[5][TAM_MAX_COL] = {
    {'a', 'D', 'D', 'b', '\0', '\0', '\0'},
    {'a', 'D', 'D', 'b', '\0', '\0', '\0'},
    {'c', 'd', 'd', 'e', '\0', '\0', '\0'},
    {'c', 'g', 'h', 'e', '\0', '\0', '\0'},
    {'f', ' ', ' ', 'i', '\0', '\0', '\0'}};

    NodeTree* arvore = NULL;

    recursividade(arvore, tabuleiro1);

    return 0;
}