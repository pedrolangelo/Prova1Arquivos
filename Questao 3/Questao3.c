#include <stdio.h>
#include <string.h>


typedef struct _Registro Registro;

struct _Registro {
    int id_inscricao;
    char curso[20];
    char cpf[15];
    char dataNacimento[11];
    char sexo;
    char email[40];
    char opcaoQuadro;
};

int main (int argc, char**argv){
    long tamanhoA, quantidadeA, tamanhoB, quantidadeB, c; 
    FILE *f = fopen ("candidatosA.dat", "r"), *arq = fopen ("candidatosB.dat", "r");
    Registro r, e;

    //Primeiro arquivo
    fseek (f, 0, SEEK_END);
    tamanhoA = ftell(f);
    quantidadeA = tamanhoA/sizeof(Registro);
    rewind(f);

    //Segundo arquivo
    fseek (arq, 0, SEEK_END);
    tamanhoB = ftell(arq);
    quantidadeB = tamanhoB/sizeof(Registro);
    rewind(arq);

        if (quantidadeA>quantidadeB) c = quantidadeB;
        else c = quantidadeA;

    for (int i = 0; i < c; i++){
        fread(&r, sizeof(Registro), 1, f);
        fread(&e, sizeof(Registro), 1, arq);
        
            if (strncmp(r.cpf,e.cpf,15)==0){
                printf("%.40s\n",r.email);
                fread(&r, sizeof(Registro), 1, f);
                fread(&e, sizeof(Registro), 1, arq); 
            }else if (strncmp(r.cpf,e.cpf,15)>0) fread(&r, sizeof(Registro), 1, f);
                  else fread(&e, sizeof(Registro), 1, arq);
    }
    fclose(f);
    fclose(arq);
}