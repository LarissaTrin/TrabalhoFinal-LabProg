#include <stdio.h>

#define TAM_MAX_COL 7
#define MAX_INPUT_USER 8 

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

char encontrarLetra(int x, int y){
    return tabuleiroJogo[x-1][y-1];
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
  
  printf("\n======================== EXEMPLOS =======================\n");
  printf(" c 1\n");
  printf(" c 2\n");
  printf(" p\n");
  printf(" m 1 1 D\n");
  printf(" m 2 3 B\n");

}

int interacoesUsuario(int argc, char* argv[]){

    int configTabuleiro = 1;
    int usuarioMovePecaTerminal = 0;
    int x = 0;
    int y = 0;
    int argCfoilido = 0;
    int argMfoilido = 0;
    char direcao = '0';

    if (argc == 1){
        configTabuleiro == 1 ? copiarMatriz(tabuleiro1) : copiarMatriz(tabuleiro2);
        printarTabuleiro(configTabuleiro);
        return 0;
    }

    if (argc > 2 && argc < 5){
        printf("[!] Erro nos argumentos\n\n");
        help2();
        return 1;
    }

    if (argc > 6){
        printf("[!] Erro: Ultrapassou limite de argumentos\n\n");
        help2();
        return 1;
    }

    if (argc == 2){
        char* argumento = argv[1];

        if (argumento[0] == '-' && argumento[1] == 'c'){

            if (argumento[2] == '1' || argumento[2] == '\0'){
                configTabuleiro == 1 ? copiarMatriz(tabuleiro1) : copiarMatriz(tabuleiro2);
                printarTabuleiro(configTabuleiro);
                return 0;

            } else if (argumento[2] == '2'){
                configTabuleiro = 2;
                configTabuleiro == 1 ? copiarMatriz(tabuleiro1) : copiarMatriz(tabuleiro2);
                printarTabuleiro(configTabuleiro);
                return 0;

            } else {
                printf("[!] Erro: Configuracao de tabuleiro inválida\n\n");
                help2();
                return 1;
            }
        } else if (argumento[0] == '-' && argumento[1] == 'm'){
            printf("[!] Erro: Opcao -m exige coordenadas e direcao\n\n");
            help2();
            return 1;
            } else {
                printf("[!] Erro: Argumento invalido\n\n");
                help2();
                return 1;
            }
    }

    if (argc == 5 || argc == 6){

        for (int i = 1; i <= 2; i++){
            char* argumento = argv[i];

            if (argumento[0] == '-' && argumento[1] == 'c') {

                if (argMfoilido == 1){
                    printf("[!] Erro: Ordem inválida de argumentos\n\n");
                    help2();
                    return 1;
                } else if (argCfoilido == 1){
                    printf("[!] Erro: Argumentos inválidos\n\n");
                    help2();
                    return 1;
                } else {
                    argCfoilido = 1;
                }

                if (argumento[2] == '1' || argumento[2] == '\0'){
                    configTabuleiro = 1;

                } else if (argumento[2] == '2'){
                    configTabuleiro = 2;

                } else {
                    printf("[!] Erro: Configuração de tabuleiro inválida\n\n");
                    help2();
                    return 1;
                }
            } else 

            if (argumento[0] == '-' && argumento[1] == 'm'){
                argMfoilido = 1;

                if (argc == 5 && argCfoilido == 1){
                    printf("[!] Erro: Argumentos inválidos\n\n");
                    help2();
                    return 1;
                }

                direcao = argv[i+3][0];

                if (direcao != 'D' && direcao != 'E' && direcao != 'T' && direcao != 'B'){
                    printf("[!] Erro: Direção inválida\n\n");
                    help2();
                    return 1;
                } 
                
                char x_ = argv[i+1][0];
                char y_ = argv[i+2][0];

                x = x_ - '0';
                y = y_ - '0';

                if (configTabuleiro == 1){
                    if (x >=1 && x <= 5 && y >= 1 && y <= 4){
                        usuarioMovePecaTerminal = 1;
                    } else {
                        printf("[!] Erro1: Coordenadas inválidas\n\n");
                        help2();
                        return 1;
                    } 
                }
                
                if (configTabuleiro == 2){
                    if (x >= 1 && x <= 5 && y >= 1 && y <= 6) {
                    usuarioMovePecaTerminal = 1;
                    } else {
                        printf("[!] Erro2: Coordenadas inválidas\n\n");
                        help2();
                        return 1;
                    }
                }
            }
        }
    }

    printf("Tabuleiro: %d\n", configTabuleiro);
    if (usuarioMovePecaTerminal == 1){
        printf("Coordenadas: %d, %d\n", x,y);
        printf("Direção do movimento: %c\n\n", direcao);
    }

}

int main(int argc, char* argv[]){

    banner();

    if (argc == 1){
        //beleza, ler arquivo haikori.txt e seguir lindamente;
        //return 0;
    } else if (argc == 3){
        //beleza, ler arquivo especificado e seguir lindamente;
        //return 0;
    } else {
        printf("[!] Erro nos argumentos\n\n");
        help1();
        return 1;
    }

    int fim = 0;

    while (!fim){

        char inputUsuario[MAX_INPUT_USER];
        scanf("%s", inputUsuario);      
        
        printf("%s\n", inputUsuario);

        //TO DO / NOTAS:

        // vetorTipoArgv = ["primeiroarg", "segundoarg"];

        // algo = interacoesUsuario(argcfalsificado, argvfalsificado);

        // if (algo == 1){
        //     printf("Operação inválida");
        //     continue;
        // }

        // Mais info no arquivo teste.c =)

        if (inputUsuario[0] == 'q'){
            printf("\nTchau, obrigado por ter jogado!");
            fim = 1;
        }

    }

    // configTabuleiro == 1 ? copiarMatriz(tabuleiro1) : copiarMatriz(tabuleiro2);
    // printarTabuleiro(configTabuleiro);

    // char letra = encontrarLetra(x,y);
    // char tipo = checarTipoPeca(letra);
    // moverDirecao(direcao, tipo, letra);
    // printf("\n");
    // printarTabuleiro(configTabuleiro);

    return 0;
}