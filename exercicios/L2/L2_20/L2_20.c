#include <stdio.h>
#include <math.h>

int main() {
    float a = 0, b = 0, c = 0, d = 0, yAtual, yAnterior;
    int e = 0, f = 0;
    char crescente = 0, haPico = 0, haVale = 0;

    scanf("%f %f %f %f", &a, &b, &c, &d);
    scanf("%d %d", &e, &f);

    yAnterior = a * pow((e - 1), 3) + b * pow((e - 1), 2) + c * (e - 1) + d;
    yAtual = a * pow(e, 3) + b * pow(e, 2) + c * e + d;
    
    if (yAtual > yAnterior) crescente = 1;
    
    for (e; e <= f; e++) {
        
        yAtual = a * pow(e, 3) + b * pow(e, 2) + c * e + d;
        
        if (crescente) {
            if (yAtual < yAnterior) {
                printf("Pico em x=%d\n", e-1);
                crescente = 0;
                haPico = 1;
            }
        } else {
            if (yAtual > yAnterior) {
                printf("Vale em x=%d\n", e-1);
                crescente = 1;
                haVale = 1;
            }
        }
        
        yAnterior = yAtual;
    }
    if (!haPico) printf("Nao ha pico\n");
    if (!haVale) printf("Nao ha vale");
    return 0;
}