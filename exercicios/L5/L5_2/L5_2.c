#include <stdio.h>

void LeVetorInt(int notas[], int tam);
void ImprimeVetor(int vet[], int tam);
void OrdenaCrescente(int vet[], int tam);
void OrdenaDecrescente(int vet[], int tam);
void TrocaPosicaoVetor(int vet[], int a, int b);
void CopiaVetor(int vet[], int dst[], int tam);
int EhIgualVetor(int vet1[], int vet2[], int tam);

int main() {
    int qtdNotas, i, crescente = 0, decrescente = 0;
    scanf("%d", &qtdNotas);
    int notas[qtdNotas], copiaNotas[qtdNotas];
    LeVetorInt(notas, qtdNotas);

    CopiaVetor(notas, copiaNotas, qtdNotas);

    OrdenaCrescente(notas, qtdNotas);
    if (EhIgualVetor(notas, copiaNotas, qtdNotas)) crescente = 1;
    OrdenaDecrescente(notas, qtdNotas);
    if (EhIgualVetor(notas, copiaNotas, qtdNotas)) decrescente = 1;

    if (crescente && decrescente) printf("CRESCENTE&DECRESCENTE");
    else if (crescente) printf("CRESCENTE");
    else if (decrescente) printf("DECRESCENTE");
    else printf("DESORDENADO");

    return 0;
}

void LeVetorInt(int vet[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        scanf("%d", &vet[i]);
    }
}

void ImprimeVetor(int vet[], int tam) {
    int i;
    printf("[");
    for (i = 0; i < tam; i++) {
        if (i != tam - 1) {
            printf("%d, ", vet[i]);
        } else {
            printf("%d]", vet[i]);
        }
    }
}

void OrdenaCrescente(int vet[], int tam) {
    int i;

    for (i = 0; i < tam - 1; i++) {
        int j;
        for (j = i + 1; j < tam; j++) {
            if (vet[i] > vet[j]) {
                TrocaPosicaoVetor(vet, j, i);
            }
        }
    }
}

void OrdenaDecrescente(int vet[], int tam) {
    int i;

    for (i = 0; i < tam - 1; i++) {
        int j;
        for (j = i + 1; j < tam; j++) {
            if (vet[i] < vet[j]) {
                TrocaPosicaoVetor(vet, j, i);
            }
        }
    }

}

void TrocaPosicaoVetor(int vet[], int a, int b) {
    int aux;

    aux = vet[a];
    vet[a] = vet[b];
    vet[b] = aux;
}

void CopiaVetor(int vet[], int dst[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        dst[i] = vet[i];
    }
}

int EhIgualVetor(int vet1[], int vet2[], int tam) {
    int iguais = 1, i;
    for (i = 0; i < tam; i++) {
        if (vet1[i] != vet2[i]) iguais = 0;
    }

    return iguais;
}