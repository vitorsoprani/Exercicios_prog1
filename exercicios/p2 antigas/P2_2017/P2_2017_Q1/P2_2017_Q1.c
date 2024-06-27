#include <stdio.h>

int main() {
    int qtdNumeros, i;
    int menorNumero, posMenorNumero = 1;

    scanf("%d", &qtdNumeros);

    if (qtdNumeros) {
        scanf("%d", &menorNumero);

        for (i = 2; i <= qtdNumeros; i++) {
            int numeroAtual;
            scanf("%d", &numeroAtual);

            if (numeroAtual < menorNumero) {
                menorNumero = numeroAtual;
                posMenorNumero = i;
            }
        }
        printf("POS:%d", posMenorNumero);
    }
    return 0;
}