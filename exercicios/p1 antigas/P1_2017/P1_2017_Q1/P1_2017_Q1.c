#include <stdio.h>

void FazOperacao(int n1, int n2, char operacao);

int main() {
    int n1, n2;
    char operacao;
    scanf("%d %d %c", &n1, &n2, &operacao);

    FazOperacao(n1, n2, operacao);

    return 0;
}

void FazOperacao(int n1, int n2, char operacao) {
    switch (operacao) {
        case '+':
            printf("RESP:%d", n1 + n2);
            break;
        case '-':
            printf("RESP:%d", n1 - n2);
            break;
        case '*':
            printf("RESP:%d", n1 * n2);
            break;
        case '/':
            printf("RESP:%d", n1 / n2);
            break;
        default:
            printf("Invalido");
            break;
    }
}