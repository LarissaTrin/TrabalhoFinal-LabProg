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
    printf("INTERNAL ERROR: MOVIMENTO DIREITA INVALIDO\n");
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
    printf("INTERNAL ERROR: MOVIMENTO ESQUERDA INVALIDO\n");
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
    printf("INTERNAL ERROR: MOVIMENTO TOPO INVALIDO\n");
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
    printf("INTERNAL ERROR: MOVIMENTO BAIXO INVALIDO\n");
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
    printf("INTERNAL ERROR: TIPO INVALIDO\n");
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

Node *inserirNodeNoFim(Node *listaEncadeada, int configTabuleiro, char tabuleiroJogo[5][TAM_MAX_COL])
{ // insere novo node no fim da lista encadeada (historico e lista de sugestoes)

    // printf("funcao: inserirNodeNoFim(Node *listaEncadeada, int configTabuleiro, char tabuleiroJogo[5][TAM_MAX_COL])\n");

    Node *novoNode = criarNode();
    copiarMatriz(tabuleiroJogo, novoNode->fotoTabuleiroAtual);
    novoNode->numTabuleiro = configTabuleiro;

    if (listaEncadeada == NULL)
    {
        listaEncadeada = novoNode;
        novoNode->proximo = NULL;
    }
    else
    {
        Node *auxiliar = listaEncadeada;

        while ((auxiliar->proximo) != NULL)
        {
            auxiliar = auxiliar->proximo;
        }

        auxiliar->proximo = novoNode;
        novoNode->proximo = NULL;
    }

    return listaEncadeada;
}

typedef struct nodeTree
{
    char fotoTabuleiroAtual[5][TAM_MAX_COL];
    int numTabuleiro;
    struct nodeTree *filhos[8];
    struct nodeTree *pai;
    struct nodeTree *irmao;
    int quantNivel;
} NodeTree;

NodeTree *inserirRaizTree(NodeTree *noAtual, char tabuleiro[5][TAM_MAX_COL], int numTab, NodeTree *ptPai, int nivel)
{
    // printf("\nInserir raiz\n");
    NodeTree *novoNode = (NodeTree *)malloc(sizeof(NodeTree));
    if (noAtual == NULL)
    {
        // é verdadeira penas a primeira vez para criar a raiz primaria
        copiarMatriz(tabuleiro, novoNode->fotoTabuleiroAtual);
        novoNode->numTabuleiro = numTab;
        novoNode->quantNivel = nivel;
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
    return novoNode;
}

NodeTree *inserirFilhoTree(NodeTree *noAtual, int numTab, Node *sugest[8])
{
    int i = 0;
    while (i < 8 && sugest[i] != NULL)
    {
        noAtual->filhos[i] = inserirRaizTree(noAtual->filhos[i], sugest[i]->fotoTabuleiroAtual, numTab, noAtual, 1);
        ++i;
    }
    return noAtual;
}

int verificaFim(int configTabuleiro, char tabuleiro[5][TAM_MAX_COL], int nivel)
{
    if (configTabuleiro == 1)
    {
        if (tabuleiro[4][1] == 'D' && tabuleiro[4][2] == 'D')
        {
            return 1;
        }

        printarTabuleiro(1, tabuleiro);
    }
    else if (configTabuleiro == 2)
    {
        if (tabuleiro[4][5] == 'D'){
            return 1;
        }

        printf("\nNivel: %d\n", nivel);
        printarTabuleiro(2, tabuleiro);

        if (tabuleiro[2][3] == 'D' && tabuleiro[3][3]){
            printf("D [2][3]&[3][3]\n");
        }

        if (tabuleiro[0][5] == 'D'){
            printf("D [0][5]\n");
        }

        if (tabuleiro[4][0] == 'D'){
            printf("D [4][0]\n");
        }

    }
    return 0;

    // if (configTabuleiro == 1)
    // {
    //     if (tabuleiro[4][1] == 'D' && tabuleiro[4][2] == 'D')
    //     {
    //         return 1;
    //     }
    // }
    // else if (configTabuleiro == 2 && tabuleiro[4][5] == 'D')
    // {
    //     return 1;
    // }
    // return 0;
}

void imprimirSolucao(NodeTree *raiz)
{
    if (raiz->filhos[0] == NULL)
    {
        printf("\nAcabou os filhos.\n");
        return;
    }
    else
    {
        printf("PAI:\n");
        printarTabuleiro(1, raiz->fotoTabuleiroAtual);
        printf("FILHOS DO NO ACIMA:\n");
        for (int i = 0; i < 8; i++)
        {
            printarTabuleiro(1, raiz->filhos[i]->fotoTabuleiroAtual);
        }
        raiz = raiz->filhos[0];
        imprimirSolucao(raiz);
    }
}

void imprimeSolucao(NodeTree *no)
{
    printf("\n[!] A solucao foi encontrada!\nApresentando passos para o resultado...\n\n");
    NodeTree *auxiliar = no;
    while ((auxiliar->pai) != NULL) // enquanto existirem pais na arvere, imprimir cada um
    {
        printarTabuleiro(auxiliar->numTabuleiro, auxiliar->fotoTabuleiroAtual);
        printf("\n");
        auxiliar = auxiliar->pai;
    }

    if ((auxiliar->pai) == NULL) // imprimir o ultimo no, o tabuleiro original
    {
        printarTabuleiro(auxiliar->numTabuleiro, auxiliar->fotoTabuleiroAtual);
    }

    // Vai imprimir de tras pra frente: a jogada final (donzela na porta) sera a primeira a ser impressa e ficara no topo.
    // Tabuleiro original sera o ultimo a ser impresso
    // Para imprimir na ordem inversa sera necessario fazer uma nova lista encadeada (historicoResolucao).
}

int compararTabuleiros(int num, char tabuleiro1[5][TAM_MAX_COL], char tabuleiro2[5][TAM_MAX_COL])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < TAM_MAX_COL; j++)
        {
            if (tabuleiro1[i][j] != tabuleiro2[i][j])
                return 0;
        }
    }
    return 1;
}

