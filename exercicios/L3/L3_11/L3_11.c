#include <stdio.h>
#define PAR 0
#define IMPAR 1

int EhPar(int numero);
void PrintaPares(int N);
void PrintaImpares(int N);

int main() {
    int modo, N;
    scanf("%d %d", &modo, &N);

    if (modo == PAR) {
        PrintaPares(N);
    } else if (modo == IMPAR) {
        PrintaImpares(N);
    }

    return 0;
}

int EhPar(int numero) {
    return !(numero % 2);
}

void PrintaPares(int N) {
    int i, qntPrintados = 1;
    
    for (i = 2; qntPrintados <= N; i++){
        if (EhPar(i)){
            printf("%d ", i);
            qntPrintados ++;
        }
    }
}

void PrintaImpares(int N) {
    int i, qntPrintados = 1;
    
    for (i = 1; qntPrintados <= N; i++){
        if (!EhPar(i)){
            printf("%d ", i);
            qntPrintados ++;
        }
    }
}