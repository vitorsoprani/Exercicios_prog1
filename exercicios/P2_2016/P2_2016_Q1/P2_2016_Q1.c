#include <stdio.h>
#define IMPAR 1
#define PAR 2
int EhPar(int n);

int main(){
    int qntNumeros = 0, i;
    int tipo = 0, qntTipo = 1;
    int numero;
    
    scanf("%d", &qntNumeros);
    scanf("%d", &numero);
    
    if (EhPar(numero)){
        tipo = PAR;
    } else {
        tipo = IMPAR;
    }
    
    for (i = 1; i < qntNumeros; i++) {
        scanf("%d", &numero);
        if (EhPar(numero)){
            if (tipo == PAR) qntTipo ++;
        } else {
            if (tipo == IMPAR) qntTipo ++;
        }
    }
    
    if (tipo == PAR) {
        printf("QTD PARES:%d", qntTipo);
    } else {
        printf("QTD IMPARES:%d", qntTipo);
    }
    
    return 0;
}

int EhPar(int n) {
    return !(n%2);
}