int checaPaisIguais(NodeTree *no, char candidatoSugestao[5][TAM_MAX_COL])
{
    NodeTree *auxiliar = no;
    // printarTabuleiro(1,auxiliar->fotoTabuleiroAtual);
    // printarTabuleiro(1,candidatoSugestao);

    while ((auxiliar->pai) != NULL)
    {
        if (compararTabuleiros(auxiliar->numTabuleiro, candidatoSugestao, auxiliar->fotoTabuleiroAtual) == 1)
        {
            // Candidato ja existe na arvore, cancela ele
            // printf("Existe pai igual\n");
            return 1;
        }
        auxiliar = auxiliar->pai;
    }
    if ((auxiliar->pai) == NULL)
    {
        if (compararTabuleiros(auxiliar->numTabuleiro, candidatoSugestao, auxiliar->fotoTabuleiroAtual) == 1)
        {
            // Candidato ja existe na arvore, cancela ele
            // printf("Existe pai igual\n");
            return 1;
        }
    }
    // printf("NAO existe pai igual\n");
    return 0; // Tudo certo com o candidato, nao existe nenhum pai igual
}

Node *encontrarProxsJogadas(int configTabuleiro, char tabuleiroJogo[5][TAM_MAX_COL], Node *sugestoes, NodeTree *noAtual) // Node* possiveisJogadas
{
    // printf("\nfuncao: encontrarProxsJogadas\n");

    Node *possiveisJogadas = sugestoes;

    NodeTree *auxiliarNoAtual = noAtual;
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
                        //if (tipoPeca == 'D' && movValido == 1) printf("Movi D Baixo\n");
                        if (movValido)
                        {
                            // printf("Estive 1\n");
                            matrizRepetida = checaPaisIguais(auxiliarNoAtual, tabuleiroAux);
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
                                // printf("Estive 2\n");
                                matrizRepetida = checaPaisIguais(auxiliarNoAtual, tabuleiroAux);
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
                        //if (tipoPeca == 'D' && movValido == 1) printf("Movi D Topo\n");
                        if (movValido)
                        {
                            // printf("Estive 3 \n");
                            matrizRepetida = checaPaisIguais(auxiliarNoAtual, tabuleiroAux);
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
                                // printf("Estive 4 \n");
                                matrizRepetida = checaPaisIguais(auxiliarNoAtual, tabuleiroAux);
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
                            // printf("Estive 5\n");
                            matrizRepetida = checaPaisIguais(auxiliarNoAtual, tabuleiroAux);
                            if (!matrizRepetida)
                            {
                                possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            }
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                    }

                    int n = (configTabuleiro == 1 ? 3 : 4);
                    if (j < n)
                    {
                        // Checando direita
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i][j + 2], tabuleiroJogo);
                        movValido = moverDirecao('E', tipoPeca, tabuleiroJogo[i][j + 2], tabuleiroAux);
                        if (movValido)
                        {
                            // printf("Estive 6\n");
                            matrizRepetida = checaPaisIguais(auxiliarNoAtual, tabuleiroAux);
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
                            // printf("Estive 7\n");
                            matrizRepetida = checaPaisIguais(auxiliarNoAtual, tabuleiroAux);
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
                            // printf("Estive 8\n");
                            matrizRepetida = checaPaisIguais(auxiliarNoAtual, tabuleiroAux);
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
                        //if (tipoPeca == 'D' && movValido == 1) printf("Movi D Dir\n");
                        if (movValido)
                        {
                            // printf("Estive 9\n");
                            matrizRepetida = checaPaisIguais(auxiliarNoAtual, tabuleiroAux);
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
                                // printf("Estive 10\n");
                                matrizRepetida = checaPaisIguais(auxiliarNoAtual, tabuleiroAux);
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
                        //if (tipoPeca == 'D' && movValido == 1) printf("Movi D Esq\n");
                        if (movValido)
                        {
                            // printf("Estive 11\n");
                            matrizRepetida = checaPaisIguais(auxiliarNoAtual, tabuleiroAux);
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
                                // printf("Estive 12\n");
                                matrizRepetida = checaPaisIguais(auxiliarNoAtual, tabuleiroAux);
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
                            // printf("Estive 13\n");
                            matrizRepetida = checaPaisIguais(auxiliarNoAtual, tabuleiroAux);
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
                            // printf("Estive 14\n");
                            matrizRepetida = checaPaisIguais(auxiliarNoAtual, tabuleiroAux);
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
                            // printf("Estive 15\n");
                            matrizRepetida = checaPaisIguais(auxiliarNoAtual, tabuleiroAux);
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
                            // printf("Estive 16\n");
                            matrizRepetida = checaPaisIguais(auxiliarNoAtual, tabuleiroAux);
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

int recNova(NodeTree *noAtual, Node *sugestoes, int nivel)
{
    int fim = verificaFim(noAtual->numTabuleiro, noAtual->fotoTabuleiroAtual, noAtual->quantNivel);
    if (fim == 1)
    {
        printf("\nACHEI A RESPOSTA AMIGOS\n");
        imprimeSolucao(noAtual);
        return 1;
    }

    //NodeTree *aux = noAtual;
    // aux = inserirFilhoTree(aux, 1, sugestoes);

    //printf("Paizão: \n");
    //printarTabuleiro(noAtual->numTabuleiro, noAtual->fotoTabuleiroAtual);
    int i = 0;

    while (i < 8 && sugestoes != NULL)
    {
        noAtual->filhos[i] = inserirRaizTree(noAtual->filhos[i], sugestoes->fotoTabuleiroAtual, noAtual->numTabuleiro, noAtual, nivel);
        
        //printf("Quem é meu Pai: \n");
        //printarTabuleiro(noAtual->numTabuleiro, noAtual->fotoTabuleiroAtual);
        //printf("Analisando o filho numero #%d\n", i);
        //printarTabuleiro(noAtual->filhos[i]->numTabuleiro, noAtual->filhos[i]->fotoTabuleiroAtual);
        //printf("---------\n");

        Node *novaSugestao = NULL;
        novaSugestao = encontrarProxsJogadas(noAtual->numTabuleiro, noAtual->filhos[i]->fotoTabuleiroAtual, novaSugestao, noAtual);

        fim = recNova(noAtual->filhos[i], novaSugestao, nivel+1);
        if (fim == 1)
            return fim;

        sugestoes = sugestoes->proximo;
        ++i;
    }

    //free(noAtual);
    //printf("matei o no\n");

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

    char tabuleiro2[5][TAM_MAX_COL] = {
        {'D', 'D', ' ', 'a', 'a', 'b', '\0'},
        {'D', 'D', ' ', 'a', 'c', 'd', '\0'},
        {'e', 'e', 'f', 'g', 'd', 'd', '\0'},
        {'h', 'h', 'i', 'j', 'k', 'l', '\0'},
        {'h', 'i', 'i', 'm', 'k', 'l', '\0'}};

    
    int numTab = 2;
    NodeTree *noAtual = NULL;
    noAtual = inserirRaizTree(noAtual, tabuleiro2, numTab, NULL, 0);

    //NodeTree *aux = noAtual;

    Node *sugestoes = NULL;
    sugestoes = encontrarProxsJogadas(numTab, noAtual->fotoTabuleiroAtual, sugestoes, noAtual);

    // int niveis = 5;

    int final = recNova(noAtual, sugestoes, 1);

    // imprimir(noAtual);
    printf("\nACHEI: %d", final);

    return 0;
}