#include <stdio.h>

int EhMaiusculo(char c);
int EhLetra(char c);
int EhDigito(char c);
int EhVogal(char c);
int TransformaMaiusculo(char c);

int main() {
    char c1, c2, c3, c4, codigoValido = 1;
    scanf("%c%c%c%c", &c1, &c2, &c3, &c4);

    if (!EhMaiusculo(c1)) codigoValido = 0;
    if (!EhDigito(c2)) codigoValido = 0;
    if (!EhVogal(c3)) codigoValido = 0;
    if (EhVogal(c4) || EhMaiusculo(c4) || !EhLetra(c4)) codigoValido = 0;

    if (codigoValido) {
        printf("%c%c%c%c", c1, c2, TransformaMaiusculo(c3), TransformaMaiusculo(c4));
    } else {
        printf("Invalido");
    }
    return 0;
}

int EhLetra(char c) {
    return EhMaiusculo(c) || c <= 'z' && c >= 'a';
}

int EhMaiusculo(char c) {
    return c >= 'A' && c <= 'Z';
}

int EhDigito(char c) {
    return c >= '0' && c <= '9';
}

int EhVogal(char c) {
    if (!EhLetra(c)) return 0;
    c = TransformaMaiusculo(c);
    return c == 'A'
            || c == 'E'
            || c == 'I'
            || c == 'O'
            || c == 'U';
}

int TransformaMaiusculo(char c) {
    if (EhMaiusculo(c)) {
        return c;
    } else {
        c += (int) 'A' - (int) 'a';
        return c;
    }
}