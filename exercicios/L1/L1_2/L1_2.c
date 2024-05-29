#include <stdio.h>

int main(){
    float altura = 0, largura = 0;
    scanf("%f", &altura);
    scanf("%f", &largura);
    printf("%.2f", (altura*2) + (largura*2));
    
    return 0;
}