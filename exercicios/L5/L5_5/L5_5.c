#include <stdio.h>

void LeVetor(int *vet, int tam);
int EncontraPrimeiraOcorrencia(int *vet, int tam, int num);

int main() {
    int numProcurado, qtdNumeros, primeiraOcorrencia;
    scanf("%d %d", &numProcurado, &qtdNumeros);
    int numeros[qtdNumeros];
    LeVetor(numeros, qtdNumeros);

    primeiraOcorrencia = EncontraPrimeiraOcorrencia(numeros, qtdNumeros, numProcurado);

    printf("RESP:%d", primeiraOcorrencia);
    return 0;
}

void LeVetor(int *vet, int tam) {
    int i;

    for (i = 0; i < tam; i++) {
        scanf("%d", &vet[i]);
    }
}

int EncontraPrimeiraOcorrencia(int *vet, int tam, int num) {
    int i;

    for (i = 0; i < tam; i++) {
        if (vet [i] == num) return i;
    }

    return i;
}