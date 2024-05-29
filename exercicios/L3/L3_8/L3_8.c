#include <stdio.h>
#define VALOR_MINIMO -32000
#define VALOR_MAXIMO 32000

int VerificaPrimo(int n);
int VerificaNegativo(int n);
int TransformaPrimo(int n);
int EhDivisorDe(int divisor, int dividendo);

int main() {
    int linhas, colunas, i, ii;
    scanf("%d %d", &linhas, &colunas);
    
    for (i = 1; i <= linhas; i++) {
        printf("\t");
        for (ii = 1; ii <= colunas; ii++) {
            int n;
            scanf("%d", &n);
            n = TransformaPrimo(n);
            printf("%d ", n);
        }
        printf("\n");
    }
    return 0;
}

int EhDivisorDe(int divisor, int dividendo) {
    return !(dividendo % divisor);
}

int VerificaPrimo(int n) {
    int divisores = 0, i, ii;

    if (VerificaNegativo(n)) {
        for (i = -1; i >= n; i--) {
            if (EhDivisorDe(i, n)) {
                divisores++;
                if (divisores > 2) break;
            }//if
        } //for
        return divisores == 2;

    } else {
        for (i = 1; i <= n; i++) {
            if (EhDivisorDe(i, n)) {
                divisores++;
                if (divisores > 2) break;
            }//if
        } //for
        return divisores == 2;
    }//else
}//VerificaPrimo

int VerificaNegativo(int n) {
    return n < 0;
}

int TransformaPrimo(int n) {
    int proximoPrimo = n;

    if (VerificaNegativo(n)) {
        while (!VerificaPrimo(proximoPrimo) && proximoPrimo > VALOR_MINIMO) {
            proximoPrimo--;
        }
    } else {
        while (!VerificaPrimo(proximoPrimo) && proximoPrimo < VALOR_MAXIMO) {
            proximoPrimo++;
        }
    }
    return VerificaPrimo(proximoPrimo) ? proximoPrimo : n;
}
