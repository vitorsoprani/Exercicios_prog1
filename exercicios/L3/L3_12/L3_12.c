#include <stdio.h>

int EhDivisorDe(int divisor, int dividendo);
int SomaDosDigitos(int n);
void ParImpar(int n);
void ValorPrimo(int n);

int main() {
    int numero = 0;
    scanf("%d", &numero);

    do {
        numero = SomaDosDigitos(numero);
        ParImpar(numero);
        ValorPrimo(numero);
    } while (numero > 9);

    return 0;
}

int SomaDosDigitos(int n) {
    int soma = 0;
    while (n) {
        soma += n % 10;
        n = n / 10;
    }
    printf("%d ", soma);
    return soma;
}

int EhDivisorDe(int divisor, int dividendo) {
    return !(dividendo % divisor);
}

void ParImpar(int n) {
    if (n % 2) {
        printf("Impar ");
    } else {
        printf("Par ");
    }
}

void ValorPrimo(int n) {
    int divisores = 0, i;

    for (i = n; i > 1; i--) {
        if (EhDivisorDe(i, n)) {
            divisores++;
            if (divisores > 1) break;
        }
    }
    if (divisores == 1) printf("Primo\n");
    else printf("Nao e primo\n");
}