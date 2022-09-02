#include <stdio.h>

#define TAM_MAX_COL 7
#define MAX_INPUT_USER 10 

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

void printarTabuleiro(int num)
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

void moverDireita(char tipo, char letra)
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
                    return;
                } else if (tipo == 'D') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                
                if (tipo == 'B' && tabuleiroJogo[i][j + 2] == ' ' && tabuleiroJogo[i + 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i][j + 2] = letra;
                    tabuleiroJogo[i + 1][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return;
                } else if (tipo == 'B') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (tipo == 'P' && tabuleiroJogo[i][j + 1] == ' ' && tabuleiroJogo[i + 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i][j + 1] = letra;
                    tabuleiroJogo[i + 1][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return;
                } else if (tipo == 'P') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (tipo == 'Q' && tabuleiroJogo[i][j + 1] == ' ')
                {
                    tabuleiroJogo[i][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    return;
                } else if (tipo == 'Q') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (tipo == 'S' && tabuleiroJogo[i][j + 2] == ' ')
                {
                    tabuleiroJogo[i][j + 2] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    return;
                } else if (tipo == 'S') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (tipo == 'C' && tabuleiroJogo[i][j + 1] == ' ' && tabuleiroJogo[i + 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i][j + 1] = letra;
                    tabuleiroJogo[i + 1][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j - 1] = ' ';
                    return;
                } else {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
            }
        }
    }
}

void moverEsquerda(char tipo, char letra)
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
                    return;
                } else if (tipo == 'D') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                
                if (j > 0 && tipo == 'B' && tabuleiroJogo[i][j - 1] == ' ' && tabuleiroJogo[i + 1][j - 1] == ' ')
                {
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i + 1][j - 1] = letra;
                    tabuleiroJogo[i][j + 1] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return;
                } else if (tipo == 'B') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (j > 0 && tipo == 'P' && tabuleiroJogo[i][j - 1] == ' ' && tabuleiroJogo[i + 1][j - 1] == ' ')
                {
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i + 1][j - 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return;
                } else if (tipo == 'P') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (j > 0 && tipo == 'Q' && tabuleiroJogo[i][j - 1] == ' ')
                {
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    return;
                } else if (tipo == 'Q') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (j > 0 && tipo == 'S' && tabuleiroJogo[i][j - 1] == ' ')
                {
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i][j + 1] = ' ';
                    return;
                } else if (tipo == 'S') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (j > 0 && tipo == 'C' && tabuleiroJogo[i][j - 1] == ' ' && tabuleiroJogo[i + 1][j - 2] == ' ')
                {
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i + 1][j - 2] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return;
                } else {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
            }
        }
    }
}

void moverTopo(char tipo, char letra)
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
                    return;
                } else if (tipo == 'D') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                
                if (i > 0 && tipo == 'B' && tabuleiroJogo[i - 1][j] == ' ' && tabuleiroJogo[i - 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i - 1][j] = letra;
                    tabuleiroJogo[i - 1][j + 1] = letra;
                    tabuleiroJogo[i][j + 1] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return;
                } else if (tipo == 'B') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (i > 0 && tipo == 'P' && tabuleiroJogo[i - 1][j] == ' ')
                {
                    tabuleiroJogo[i - 1][j] = letra;
                    tabuleiroJogo[i + 1][j] = ' ';
                    return;
                } else if (tipo == 'P') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (i > 0 && tipo == 'Q' && tabuleiroJogo[i - 1][j] == ' ')
                {
                    tabuleiroJogo[i - 1][j] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    return;
                } else if (tipo == 'Q') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (i > 0 && tipo == 'S' && tabuleiroJogo[i - 1][j] == ' ' && tabuleiroJogo[i - 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i - 1][j] = letra;
                    tabuleiroJogo[i - 1][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i][j + 1] = ' ';
                    return;
                } else if (tipo == 'S') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (tipo == 'C' && tabuleiroJogo[i - 1][j] == ' ' && tabuleiroJogo[i][j - 1] == ' ')
                {
                    tabuleiroJogo[i - 1][j] = letra;
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i + 1][j] = ' ';
                    tabuleiroJogo[i + 1][j - 1] = ' ';
                    return;
                } else {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
            }
        }
    }
}

