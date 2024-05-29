#include <stdio.h>

int main() {
    char caracter = 0, primeiraImpressao = 1;
    int parenteseExtra = 0;

    while (1) {
        scanf("%c", &caracter);
        if (caracter == '(') {

            while (1) {
                scanf("%c", &caracter);

                if (primeiraImpressao) {
                    primeiraImpressao = 0;
                    printf("RESP:");
                }

                if (caracter == '(') {
                    parenteseExtra++;
                }

                if (caracter == ')') {
                    if (parenteseExtra) {
                        parenteseExtra--;
                    } else {
                        break;
                    }
                }
                printf("%c", caracter);
            }
        }

        if (caracter == '.') {
            break;
        }
    }
    return 0;
}