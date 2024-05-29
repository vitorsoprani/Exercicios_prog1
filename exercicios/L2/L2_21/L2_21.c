#include <stdio.h>

int main() {
    int qntNumeros = 0, i, n1, n2, n3, n4, n5, n6, n7, n8, n9;
    char caracter = 0;
    scanf("%d", &qntNumeros);
    scanf("%*c");

    for (i = 1; i <= qntNumeros; i++) {
        if (i == 1) {
            scanf("%d", &n1);
            scanf("%*c");
        } else if (i == 2) {
            scanf("%d", &n2);
            scanf("%*c");
        } else if (i == 3) {
            scanf("%d", &n3);
            scanf("%*c");
        } else if (i == 4) {
            scanf("%d", &n4);
            scanf("%*c");
        } else if (i == 5) {
            scanf("%d", &n5);
            scanf("%*c");
        } else if (i == 6) {
            scanf("%d", &n6);
            scanf("%*c");
        } else if (i == 7) {
            scanf("%d", &n7);
            scanf("%*c");
        } else if (i == 8) {
            scanf("%d", &n8);
            scanf("%*c");
        } else if (i == 9) {
            scanf("%d", &n9);
            scanf("%*c");
        }
    }
    scanf("%*c"); //Apaga o caracter seguinte (que deve ser uma aspa dupla)

    while (1) {
        scanf("%c", &caracter);
        if (caracter == 34) {
            break;
        } else if (caracter == 37) {
            scanf("%d", &i);
            if (i < 1 || i > qntNumeros) {
                printf("ERRO");
            } else {
                if (i == 1) printf("%d", n1);
                else if (i == 2) printf("%d", n2);
                else if (i == 3) printf("%d", n3);
                else if (i == 4) printf("%d", n4);
                else if (i == 5) printf("%d", n5);
                else if (i == 6) printf("%d", n6);
                else if (i == 7) printf("%d", n7);
                else if (i == 8) printf("%d", n8);
                else if (i == 9) printf("%d", n9);
            }
        } else {
            printf("%c", caracter);
        }
    }
    return 0;
}
