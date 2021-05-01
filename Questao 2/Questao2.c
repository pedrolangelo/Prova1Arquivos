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
    long tamanho, quantidade; 
    FILE *f = fopen ("candidatos.dat", "r"), *arq = fopen ("candidatos2.dat", "w");
    Registro r, e;


    fseek (f, 0, SEEK_END);
    tamanho = ftell(f);
    quantidade = tamanho/sizeof(Registro);
    rewind(f);

    fread(&r, sizeof(Registro), 1, f);

    for (int i = 0; i < quantidade; i++){
        e = r;
        fread(&r, sizeof(Registro), 1, f);
             if (strncmp(r.cpf,e.cpf,15)==0){
                    if (e.id_inscricao>r.id_inscricao){
                        r=e;
                    }
                fwrite(&r, sizeof(Registro), 1, arq);
                fread(&r, sizeof(Registro), 1, f);
                i++;
            }else {
                fwrite(&e, sizeof(Registro), 1, arq);
            }
    }

    fclose(arq);
}