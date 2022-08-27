#include <stdio.h>

static char tabuleiro1[5][4] = {
    {'a', 'D', 'D', 'b'},
    {'a', 'D', 'D', 'b'},
    {'c', 'd', 'd', 'e'},
    {'c', 'g', 'h', 'e'},
    {'f', ' ', ' ', 'i'}};

static char tabuleiro2[5][6] = {
    {'D', 'D', ' ', 'a', 'a', 'b'},
    {'D', 'D', ' ', 'a', 'c', 'd'},
    {'e', 'e', 'f', 'g', 'd', 'd'},
    {'h', 'h', 'i', 'j', 'k', 'l'},
    {'h', 'i', 'i', 'm', 'k', 'l'}};

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

void movimento()
{
}

void moverDireita(char tipo, char letra) // Funcional para tabuleiro 2
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (tabuleiro2[i][j] == letra)
            {
                if (tipo == 'D' && tabuleiro2[i][j + 2] == ' ' && tabuleiro2[i + 1][j + 2] == ' ')
                {
                    tabuleiro2[i][j + 2] = letra;
                    tabuleiro2[i + 1][j + 2] = letra;
                    tabuleiro2[i][j] = ' ';
                    tabuleiro2[i + 1][j] = ' ';
                    return;
                } else if (tipo == 'D') {
                    printf("\n Donzela - Nao e possivel mover peca\n");
                    return;
                }
                
                if (tipo == 'B' && tabuleiro2[i][j + 2] == ' ' && tabuleiro2[i + 1][j + 1] == ' ')
                {
                    tabuleiro2[i][j + 2] = letra;
                    tabuleiro2[i + 1][j + 1] = letra;
                    tabuleiro2[i][j] = ' ';
                    tabuleiro2[i + 1][j] = ' ';
                    return;
                } else if (tipo == 'B') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (tipo == 'P' && tabuleiro2[i][j + 1] == ' ' && tabuleiro2[i + 1][j + 1] == ' ')
                {
                    tabuleiro2[i][j + 1] = letra;
                    tabuleiro2[i + 1][j + 1] = letra;
                    tabuleiro2[i][j] = ' ';
                    tabuleiro2[i + 1][j] = ' ';
                    return;
                } else if (tipo == 'P') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (tipo == 'Q' && tabuleiro2[i][j + 1] == ' ')
                {
                    tabuleiro2[i][j + 1] = letra;
                    tabuleiro2[i][j] = ' ';
                    return;
                } else if (tipo == 'Q') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (tipo == 'S' && tabuleiro2[i][j + 2] == ' ')
                {
                    tabuleiro2[i][j + 2] = letra;
                    tabuleiro2[i][j] = ' ';
                    return;
                } else if (tipo == 'S') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (tipo == 'C' && tabuleiro2[i][j + 1] == ' ' && tabuleiro2[i + 1][j + 1] == ' ')
                {
                    tabuleiro2[i][j + 1] = letra;
                    tabuleiro2[i + 1][j + 1] = letra;
                    tabuleiro2[i][j] = ' ';
                    tabuleiro2[i + 1][j - 1] = ' ';
                    return;
                } else {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
            }
        }
    }
}

void moverTopo(char tipo, char letra) // Funcional para tabuleiro 2
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (tabuleiro2[i][j] == letra)
            {
                if (i > 0 && tipo == 'D' && tabuleiro2[i - 1][j] == ' ' && tabuleiro2[i - 1][j + 1] == ' ')
                {
                    tabuleiro2[i - 1][j] = letra;
                    tabuleiro2[i - 1][j + 1] = letra;
                    tabuleiro2[i + 1][j] = ' ';
                    tabuleiro2[i + 1][j + 1] = ' ';
                    return;
                } else if (tipo == 'D') {
                    printf("\n Donzela - Nao e possivel mover peca\n");
                    return;
                }
                
                if (i > 0 && tipo == 'B' && tabuleiro2[i - 1][j] == ' ' && tabuleiro2[i - 1][j + 1] == ' ')
                {
                    tabuleiro2[i - 1][j] = letra;
                    tabuleiro2[i - 1][j + 1] = letra;
                    tabuleiro2[i][j + 1] = ' ';
                    tabuleiro2[i + 1][j] = ' ';
                    return;
                } else if (tipo == 'B') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (i > 0 && tipo == 'P' && tabuleiro2[i - 1][j] == ' ')
                {
                    tabuleiro2[i - 1][j] = letra;
                    tabuleiro2[i + 1][j] = ' ';
                    return;
                } else if (tipo == 'P') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (i > 0 && tipo == 'Q' && tabuleiro2[i - 1][j] == ' ')
                {
                    tabuleiro2[i - 1][j] = letra;
                    tabuleiro2[i][j] = ' ';
                    return;
                } else if (tipo == 'Q') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (i > 0 && tipo == 'S' && tabuleiro2[i - 1][j] == ' ' && tabuleiro2[i - 1][j + 1] == ' ')
                {
                    tabuleiro2[i - 1][j] = letra;
                    tabuleiro2[i - 1][j + 1] = letra;
                    tabuleiro2[i][j] = ' ';
                    tabuleiro2[i][j + 1] = ' ';
                    return;
                } else if (tipo == 'S') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (tipo == 'C' && tabuleiro2[i - 1][j] == ' ' && tabuleiro2[i][j - 1] == ' ')
                {
                    tabuleiro2[i - 1][j] = letra;
                    tabuleiro2[i][j - 1] = letra;
                    tabuleiro2[i + 1][j] = ' ';
                    tabuleiro2[i + 1][j - 1] = ' ';
                    return;
                } else {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
            }
        }
    }
}

