#include <stdio.h>

#define TAM_MAX 50

/*Le um numero no formato indicado e retorn ao tamanho do numero*/
int LeNumero(int numero[]);

/*Realiza a operaçao e retorna o tamanho do resultado*/
int RealizaOperacao(int n1[], int tamN1, int n2[], int tamN2, int result[]);

void PrintaResultado(int result[], int tamResult);

int main() {
    int n;
    scanf("%d", &n);

    int n1[TAM_MAX];
    int tamN1;
    int n2[TAM_MAX];
    int tamN2;
    int result[TAM_MAX * 2];
    int tamResult;




    int i;
    for (i = 0; i < n; i++) {
        tamN1 = LeNumero(n1);
        tamN2 = LeNumero(n2);
        tamResult = RealizaOperacao(n1, tamN1, n2, tamN2, result);
        PrintaResultado(result, tamResult);
    }

    return 0;
}

int LeNumero(int numero[]) {
    int i = 0;
    scanf("%d", &numero[i]);

    while (numero[i] != -1) {
        i++;
        scanf("%d", &numero[i]);
    }

    return i - 1;
}

int RealizaOperacao(int n1[], int tamN1, int n2[], int tamN2, int result[]) {
    int i;

    int tamResult;
    int resultParcial = 0;

    for (i = 0; 1; i++) {
        if (tamN1 - i >= 0 && tamN2 - i >= 0) {
            n1[tamN1 - i] += resultParcial;
            resultParcial = n1[tamN1 - i] + n2[tamN2 - i];
            result[i] = resultParcial % 10;
            resultParcial -= resultParcial % 10;
            resultParcial /= 10;
        } else if (tamN1 - i >= 0) {
            resultParcial += n1[tamN1 - i];
            result[i] = resultParcial % 10;
            resultParcial -= resultParcial % 10;
            resultParcial /= 10;
        } else {
            result[i] = resultParcial;
            break;
        }
    }
    if (result[i]) return i + 1;
    return i;
}

void PrintaResultado(int result[], int tamResult) {
    int i;
    for (i = tamResult - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
}