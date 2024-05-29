#include <stdio.h>

int main() {
    int numero = 0, milhar = 0, centena = 0, dezena = 0;
    scanf("%d", &numero);

    while (numero > 9) {
        milhar = numero - numero % 1000;
        numero -= milhar;

        centena = numero - numero % 100;
        numero -= centena;

        dezena = numero - numero % 10;
        numero -= dezena;
           
        numero += milhar/1000;
        numero += centena/100;
        numero += dezena/10;
    }
    printf("RESP:%d", numero);
    return 0;
}