char encontraLetra(int x, int y){
    return 'z';
}

char checarTipoPeca(char letra) //Funcional - tabuleiro2
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


void banner(void) {

  printf("\n");
  printf("-----------------\n");
  printf("HAIKORI    \n");
  printf("Por Larissa, Mirian e Yuri\n");
  printf("-----------------\n");
  printf("\n");

}

void help(void) {

  printf("Modo de uso: ./tabuleiro [opções]\n");

  printf("\n========================= NOTAS =========================\n");
  printf("FASE 1 - Linha de comando e movimento de peças\n");


  printf("\n======================== OPÇÕES ========================\n");
  printf(" -c<config_tabuleiro> : Especifica qual tabuleiro o jogo deve utilizar.\n");
  printf("                        Configurações: 1 - Menor [default] | 2 - Maior\n");
  printf(" -m <x> <y> <direcao> : Movimenta a peça que está nas coordenadas (x,y) para a direção d.\n");
  printf("                        Direções: D - Direita | E - Esquerda | B - Baixo | T - Topo\n");
    
  printf("\n======================== EXEMPLOS =======================\n");
  printf(" ./tabuleiro\n");
  printf(" ./tabuleiro -c1\n");
  printf(" ./tabuleiro -c2\n");
  printf(" ./tabuleiro -c2 -m 1 1 D\n");
  printf(" ./tabuleiro -c2 -m 2 2 B\n");
  printf(" ./tabuleiro -m 2 2 T\n");


}

int main(int argc, char* argv[]){
    banner();

    int configTabuleiro = 1;
    int usuarioMovePecaTerminal = 0;
    int x = 0;
    int y = 0;
    char direcao = 0;

    if (argc == 1){
        criaTabuleiroUm();
        return 0;
    }

    if (argc > 2 && argc < 5){
        printf("[!] Erro nos argumentos\n\n");
        help();
        return 1;
    }

    if (argc > 6){
        printf("[!] Erro: Ultrapassou limite de argumentos\n\n");
        help();
        return 1;
    }

    if (argc == 2){
        char* argumento = argv[1];

        if (argumento[0] == '-' && argumento[1] == 'c'){

            if (argumento[2] == '1' || argumento[2] == '\0'){
                criaTabuleiroUm();
                return 0;

            } else if (argumento[2] == '2'){
                configTabuleiro = 2;
                criaTabuleiroDois();
                return 0;

            } else {
                printf("[!] Erro: Configuração de tabuleiro inválida\n\n");
                help();
                return 1;
            }
        } else if (argumento[0] == '-' && argumento[1] == 'm'){
            printf("[!] Erro: Opção -m exige coordenadas e direção\n\n");
            help();
            return 1;
            } else {
                printf("[!] Erro: Argumento inválido\n\n");
                help();
                return 1;
            }
        }

    if (argc == 5 || argc == 6){

        for (int i = 1; i <= 2; i++){
            char* argumento = argv[i];

            if (argumento[0] == '-' && argumento[1] == 'c') {

                if (argumento[2] == '1' || argumento[2] == '\0'){
                    configTabuleiro = 1;

                } else

                if (argumento[2] == '2'){
                    configTabuleiro = 2;

                } else {
                    printf("[!] Erro: Configuração de tabuleiro inválida\n\n");
                    help();
                    return 1;
                }
            } else 

            if (argumento[0] == '-' && argumento[1] == 'm'){
                direcao = argv[i+3][0];

                if (direcao != 'D' && direcao != 'E' && direcao != 'T' && direcao != 'B'){
                    printf("[!] Erro: Direção inválida\n\n");
                    help();
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
                        help();
                        return 1;
                    } 
                }
                
                if (configTabuleiro == 2){
                    if (x >= 1 && x <= 5 && y >= 1 && y <= 6) {
                    usuarioMovePecaTerminal = 1;
                    } else {
                        printf("[!] Erro2: Coordenadas inválidas\n\n");
                        help();
                        return 1;
                    }
                }
            }
        }

    printf("Testes linha de comando\n");
    printf("Tabuleiro escolhido: %d\n", configTabuleiro);
    if (usuarioMovePecaTerminal == 1){
        printf("Coordenadas escolhidas: %d, %d\n", x,y);
        printf("Direção escolhida: %c\n\n", direcao);
    }

    /* TO DO:

    - Função para encontrar letra a movimentar a partir das coordenadas passadas pela linha de comando
    - Montar as chamadas corretas para as funções a partir das informações coletadas na linha de comando

        letra = encontraLetra(x,y);
        criaTabuleiroGenerico(configTabuleiro);
        moverDirecao(direcao);

    */

    char letra = 'D';
    printf("%s", "Configuracao 2 \n\n");
    criaTabuleiroDois();
    char tipo = checarTipoPeca(letra);
    printf("\npeca movida - tipo: %c\n", tipo);
    moverTopo(tipo, letra);
    criaTabuleiroDois();

    return 0;
}
}