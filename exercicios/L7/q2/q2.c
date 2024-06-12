#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCAMINHO  50
#define MAXCODIGO   4 //3 caracteres do codigo + \0
#define CODPORLINHA 2

#define INVALIDO   -1
#define DIFERENTES  0
#define IGUAIS      1

int EhValidoCodigo(char codigos[MAXCODIGO]);
int ComparaCodigos(char codigos[CODPORLINHA][MAXCODIGO]);
int EhLetraOuNumero(char c);
char TransformaMinuscula(char c);

int main(int argc, char* argv[]) {
    char caminho[MAXCAMINHO], codigos[CODPORLINHA][MAXCODIGO];
    FILE* arquivoInput;
    FILE* arquivoOutput;

    sprintf(caminho, "%s", argv[1]);
    arquivoInput = fopen(caminho, "r");

    if (!arquivoInput) {
        printf("[ERRO] O arquivo indicado não pode ser aberto ou nao existe");
        exit(1);
    } else {
        printf("Abrindo o arquivo '%s'.", caminho);
    }

    sprintf(caminho, "%s", argv[2]);
    arquivoOutput = fopen(caminho, "w");

    while (!feof(arquivoInput)) {
        fscanf(arquivoInput, "%s %s\n", codigos[0], codigos[1]);
        switch (ComparaCodigos(codigos)) {
        case IGUAIS:
            fprintf(arquivoOutput, "IGUAIS\n");
            break;
        case DIFERENTES:
            fprintf(arquivoOutput, "DIFERENTES\n");
            break;
        case INVALIDO:
            fprintf(arquivoOutput, "INVALIDO\n");
            break;
        }
    }

    fclose(arquivoInput);
    fclose(arquivoOutput);

    return 0;
}

int EhValidoCodigo(char codigo[MAXCODIGO]) {
    int i;

    for (i = 0; i < MAXCODIGO; i++) {
        if (!EhLetraOuNumero(codigo[i])) return 0;
    }

    return 1;
}

int EhLetraOuNumero(char c) {
    return c > 'a' && c < 'z' || c > 'A' && c < 'Z' || c > '0' && c < '9';
}

int ComparaCodigos(char codigos[CODPORLINHA][MAXCODIGO]) {
    int i, j;

    //Transforma tudo em maiuscula
    for (i = 0; i < CODPORLINHA; i++) {
        for (j = 0; j < MAXCODIGO; j++) {
            codigos[i][j] = TransformaMinuscula(codigos[i][j]);
        }
    }

    if (!(EhValidoCodigo(codigos[0])) || !(EhValidoCodigo(codigos[1]))) {
        return INVALIDO;
    }

    return !strcmp(codigos[0], codigos[1]);
}

char TransformaMinuscula(char c) {

    if (c > 'a' && c < 'z') {
        return c + ((int)'A' - (int)'a');
    }

    return c;

}