void moverBaixo(char tipo, char letra)
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
                    return;
                } else if (tipo == 'D') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                
                if (i < 5 && tipo == 'B' && tabuleiroJogo[i + 2][j] == ' ' && tabuleiroJogo[i + 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i + 2][j] = letra;
                    tabuleiroJogo[i + 1][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i][j + 1] = ' ';
                    return;
                } else if (tipo == 'B') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (i < 5 && tipo == 'P' && tabuleiroJogo[i + 2][j] == ' ')
                {
                    tabuleiroJogo[i + 2][j] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    return;
                } else if (tipo == 'P') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (i < 5 && tipo == 'Q' && tabuleiroJogo[i  + 1][j] == ' ')
                {
                    tabuleiroJogo[i + 1][j] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    return;
                } else if (tipo == 'Q') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (i < 5 && tipo == 'S' && tabuleiroJogo[i + 1][j] == ' ' && tabuleiroJogo[i + 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i + 1][j] = letra;
                    tabuleiroJogo[i + 1][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i][j + 1] = ' ';
                    return;
                } else if (tipo == 'S') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (tipo == 'C' && tabuleiroJogo[i + 2][j] == ' ' && tabuleiroJogo[i + 2][j - 1] == ' ')
                {
                    tabuleiroJogo[i + 2][j] = letra;
                    tabuleiroJogo[i + 2][j - 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j - 1] = ' ';
                    return;
                } else {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
            }
        }
    }
}

void moverDirecao(char direcao, char tipo, char letra)
{
    switch (direcao)
    {
    case 'D':
        moverDireita(tipo, letra);
        break;
    case 'E':
        moverEsquerda(tipo, letra);
        break;
    case 'T':
        moverTopo(tipo, letra);
        break;
    case 'B':
        moverBaixo(tipo, letra);
        break;
    default:
        printf("INTERNAL ERROR: DIRECAO INVALIDA");
        break;
    }
    
}

char encontrarLetra(int i, int j){
    return tabuleiroJogo[i-1][j-1];
}

char checarTipoPeca(char letra)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (tabuleiroJogo[i][j] == letra) {
                if (tabuleiroJogo[i][j + 1]  == letra)
                {
                    if(tabuleiroJogo[i + 1][j]  == letra) {
                        if (tabuleiroJogo[i + 1][j + 1]  == letra)
                        {
                           return 'D';
                        }
                        return 'B';                        
                    }
                    return 'S';
                } else if (tabuleiroJogo[i + 1][j]  == letra)
                {
                    if (j != 0 && tabuleiroJogo[i + 1][j - 1]  == letra)
                    {
                        return 'C';
                    }
                    
                    return 'P';
                } else return 'Q';                
            }
        }
    }
    printf("INTERNAL ERROR: TIPO INVALIDO");
    return 'e';
}


void banner(void) {

  printf("-----------------\n");
  printf("HAIKORI\n");
  printf("Por Larissa, Mirian e Yuri\n");
  printf("-----------------\n");
  printf("\n");

}

void help1(void) {

  printf("Modo de uso: ./tabuleiro [opcoes]\n");

  printf("\n========================= NOTAS =========================\n");
  printf("FASE 2 - Ler .txt, movimento iterativo de pecas e historico.\n");

  printf("\n======================== OPCOES ========================\n");
  printf(" -f <nome_arquivo.txt> : Especifica qual tabuleiro o jogo deve utilizar.\n");
  printf("                         Default: haikori.txt\n\n"); 
    
  printf("\n======================== EXEMPLOS =======================\n");
  printf(" ./tabuleiro\n");
  printf(" ./tabuleiro -f meuarquivo.txt\n");

}

void help2(void) {

  printf("\n======================== OPCOES ========================\n");
  printf(" l                   : Listar todas as opcoes numeradas dos tabuleiros.\n");
  printf(" c <config_tab>      : Especifica qual dos tabuleiros disponiveis o jogo deve utilizar.\n");
  printf("                       Se a configuracao for alterada no meio de um jogo, todo o progresso anterior sera perdido.\n\n");
  printf(" m <lin> <col> <dir> : Movimenta a peca que esta na posicao (lin,col) para a direcao dir.\n");
  printf("                       Direcoes: D - Direita | E - Esquerda | B - Baixo | T - Topo\n");
  printf(" p                   : Imprime o historico de movimentacoes desde a configuracao inicial.\n");

}

