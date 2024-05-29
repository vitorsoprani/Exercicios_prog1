#include <stdio.h>

int EhIgual(int a, int b);
int MaiorDigito(int num);

int main() {
    int numA, numB, count = 0;

    while (scanf("(%d,%d)", &numA, &numB) == 2) {
        if (EhIgual(MaiorDigito(numA), MaiorDigito(numB))) count++;
    }

    printf("COUNT:%d", count);
    return 0;
}

int EhIgual(int a, int b) {
    return a == b;
}

int MaiorDigito(int num) {
    int maiorDigito = 0;

    while (num) {
        int digito = num % 10;
        num /= 10;
        if (digito > maiorDigito) maiorDigito = digito;
    }

    return maiorDigito;
}
