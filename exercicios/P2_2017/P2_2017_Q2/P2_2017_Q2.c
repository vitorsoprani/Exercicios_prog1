#include <stdio.h>

int EhIgual(int a, int b);
int InverteNumero(int num);
int EhPalindromo(int num);

int main() {
    int qtdPalindromos = 0, numeroAtual;

    while (scanf("%d", &numeroAtual) == 1) {
        if (EhPalindromo(numeroAtual)) {
            qtdPalindromos ++;
        }
    }
    printf("COUNT:%d", qtdPalindromos);
    return 0;
}

int EhIgual(int a, int b) {
    return a == b;
}

int InverteNumero(int num) {
    int numInvertido = 0;

    while (num) {
        numInvertido *= 10;
        numInvertido += num % 10;
        num /= 10;
    }

    return numInvertido;
}

int EhPalindromo(int num) {
    return EhIgual(num, InverteNumero(num));
}
