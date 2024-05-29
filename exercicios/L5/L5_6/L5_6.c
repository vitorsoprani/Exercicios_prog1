#include <stdio.h>
#define TODOS 1
#define NENHUM 0
#define PARCIAL 2

void LeVetor(int *vet, int tam);
int EstaContidoAEmB(int *vetA, int tamA, int *vetB, int tamB);

int main() {
    int n1, n2;
    scanf("%d", &n1);
    int seq1[n1];
    LeVetor(seq1, n1);
    scanf("%d", &n2);
    int seq2[n2];
    LeVetor(seq2, n2);

    switch (EstaContidoAEmB(seq1, n1, seq2, n2)) {
        case TODOS:
            printf("TODOS");
            break;
        case NENHUM:
            printf("NENHUM");
            break;
        case PARCIAL:
            printf("PARCIAL");
            break;
    }
    return 0;
}

void LeVetor(int *vet, int tam) {
    int i;

    for (i = 0; i < tam; i++) {
        scanf("%d", &vet[i]);
    }
}

int EstaContidoAEmB(int *vetA, int tamA, int *vetB, int tamB) {
    int i, j, qtdContidos = 0;

    for (i = 0; i < tamA; i++) {
        for (j = 0; j < tamB; j++) {
            if (vetA[i] == vetB[j]) {
                qtdContidos++;
                break;
            }
        }
    }

    if (qtdContidos == 0) return NENHUM;
    if (qtdContidos == tamA) return TODOS;
    return PARCIAL;
}