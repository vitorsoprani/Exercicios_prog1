#include <stdio.h>

int CalculaValorPalavra();
int ValorLetra(char caracter);
int EhDivisorDe(int divisor, int dividendo);
int EhPrimo(int n);
int ProximoPrimo(int n);

int main() {
    int valor = CalculaValorPalavra();
    do {
        if (EhPrimo(valor)){
            printf("E primo\n");
        } else {
            valor = ProximoPrimo(valor);
            printf("Nao e primo %d\n", valor);
        }
        valor = CalculaValorPalavra();
    } while (valor);
    return 0;
}

int ProximoPrimo(int n) {
    int i;
    for (i = n + 1; !EhPrimo(i); i++);
    return i;
}

int EhPrimo(int n) {
    int i;
    for (i = 2; i <= n / 2; i++) {
        if (EhDivisorDe(i, n)) {
            return 0;
        }
    }
    return n > 1;
}

int EhDivisorDe(int divisor, int dividendo) {
    return !(dividendo % divisor);
}

int CalculaValorPalavra() {
    char caracter = 0;
    int valorPalavra = 0;
    while (scanf("%c", &caracter) == 1) {
        if (caracter == '\n') break;
        valorPalavra += ValorLetra(caracter);
    }
    return valorPalavra;
}

int ValorLetra(char caracter) {
    if (caracter >= 'a' && caracter <= 'z') {
        return (int) caracter - (int) 'a' + 1;
    } else if (caracter >= 'A' && caracter <= 'Z') {
        return (int) caracter - (int) 'A' + 27;
    } else {
        return 0;
    }
}