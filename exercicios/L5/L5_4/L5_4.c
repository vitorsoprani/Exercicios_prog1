#include <stdio.h>

void LeVetor(int vet[], int tam);
void ImprimeQtdNumerosEntreAeB(int vet[], int tam, int a, int b);

int main() {
    int n, a, b;
    scanf("%d", &n);
    int numeros[n];
    LeVetor(numeros, n);

    scanf("%d %d", &a, &b);
    ImprimeQtdNumerosEntreAeB(numeros, n, a, b);
    return 0;
}

void LeVetor(int vet[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        scanf("%d", &vet[i]);
    }
}

void ImprimeQtdNumerosEntreAeB(int vet[], int tam, int a, int b) {
    int numerosDentro = 0, numerosFora = 0, i;

    for (i = 0; i < tam; i++) {
        if (vet[i] >= a && vet[i] <= b) {
            numerosDentro++;
        } else {
            numerosFora++;
        }
    }
    printf("%d %d", numerosDentro, numerosFora);
}
