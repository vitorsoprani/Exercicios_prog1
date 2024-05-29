#include <stdio.h>

int main() {
    int h1, m1, s1, h2, m2, s2;
    int soma = 0;
    scanf("%d %d %d %d %d %d", &h1, &m1, &s1, &h2, &m2, &s2);

    if (h1 > h2) {
        soma = h1 + m1 + s1;
    } else if (h1 == h2) {
        if (m1 > m2) {
            soma = h1 + m1 + s1;
        } else if (m1 == m2) {
            if (s1 > s2) {
                soma = h1 + m1 + s1;
            } else if (s1 == s2) {
                printf("IGUAIS");
                return 0;
            } else {
                soma = h2 + m2 + s2;
            }
        } else {
            soma = h2 + m2 + s2;
        }
    } else {
        soma = h2 + m2 + s2;
    }
    soma -= soma - (soma % 100);
    soma = soma / 10;

    printf("RESP:%d", soma);
    return 0;
}