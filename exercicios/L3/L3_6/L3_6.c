#include <stdio.h>

int EhPalindromo(int num);
int InverteNumero(int num);

int main() {
    int numero = 0;

    while (scanf("%d", &numero) == 1) {
        EhPalindromo(numero) ? printf("S\n") : printf("N\n");
    }
    return 0;
}

int EhPalindromo(int num) {
    int numeroInvertido;
    numeroInvertido = InverteNumero(num);
    return num == numeroInvertido;
}

int InverteNumero(int num) {
    int invertido = 0;

    while (num) {
        invertido = invertido * 10;
        invertido += num % 10;
        num = num / 10;
    }
    return invertido;
}