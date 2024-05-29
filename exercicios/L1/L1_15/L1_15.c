#include <stdio.h>

int main(){
    int numero = 0, escolha = 0;
    scanf("%d %d", &numero, &escolha);
    switch (escolha){
        case 1:
            numero = numero % 100;
            numero = numero % 10;
            break;
        case 2:
            numero = numero % 100;
            numero -= numero % 10;
            numero = numero/10;
            break;
        case 3:
            numero -= numero % 100;
            numero = numero/100;
            break;
        default:
            break;
    }

    if (numero % 2){
        printf("IMPAR");
    } else {
        printf("PAR");
    }

    return 0;
}
