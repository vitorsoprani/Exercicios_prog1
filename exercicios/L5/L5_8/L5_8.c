#include <stdio.h>

void LeVetor(int vet[], int qtd);
void TrocaParEImpar(int vet[], int qtd);
void ImprimeDadosVetor(int vet[], int qtd);
int EhPar(int n);
void TrocaIndiceAPorB(int vet[], int a, int b);

int main() {
    int qtd;
    scanf("%d", &qtd);
    int vet[qtd];
    LeVetor(vet, qtd);
    
    TrocaParEImpar(vet, qtd);

    ImprimeDadosVetor(vet, qtd);
    return 0;
}

void LeVetor(int vet[], int qtd) {
    int i;
    for (i = 0; i < qtd; i++) {
        scanf("%d", &vet[i]);
    }
}

void TrocaParEImpar(int vet[], int qtd) {
    int i;

    for (i = 0; i < qtd; i++) {
        if (EhPar(i) && i < qtd - 1) {
            TrocaIndiceAPorB(vet, i, i + 1);
        }
    }
}

void ImprimeDadosVetor(int vet[], int qtd) {
    int i;
    printf("{");
    
    if (qtd){
        for (i = 0; i < qtd - 1; i++) {
            printf("%d, ", vet[i]);    
        }
        printf("%d}", vet[i]);
    } else {
        printf("}");
    }
}

int EhPar(int n) {
    return !(n % 2);
}

void TrocaIndiceAPorB(int vet[], int a, int b) {
    int aux;
    aux = vet[a];
    vet[a] = vet[b];
    vet[b] = aux;
}

