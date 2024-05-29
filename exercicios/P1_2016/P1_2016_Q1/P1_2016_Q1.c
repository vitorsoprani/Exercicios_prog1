#include <stdio.h>

int main(){
    int dia;
    scanf("%d", &dia);
    
    if (dia == 1) printf("Domingo");
    else if (dia == 2) printf("Segunda");
    else if (dia == 3) printf("Terca");
    else if (dia == 4) printf("Quarta");
    else if (dia == 5) printf("Quinta");
    else if (dia == 6) printf("Sexta");
    else if (dia == 7) printf("Sabado");
    else printf("Invalido");
    return 0;
}