#include <stdio.h>
#include <math.h>

int main(){
    float numero1 = 0, numero2 = 0;
    scanf("%f", &numero1);
    scanf("%f", &numero2);
    printf("%.2f", sqrt(numero1) + sqrt(numero2));
    return 0;
}