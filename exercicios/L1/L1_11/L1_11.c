#include <stdio.h>

int main()
{
    int numero = 0;
    scanf("%d", &numero);
    switch (numero){
        case 1:
            printf("Jan.");
            break;
        case 2:
            printf("Fev.");
            break;
        case 3:
            printf("Mar.");
            break;
        case 4:
            printf("Abr.");
            break;
        case 5:
            printf("Mai.");
            break;
        case 6:
            printf("Jun.");
            break;
        case 7:
            printf("Jul.");
            break;
        case 8:
            printf("Ago.");
            break;
        case 9:
            printf("Set.");
            break;
        case 10:
            printf("Out.");
            break;
        case 11:
            printf("Nov.");
            break;
        case 12:
            printf("Dez.");
            break;
        default:
            printf("Invalido.");
    }

    return 0;
}