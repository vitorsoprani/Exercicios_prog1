#include <stdio.h>

int main()
{
    int numero = 0;
    scanf("%d", &numero);
    if (numero % 2) //se for resto 0, será lido como false -> roda o else
    {
        printf("Impar");
    }
    else
    {
        printf("Par");
    }
    return 0;
}