#include <stdio.h>

int main() {
    char caracter = 0;
    scanf("%c", &caracter);
    printf("RESP:");
    while ((caracter != '!') && (caracter != '.') && (caracter != '?')) {
        if (caracter == ' ') {
            printf("_");
        } else {
            printf("%c", caracter);
        }
        scanf("%c", &caracter);
    }
    printf("%c", caracter);
    return 0;
}