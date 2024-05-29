#include <stdio.h>

void LeVetor(int vet[], int qtd);
void OrdenaCrescente(int vet[], int qtd);
int IdxDoMenorEntreAeB(int vet[], int a, int b);
int EhMaiorQue(int a, int b);
void TrocaDeLugar(int vet[], int idxA, int idxB);
void ImprimeVetor(int vet[], int qtd);
void InicializaVetorSaida(char saida[], int qtd1, int qtd2);

int main() {
    int qtd1, qtd2, qtdTotal;
    
    scanf("%d", &qtd1);
    int vet1[qtd1];
    LeVetor(vet1, qtd1);
    
    scanf("%d", &qtd2);
    int vet2[qtd2];
    LeVetor(vet2, qtd2);

    qtdTotal = qtd1 + qtd2;

    int vetFinal[qtdTotal];

    char saida[qtdTotal];
    InicializaVetorSaida(saida, qtd1, qtd2);
    
    OrdenaCrescente(vet1, qtd1);
    OrdenaCrescente(vet2, qtd2);

    ImprimeVetor(vet1, qtd1);  
    ImprimeVetor(vet2, qtd2);
    return 0;
}

void LeVetor(int vet[], int qtd) {
    //Essa função lê os dados a serem armazenados em um vetor índice a índice.
    int i;
    
    //percorre todos os índeces do vetor
    for (i = 0; i < qtd; i++) {
        scanf("%d", &vet[i]);
    }
}

void OrdenaCrescente(int vet[], int qtd) {
    //Essa função ordena um vetor em ordem crescente.
    int i, idxAux;
    
    //loop que percorre todos os índices do vetor exceto pelo ultimo.
    //(pelo funcionamento do algoritmo, o ultimo índice não precisa ser verificado)
    for (i = 0; i < qtd - 1; i++) {
        idxAux = IdxDoMenorEntreAeB(vet, i + 1, qtd - 1);
        
        if (EhMaiorQue(vet[i], vet[idxAux])) {
            TrocaDeLugar(vet, i, idxAux);
        }
    }
}

int IdxDoMenorEntreAeB(int vet[], int a, int b) {
    //dados um vetor, um índice 'a' e um índice 'b', essa função retorna o índice entre
    //a e b que possui o menor  valor. ('a' e 'b' estão inclusos na  comparação)
    int idxDoMenor = a, i;

    for (i = a + 1; i <= b; i++) {
        if (EhMaiorQue(vet[a], vet[i])) {
            idxDoMenor = i;
        }
    }

    return idxDoMenor;
}

int EhMaiorQue(int a, int b) {
    return a > b;
}

void TrocaDeLugar(int vet[], int idxA, int idxB) {
    int aux;

    aux = vet[idxA];
    vet[idxA] = vet[idxB];
    vet[idxB] = aux;
}

void ImprimeVetor(int vet[], int qtd) {
    int i;
    for (i = 0; i < qtd; i++) {
        printf("%d ", vet[i]);
    }
}

void InicializaVetorSaida(char saida[], int qtd1, int qtd2) {
    int i;
    for (i = 0; i < qtd1; i++) {
        saida[i] = 'A';
    }
    for (i = qtd1; i < qtd1+qtd2; i++) {
        saida[i] = 'B';
    }

    for (i = 0; i < qtd1 + qtd2; i++) {
        printf("%c", saida[i]);
    }
}
