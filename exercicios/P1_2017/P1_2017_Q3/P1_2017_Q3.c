#include <stdio.h>

int ConverteParaMaiusculo(char c);
int EhLetraOuNumero(char c);

int main() {
    char c1, c2, c3, c4;
    scanf("%c%c %c%c", &c1, &c2, &c3, &c4);

    c1 = ConverteParaMaiusculo(c1);
    c2 = ConverteParaMaiusculo(c2);
    c3 = ConverteParaMaiusculo(c3);
    c4 = ConverteParaMaiusculo(c4);
    
    if (!EhLetraOuNumero(c1)) {
        printf("Invalido");
        return 0;
    }
    if (!EhLetraOuNumero(c2)) {
        printf("Invalido");
        return 0;
    }
    if (!EhLetraOuNumero(c3)) {
        printf("Invalido");
        return 0;
    }
    if (!EhLetraOuNumero(c4)) {
        printf("Invalido");
        return 0;
    }
    
    if (c1 == c3 && c2 == c4) printf("IGUAIS");
    else printf("DIFERENTES");
    
    return 0;
}

int ConverteParaMaiusculo(char c) {
    if (c >= 'a' && c <= 'z') {
        return c + ((int) 'A' - (int) 'a');
    } else {
        return c;
    }
}

int EhLetraOuNumero(char c) {
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z');
}