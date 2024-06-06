#include <stdio.h>
#include <stdlib.h>
#define TAMANHOMAX 50

int main(int argc, char* argv[]) {
    char caminho[TAMANHOMAX], nome[TAMANHOMAX], curso[TAMANHOMAX];
    int idade;
    FILE* arquivo;

    sprintf(caminho, "%s", argv[1]);

    arquivo = fopen(caminho, "r");

    if (!arquivo) {
        printf("[ERRO] -Arquivo não encontrado");
        exit(1);
    }

    while (!feof(arquivo)) {
        fscanf(arquivo, "%49[^;];%d;%49[^\n]\n", nome, &idade, curso);
        printf("-> %s tem %d anos e cursa %s\n\n", nome, idade, curso);
    }

    fclose(arquivo);

    return 0;
}