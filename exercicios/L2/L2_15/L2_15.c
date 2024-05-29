#include <stdio.h>

int main() {
    int numeroAtual = 0, maiorNumero = 0, menorNumero = 0;
    int somaPositivos = 0, somaNegativos = 0, qntPositivos = 0, qntNegativos = 0;
    
    while (scanf("%d", &numeroAtual) == 1) {
        if (numeroAtual < 0) {
            qntNegativos++;
            somaNegativos += numeroAtual;
        } else if(numeroAtual > 0) {
            qntPositivos++;
            somaPositivos += numeroAtual;
        }
    }
    printf("%d ", qntNegativos);
    printf("%d ", qntPositivos);
    printf("%d ", somaNegativos);
    printf("%d", somaPositivos);
    return 0;
}
