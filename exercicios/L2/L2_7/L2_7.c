#include <stdio.h>

int main(){
    int numero = 0, i = 0, divisores = 0, primo = 0;
    scanf("%d", &numero);

    for (i = 1; divisores < 2; i++){
        if(numero == 1) {
            break;
        } else if (!(numero % i)) {
            divisores++;
            if (i == numero) primo = 1;
        }
    }
    primo ? printf("Primo") : printf("Nao primo");
    return 0;
}