#include <stdio.h>

void LeVetor(int *vet, int tam);
int EhPA(int *vet, int tam);

int main() {
    int n;
    scanf("%d", &n);
    int sequencia[n];
    LeVetor(sequencia, n);

    if (!EhPA(sequencia, n)) printf("NAO");

    return 0;
}

void LeVetor(int *vet, int tam) {
    int i;

    for (i = 0; i < tam; i++) {
        scanf("%d", &vet[i]);
    }
}

int EhPA(int *vet, int tam) {
    int razao, i;
    if (tam <= 1) return 0;
    razao = vet[1] - vet[0];

    for (i = 1; i < tam - 1; i++) {
        if (vet[i + 1] - vet[i] != razao) return 0;
    }

    printf("RESP:%d", razao);
    return 1;
}