#include <stdio.h>

int main() {
    int numero = 0, menorNumero = 0, posicao = 0;
    int primeiraOcorrencia = -1, ultimaOcorrencia = -1;
    char primeiraLeitura = 1;

    while (1) {
        if (scanf("%d", &numero) == 0) {
            scanf("%*c");
            break;
        }
        if (primeiraLeitura) {
            menorNumero = numero;
            primeiraLeitura = 0;
        }
        if (numero < menorNumero) {
            menorNumero = numero;
        }
    }

    primeiraLeitura = 1;

    while (1) {
        if (scanf("%d", &numero) == 0) {
            break;
        }
        if (menorNumero == numero) {
            if (primeiraLeitura) {
                primeiraOcorrencia = posicao;
                primeiraLeitura = 0;
            }
            if (ultimaOcorrencia < posicao) {
                ultimaOcorrencia = posicao;
            }
        }

        posicao++;
    }

    if (primeiraOcorrencia == -1 && ultimaOcorrencia == -1) {
        primeiraOcorrencia = posicao;
        ultimaOcorrencia = posicao;
    }

    printf("%d ", menorNumero);
    printf("%d ", primeiraOcorrencia);
    printf("%d", ultimaOcorrencia);
    return 0;
}