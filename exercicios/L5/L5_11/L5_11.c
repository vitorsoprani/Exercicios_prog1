#include <stdio.h>

void LeVetor(int vet[], int qtd);
void OrdenaCrescente(int vet[], int qtd);
int IdxDoMenorEntreAeB(int vet[], int a, int b);
int EhMaiorQue(int a, int b);
void TrocaDeLugarInt(int vet[], int idxA, int idxB);
void TrocaDeLugarChar(char vet[], int idxA, int idxB);
void ImprimeVetorInt(int vet[], int qtd);
void ImprimeVetorChar(char vet[], int qtd);
void InicializaVetSaida(char vet[], int qtd1, int qtd2);
void UneVetores(int vet1[], int qtd1, int vet2[], int qtd2, int vetResult[]);
void ImprimeResultado(int vet1[], int qtd1, int vet2[], int qtd2);

int main() {
    int qtd1, qtd2;

    scanf("%d", &qtd1);
    int vet1[qtd1];
    LeVetor(vet1, qtd1);
    OrdenaCrescente(vet1, qtd1);
    
    scanf("%d", &qtd2);
    int vet2[qtd2];
    LeVetor(vet2, qtd2);
    OrdenaCrescente(vet2, qtd2);
    
    ImprimeResultado(vet1, qtd1, vet2, qtd2);
    
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
            TrocaDeLugarInt(vet, i, idxAux);
        }
    }
}

int IdxDoMenorEntreAeB(int vet[], int a, int b) {
    //dados um vetor, um índice 'a' e um índice 'b', essa função retorna o índice entre
    //a e b que possui o menor  valor. ('a' e 'b' estão inclusos na  comparação)
    int idxDoMenor = a, i;

    for (i = a + 1; i <= b; i++) {
        if (EhMaiorQue(vet[idxDoMenor], vet[i])) {
            idxDoMenor = i;
        }
    }

    return idxDoMenor;
}

int EhMaiorQue(int a, int b) {
    return a > b;
}

void TrocaDeLugarInt(int vet[], int idxA, int idxB) {
    int aux;

    aux = vet[idxA];
    vet[idxA] = vet[idxB];
    vet[idxB] = aux;
}

void TrocaDeLugarChar(char vet[], int idxA, int idxB) {
    char aux;

    aux = vet[idxA];
    vet[idxA] = vet[idxB];
    vet[idxB] = aux;
}

void ImprimeVetorInt(int vet[], int qtd) {
    int i;
    for (i = 0; i < qtd; i++) {
        printf("%d ", vet[i]);
    }
}

void ImprimeVetorChar(char vet[], int qtd) {
    int i;
    for (i = 0; i < qtd; i++) {
        printf("%c", vet[i]);
    }
}

void InicializaVetSaida(char vet[], int qtd1, int qtd2) {
    //Função que inicializa o vetor de saída com as quantidades corretas de A e B
    int i;
    for (i = 0; i < qtd1; i++) {
        vet[i] = 'A';
    }
    for (i = qtd1; i < qtd1 + qtd2; i++) {
        vet [i] = 'B';
    }
}

void UneVetores(int vet1[], int qtd1, int vet2[], int qtd2, int vetResult[]) {
    int i;
    for (i = 0; i < qtd1; i++) {
        vetResult[i] = vet1[i];
    }
    for (i = 0; i < qtd2; i++) {
        vetResult[qtd1 + i] = vet2[i];
    }
}

void ImprimeResultado(int vet1[], int qtd1, int vet2[], int qtd2) {
    int i = 0, j = 0;

    while (i < qtd1 && j < qtd2) {
        //capara os vetores valor a valor printando A ou B
        if (vet1 [i] <= vet2[j]) {
            printf("A");
            i++;
        } else {
            printf("B");
            j++;
        }
    }

    //termina de imprimir o resultado para os valores remanescentes (caso existam)
    if (i < qtd1) {
        for (i; i < qtd1; i++) {
            printf("A");
        }
    } else if (j < qtd2) {
        for (j; j < qtd2; j++) {
            printf("B");
        }
    }
}