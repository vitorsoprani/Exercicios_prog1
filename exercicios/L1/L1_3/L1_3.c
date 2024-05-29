#include <stdio.h>

int main(){
    float x1 = 0, y1 = 0, x2 = 0, y2 = 0, largura = 0, altura = 0;

    scanf ("%f", &x1);
    scanf ("%f", &y1);
    scanf ("%f", &x2);
    scanf ("%f", &y2);

    largura = x2 - x1;
    altura = y2 - y1;

    printf("%.2f", (altura*2) + (largura *2));
    return 0;
}