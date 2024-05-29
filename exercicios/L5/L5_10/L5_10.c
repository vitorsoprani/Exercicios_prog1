#include <stdio.h>

void LeVetor(int vet[], int qtd);
void ImprimeDadosVetor(int vet[], int qtd);
void OrdenaCrescente(int vet[], int qtd);
int EncontraIdxMenorEntreAeB(int vet[], int a, int b);
void TrocaDeLugar(int vet[], int a, int b);

int main() {
    int qtd;
    scanf("%d", &qtd);
    int vet[qtd];
    LeVetor(vet, qtd);

    OrdenaCrescente(vet, qtd);

    ImprimeDadosVetor(vet, qtd);

    return 0;
}

void LeVetor(int vet[], int qtd) {
    int i;

    for (i = 0; i < qtd; i++) {
        scanf("%d", &vet[i]);
    }
}

void ImprimeDadosVetor(int vet[], int qtd)  {
    int i;
    printf("{");

    if (qtd) {
        for (i = 0; i < qtd - 1; i++) {
            printf("%d, ", vet[i]);
        }
        printf("%d", vet[i]);
    }

    printf("}");
}

void OrdenaCrescente(int vet[], int qtd) {
    int i, aux;
    
    for (i = 0; i < qtd - 1; i++) {
        aux = EncontraIdxMenorEntreAeB(vet, i + 1, qtd - 1);
        if (vet[i] > vet[aux]) TrocaDeLugar(vet, i, aux);
    }
}

int EncontraIdxMenorEntreAeB(int vet[], int a, int b) {
    int i;
    int IdxMenor = a;

    for (i = a + 1; i <= b; i++) {
        if (vet[i] < vet[IdxMenor]) {
            IdxMenor = i;
        }
    }

    return IdxMenor;
}

void TrocaDeLugar(int vet[], int a, int b) {
    int aux;
    aux = vet[a];
    vet[a] = vet[b];
    vet[b] = aux;
}


