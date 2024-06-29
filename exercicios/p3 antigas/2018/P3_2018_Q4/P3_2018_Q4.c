#include <stdio.h>
#include <string.h>

#define TAM_MAX_PALAVRA     200
#define QTD_MAX_PALAVRAS    50

int TamanhoPalavra(char palavra[]);

int main() {
    char palavra1[TAM_MAX_PALAVRA];
    char palavra2[TAM_MAX_PALAVRA];
    //char listaResultante[QTD_MAX_PALAVRAS];
    int tamMaiorPalavra = 0;
    char maiorPalavra[TAM_MAX_PALAVRA] = "--";

    while (scanf("%s %s", palavra1, palavra2) == 2) {
        if (TamanhoPalavra(palavra1) > TamanhoPalavra(palavra2)) {
            //printf("p1");
            printf("%s\n", palavra1);
            if (TamanhoPalavra(palavra1) > tamMaiorPalavra) {
                tamMaiorPalavra = TamanhoPalavra(palavra1);
                strcpy(maiorPalavra, palavra1);
            }   
        } else if (TamanhoPalavra(palavra2) > TamanhoPalavra(palavra1)) {
            printf("%s\n", palavra2);
            //printf("p2");
            if (TamanhoPalavra(palavra2) > tamMaiorPalavra) {
                tamMaiorPalavra = TamanhoPalavra(palavra2);
                strcpy(maiorPalavra, palavra2);
            }
        }
    }
    
    printf("MAX:%s\n", maiorPalavra);

    return 0;
}

int TamanhoPalavra(char palavra[]) {
    int i;
    for (i = 0; 1; i++) {
        if (palavra[i] == 0) return i;
    }
}