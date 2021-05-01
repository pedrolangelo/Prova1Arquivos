#include <stdio.h>
#include <string.h>


int main(int argc, char**argv) {
    char arquivo [200], c;
    int palavras=1, linhas=1;
 
    sprintf(arquivo,"%s.dat",argv[1]);
    FILE *f = fopen (&arquivo, "r");
    
        if (f == NULL) {
            printf ("\nArquivo não encontrado");
            return 1;
        }

    c = fgetc(f);
    
        while (c != EOF){
            printf("%c", c);
                if (c == ' ' || c == '\n') palavras++;
                if (c == '\n') linhas++;
            c = fgetc (f);
        }

    printf("\n Quantidade de palavras do arquivo: %d", palavras);
    printf("\n Quantidade de linhas do arquivo: %d", linhas);
    close(f);
}