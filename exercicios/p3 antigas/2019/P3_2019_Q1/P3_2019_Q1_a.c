#include <stdio.h>

void LeVetorInt(int tamVetor, int vet[]);

void ImprimePares(int tamVet1, int vet1[], int tamVet2, int vet2[]);

int main() {
    int tamVet1, tamVet2;
    
    scanf("%d", &tamVet1);
    int vet1[tamVet1];
    
    LeVetorInt(tamVet1, vet1);
    
    scanf("%d", &tamVet2);
    int vet2[tamVet2];
    
    LeVetorInt(tamVet2, vet2);
    
    ImprimePares(tamVet1, vet1, tamVet2, vet2);
    
    return 0;
}

void LeVetorInt(int tamVetor, int vet[]) {
    int i;
    for (i = 0;i < tamVetor; i++) {
        scanf("%d", &vet[i]);
    }
}

void ImprimePares(int tamVet1, int vet1[], int tamVet2, int vet2[]) {
    int i;
    
    printf("PARES:\n");
    for (i = 0; i < tamVet1; i++) {
        printf("%d - %d\n", vet1[i], vet2[i % tamVet2]);
    }

}