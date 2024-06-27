#include <stdio.h>

float FazOperacao(float num1, float num2, char op);
float ResolveExpressao();

int main() {
    float maiorValor = -32000;
    while (1) {
        float valorAtual;
        char c = 0;

        scanf("%c", &c);

        if (c == '(') {
            valorAtual = ResolveExpressao();
            printf("%.2f", valorAtual);
            if (valorAtual > maiorValor) maiorValor = valorAtual;
        } else {
            printf("%c", c);
        }
        if (c == '.') break;
    }
    printf(" MAIOR:%.2f", maiorValor);
    return 0;
}

float FazOperacao(float num1, float num2, char op) {
    if (op == '+') {
        return num1 + num2;
    } else if (op == '-') {
        return num1 - num2;
    } else if (op == '*') {
        return num1 * num2;
    } else if (op == '/') {
        return num1 / num2;
    }
}

float ResolveExpressao() {
    float valor = 0, num1, num2;
    char op;

    scanf("%f %f %c", &num1, &num2, &op);

    valor = FazOperacao(num1, num2, op);

    while (scanf("%f %c", &num2, &op) == 2) {
        valor = FazOperacao(valor, num2, op);
    }

    scanf("%*c");
    return valor;
}
