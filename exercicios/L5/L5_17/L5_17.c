#include <stdio.h>
#define VALORMAX 500

int LeTexto(int l, int c, char texto[l][c]);
void ImprimeTextoInvertido(int qtdPal, int l, int c, char texto[l][c]);

int main() {
    char texto[VALORMAX][VALORMAX];
    int qtdPalavras;

    qtdPalavras = LeTexto(VALORMAX, VALORMAX, texto);

    ImprimeTextoInvertido(qtdPalavras, VALORMAX, VALORMAX, texto);

    return 0;
}

int LeTexto(int linhas, int colunas, char texto[linhas][colunas]) {
    int i = 0;
    while (scanf("%[a-zA-Z]", texto[i]) == 1) {
        i++;
        scanf("%*[^a-zA-Z]");
    }
    return i;
}

void ImprimeTextoInvertido(int qtdPal, int l, int c, char texto[l][c]) {
    int i;

    for (i = qtdPal; i >= 0; i--) {
        printf("%s", texto[i]);
        printf(" ");
    }
}
