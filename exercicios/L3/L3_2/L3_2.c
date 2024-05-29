#include <stdio.h>


float Soma(float num1, float num2);
float Subtracao(float num1, float num2);
float Divisao(float num1, float num2);
float Multiplicacao(float num1, float num2);
float RealizaOperacao(float a, float b, char operacao);

int main() {
    float a = 0, b = 0;
    char operacao = 0;

    scanf("%f %f %c", &a, &b, &operacao);
    scanf("%*c"); //Remove do buffer o espaço que possivelmente vem depois.
    
    a = RealizaOperacao(a, b, operacao);
    
    while (scanf("%f %c", &b, &operacao) == 2) {
        a = RealizaOperacao(a, b, operacao);
    }
    
    printf("%.2f", a);
    return 0;
}

float Soma(float num1, float num2) {
    return num1 + num2;
}

float Subtracao(float num1, float num2) {
    return num1 - num2;
}

float Divisao(float num1, float num2) {
    return num1 / num2;
}

float Multiplicacao(float num1, float num2) {
    return num1 * num2;
}

float RealizaOperacao(float a, float b, char operacao) {
    if (operacao == '+') {
        return Soma(a, b);

    } else if (operacao == '-') {
        return Subtracao(a, b);

    } else if (operacao == '/') {
        return Divisao(a, b);

    } else if (operacao == '*') {
        return Multiplicacao(a, b);
    }
}