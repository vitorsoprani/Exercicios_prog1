#include <stdio.h>

void LeVetor(int vet[], int qtd);
void InverteVetor(int vet[], int qtd);
void ImprimeDadosDoVetor(int vet[], int qtd);

int main() {
    int qtd;
    scanf("%d", &qtd);
    int vet[qtd];
    LeVetor(vet, qtd);

    InverteVetor(vet, qtd);

    ImprimeDadosDoVetor(vet, qtd);
    return 0;
}

void LeVetor(int vet[], int qtd) {
    int i;

    for (i = 0; i < qtd; i++) {
        scanf("%d", &vet[i]);
    }
}

void InverteVetor(int vet[], int qtd) {
    int i;
    int vetInvertido[qtd];

    for (i = 0; i < qtd; i++) {
        vetInvertido[i] = vet[qtd - i -1 ];
    }
    
    for (i = 0; i < qtd; i++) {
        vet[i] = vetInvertido[i];
    }
}

void ImprimeDadosDoVetor(int vet[], int qtd) {
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

