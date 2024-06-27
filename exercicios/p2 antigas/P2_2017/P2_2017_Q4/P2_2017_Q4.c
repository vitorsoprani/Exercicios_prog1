#include <stdio.h>

int EhLetra(char c);
int TransformaMaiuscula(char c);
int EhVogal(char c);
int ReconheceSimbolo(char c);

int main() {
    return 0;
}

int EhLetra(char c) {
    return c <= 'Z' && c >= 'A' || c <= 'z' && c >= 'a';
}

int TransformaMaiuscula(char c) {
    if (c > 'z') return c;
    else return c + (int) 'a' - (int) 'A';
}

int EhVogal(char c) {
    TransformaMaiuscula(c);

    return c == 'A' ||
            c == 'E' ||
            c == 'I' ||
            c == 'O' ||
            c == 'U';
}

int ReconheceSimbolo(char c) {
    
}
