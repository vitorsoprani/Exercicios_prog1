#include <stdio.h>

int EhPar(int n);

int main() {
    int soma = 0, pos, qtdNumeros;
    scanf("%d", &qtdNumeros);

    for (pos = 0; pos < qtdNumeros; pos++) {
        int numeroAtual;
        scanf("%d", &numeroAtual);

        if (EhPar(numeroAtual)) {
            if (EhPar(pos)) soma += numeroAtual;
        } else {
            if (!EhPar(pos)) soma += numeroAtual;
        }
    }

    printf("SOMA:%d", soma);
    return 0;
}

int EhPar(int n) {
    return !(n % 2);
}
