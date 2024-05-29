#include <stdio.h>

int main(){
    int n = 0, m = 0, numeroAtual = 0, divisores = 0, i = 0, primo = 0;
    scanf("%d %d", &n, &m);
    printf("RESP:");
    for (numeroAtual = n+1; numeroAtual < m; numeroAtual++){
        divisores = 0;
        primo = 0;
        //programa que checa se o numero é primo:
        for (i = 1; divisores < 2; i++){
            if(numeroAtual == 1) {
                primo = 0;
                break;
            } else if (!(numeroAtual % i)) {
                divisores++;
                if (i == numeroAtual) {
                    primo = 1;
                }
            }
        }
        if (primo) {
            printf("%d ", numeroAtual);
        }
    }
    return 0;
}