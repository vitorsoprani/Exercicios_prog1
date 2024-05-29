#include <stdio.h>

int main(){
    int qntNumeros = 0, qntPares = 0, qntImpares = 0, cont = 0;
    int numeroAtual = 0, menorNumero = 0, maiorNumero = 0, soma = 0;

    scanf("%d", &qntNumeros);

    for (cont = 1; cont <= qntNumeros; cont++){
        scanf("%d", &numeroAtual);

        if (cont == 1){
            menorNumero = numeroAtual;
        }

        if (numeroAtual < menorNumero){
            menorNumero = numeroAtual;
        } else if (numeroAtual > maiorNumero){
            maiorNumero = numeroAtual;
        }

        if (numeroAtual % 2){
            qntImpares++;
        } else {
            qntPares++;
        }

        soma += numeroAtual;
    }
    printf("%d %d %d %d %.6f", maiorNumero, menorNumero, qntPares, qntImpares, ((float)soma/qntNumeros));
    return 0;
}