int interacoesUsuario(int argc, char argumento[], int configTabuleiro, int jaEscolheuTabuleiro){

    int i = 0;
    int j = 0;
    char direcao = '0';

    if (argc == 3 || argc > 4){
        printf("[!]1 Erro no numero de argumentos\n\n");
        help2();
        return 0;
    }

    if (argc == 1){

        if (argumento[0] == 'l'){
            return 5; // listar os tabuleiros disponiveis
            
        } else if (argumento[0] == 'p'){

            return 4; // mostrar o historico        
            
            } else {
                printf("[!]2 Erro: Argumento invalido\n\n");
                help2();
                return 0;
            }
    }

    if (argc == 2){
    
        if (argumento[0] == 'c') {

            if (argumento[2] == '1'){
                if (jaEscolheuTabuleiro){
                    printf("Tem certeza que quer trocar de tabuleiro? Todo o seu progresso será perdido");
                    char temCerteza[MAX_INPUT_USER];
                    scanf("%c", temCerteza);
                    if (temCerteza[0] == '1'){
                        return 2; // troca para o tabuleiro C2 e mostra o tabuleiro C2
                    } else {
                        return 0;
                    }
                } else {
                    return 1; // escolher tabuleiro c1 e mostra o tabuleiro c1
                }


            } else if (argumento[2] == '2'){

                if (jaEscolheuTabuleiro){
                    printf("Tem certeza que quer trocar de tabuleiro? Todo o seu progresso será perdido");
                    char temCerteza[MAX_INPUT_USER];
                    scanf("%c", temCerteza);
                    if (temCerteza[0] == '1'){
                        return 1; // troca para o tabuleiro C1 e mostra o tabuleiro C1
                    } else {
                        return 0;
                    }
                } else {
                    return 2; // escolher tabuleiro c2 e mostra o tabuleiro c2

                }
            } else {
                printf("[!]3 Erro: Configuração de tabuleiro inválida\n\n");
                help2();
                return 0;
            }
        } else {
            printf("[!]4 Erro: Argumento invalido\n\n");
            help2();
            return 0;
        }
    }

    if (argc == 4){

        if (argumento[0] == 'm'){
                
                direcao = argumento[6];

                if (direcao != 'D' && direcao != 'E' && direcao != 'T' && direcao != 'B'){
                    printf("[!]5 Erro: Direção inválida\n\n");
                    help2();
                    return 0;
                } 
                
                char i_ = argumento[2];
                char j_ = argumento[4];

                i = i_ - '0';
                j = j_ - '0';

                if (configTabuleiro == 1){
                    if (i >=1 && i <= 5 && j >= 1 && j <= 4){
                    
                    } else {
                        printf("[!] Erro6: Coordenadas inválidas\n\n");
                        help2();
                        return 0;
                    } 
                }
                
                if (configTabuleiro == 2){
                    if (i >= 1 && i <= 5 && j >= 1 && j <= 6) {
                    
                    } else {
                        printf("[!] Erro7: Coordenadas inválidas\n\n");
                        help2();
                        return 0;
                    }
                }
                return 3; // Movimento valido da peca
        } else {
            printf("[!] Erro8: Argumento inválido\n\n");
            help2();
            return 0;            
        }
    }
}

int main(int argc, char* argv[]){


    banner();

    int jaEscolheuTabuleiro = 0;
    int configTabuleiro = 1;
    int fim = 0;

    // ./tabuleiro -f meuarquivo.txt >>>>>> argc = 3
    // ./tabuleiro >>>> argc = 1

    if (argc == 1){
        // Ler arquivo haikori.txt e seguir;
    } else if (argc == 3){
        // Ler arquivo especificado e seguir;
    } else {
        printf("[!] Erro nos argumentos\n\n");
        help1();
        return 1;
    }

    while (!fim){

        char inputUsuario[MAX_INPUT_USER];
        printf("Digite o comando: ");
        fgets(inputUsuario, MAX_INPUT_USER, stdin);
    
        printf("%s\n", inputUsuario);

        if (inputUsuario[0] == 'q'){
            printf("\nTchau, obrigado por ter jogado!");
            fim = 1;
        } else {

            int len = sizeof(inputUsuario)/ sizeof(inputUsuario[0]);
            int len2 = 0;
            for(int i = 0; i != len; i++){
                if (inputUsuario[i] != '\0' && inputUsuario[i] != ' ' && inputUsuario[i] != '\n'){
                    ++len2;
                }
            }
            
            printf("O len eh: %d\n\n", len2);
            int resultado = interacoesUsuario(len2, inputUsuario, configTabuleiro, jaEscolheuTabuleiro);
            printf("%d\n\n", resultado);
        }

    }

    // configTabuleiro == 1 ? copiarMatriz(tabuleiro1) : copiarMatriz(tabuleiro2);
    // printarTabuleiro(configTabuleiro);

    // char letra = encontrarLetra(i,j);
    // char tipo = checarTipoPeca(letra);
    // moverDirecao(direcao, tipo, letra);
    // printf("\n");
    // printarTabuleiro(configTabuleiro);

    return 0;
}