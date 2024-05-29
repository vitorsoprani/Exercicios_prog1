#include <stdio.h>

int LeVetorERetornaDiferenca(int vet[], int tam);
void ImprimeVetor(int vet[], int tam);
int ValorAbsoluto(int x);
void ImprimePares(int vet[], int tam, int diferenca);

int main() {
    int qtdPostes;
    scanf("%d", &qtdPostes);
    if (qtdPostes <= 1) {
        printf("IMPOSSIVEL");
        return 0;
    }
    int alturas[qtdPostes], maiorDiferenca;

    maiorDiferenca = LeVetorERetornaDiferenca(alturas, qtdPostes);
    ImprimePares(alturas, qtdPostes, maiorDiferenca);

    return 0;
}

int LeVetorERetornaDiferenca(int vet[], int tam) {
    int i, maiorDiferenca = 0;

    scanf("%d", &vet[i]);

    for (i = 1; i < tam; i++) {
        scanf("%d", &vet[i]);
        int diferencaAtual = ValorAbsoluto(vet[i - 1] - vet[i]);
        if (diferencaAtual > maiorDiferenca) {
            maiorDiferenca = diferencaAtual;
        }
    }
    return maiorDiferenca;
}

void ImprimeVetor(int vet[], int tam) {
    int i;
    printf("[");
    for (i = 0; i < tam; i++) printf(" %d ", vet[i]);
    printf("]");
}

int ValorAbsoluto(int x) {
    if (x >= 0) return x;
    else return -x;
}

void ImprimePares(int vet[], int tam, int diferenca) {
    int i;

    for (i = 0; i < tam - 1; i++) {
        int diferencaAtual = ValorAbsoluto(vet[i] - vet[i + 1]);

        if (diferencaAtual == diferenca) {
            printf(" (%d %d)", i, i + 1);
        }
    }
}