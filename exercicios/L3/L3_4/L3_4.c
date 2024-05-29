#include <stdio.h>

int EhPrimo(int num);
int EhDivisorDe(int num1, int num2);
void ImprimeMultiplos(int num, int max);

int main() {
    int n, m, i;

    scanf("%d %d", &n, &m);

    for (i = (n + 1); i < m; i++) {
        if (EhPrimo(i)) {
            printf("%d\n", i);
            ImprimeMultiplos(i, m);
        }
    }
    return 0;
}

int EhPrimo(int num) {
    int divisores = 0, i = 0;

    for (i = 2; i <= num; i++) {
        if (EhDivisorDe(i, num)) {
            divisores++;

            if (divisores > 1) {
                return 0;
            }
        }
    }
    return 1;
}

int EhDivisorDe(int num1, int num2) {
    return (!(num2 % num1));
}

void ImprimeMultiplos(int num, int max) {
    char temMultiplos = 0;
    int i;

    for (i = 2;; i++) {
        int multiplo = num*i;
        if (multiplo < max) {
            printf("%d ", multiplo);
            temMultiplos = 1;
        } else {
            break;
        }
    }
    if (!temMultiplos) {
        printf("*");
    }
    printf("\n");
}