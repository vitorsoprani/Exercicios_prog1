#include <stdio.h>

int main() {
    int a, b, x1, y1, x2, y2, x3, y3;
    int numerosNaReta = 0;
    
    scanf("%d %d %d %d %d %d %d %d", &a, &b, &x1, &y1, &x2, &y2, &x3, &y3);
    
    if (a*x1 + b == y1) numerosNaReta++;
    if (a*x2 + b == y2) numerosNaReta++;
    if (a*x3 + b == y3) numerosNaReta++;
    
    if (numerosNaReta == 1) {
        printf("Um");
    } else if (numerosNaReta == 2) {
        printf("Dois");
    } else if (numerosNaReta == 3) {
        printf("Todos");
    } else {
        printf("Nenhum");
    }
    return 0;
}