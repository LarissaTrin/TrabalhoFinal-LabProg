# include <stdio.h>

# define MAX_INPUT_USER 20

int main(){

    int fim = 0;

    while (!fim){

        char inputUsuario[MAX_INPUT_USER];
        scanf("%s", inputUsuario);
        
        printf("%c\n", inputUsuario[1]);

        if (inputUsuario[0] == 'q'){
            printf("saiu");
            return 0;
        }
      

    }
    
    return 0;
}