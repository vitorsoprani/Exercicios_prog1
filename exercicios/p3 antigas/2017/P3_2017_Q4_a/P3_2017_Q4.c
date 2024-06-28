#include <stdio.h>

#define QTD_MAX_CARACTERES 200


int EhLetra(char c);

int EhVogal(char c);

int TransformaMaiuscula(char c);

int main() {
    char palavra[QTD_MAX_CARACTERES];

    while (scanf("%s", palavra) == 1) {
        int i = 0;
        int qtdVogais = 0, qtdConsoantes = 0;
        while (palavra[i]) {
            if (EhLetra(palavra[i])) {
                if (EhVogal(palavra[i])) {
                    qtdVogais++;
                } else {
                    qtdConsoantes++;
                }
            }
            i++;
        }
        if (qtdVogais == qtdConsoantes) {
            printf("%s", palavra);
        } else if(qtdVogais < qtdConsoantes) {
            i = 0;
            while (palavra[i]) {
                if (EhLetra(palavra[i]) && !EhVogal(palavra[i])) printf("%c", palavra[i]);
                i++;
            }
        } else {
            i = 0;
            while (palavra[i]) {
                if (EhVogal(palavra[i])) printf("%c", palavra[i]);
                i++;
            }
        }
        printf("\n");
    }
    
    return 0;
}

int EhLetra(char c) {
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

int EhVogal(char c) {
    c = TransformaMaiuscula(c);

    return c == 'A'
            || c == 'E'
            || c == 'I'
            || c == 'O'
            || c == 'U';

}

int TransformaMaiuscula(char c) {
    if ('A' <= c && c <= 'Z') return c;
    return (char) (int) c + (int) 'A' - (int) 'a';
}