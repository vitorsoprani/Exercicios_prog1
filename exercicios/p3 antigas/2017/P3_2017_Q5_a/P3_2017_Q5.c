#include <stdio.h>

void DeslocaVetor(int vet[], int tamVet, int desloc);

void CopiaVetor(int origem[], int destino[], int tam);

int Mod(int n);

int main() {
    int tamVet;

    while (scanf("%d", &tamVet) == 1) {
        int vet1[tamVet];
        int vet2[tamVet];
        int i;

        for (i = 0; i < tamVet; i++) {
            scanf("%d", &vet1[i]);
        }
        //printf("Vetor 1 lido\n");

        i = 0;
        scanf("%d", &vet2[i]);
        while (vet2[i] != -1) {
            i++;
            scanf("%d", &vet2[i]);
        }
        //printf("Vetor 2 lido\n");


        int tamVet2 = i + 1;

        for (i = 0; i < tamVet2 - 1; i++) {
            DeslocaVetor(vet1, tamVet, vet2[i]);
            int j;
            for (j = 0; j < tamVet - 1; j++) {
                printf("%d ", vet1[j]);
            }
            printf("%d\n", vet1[j]);
        }
    }

    return 0;
}

void DeslocaVetor(int vet[], int tamVet, int desloc) {
    int vetNovo[tamVet];

    int i;
    for (i = 0; i < tamVet; i++) {
        vetNovo[(i + desloc) % tamVet] = vet[i];
    }

    CopiaVetor(vetNovo, vet, tamVet);

}

void CopiaVetor(int origem[], int destino[], int tam) {
    int i;

    for (i = 0; i < tam; i++) {
        destino[i] = origem[i];
    }
}

int Mod(int n) {
    if (n < 0) return - n;
    return n;
}