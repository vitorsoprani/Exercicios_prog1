#include <stdio.h>

int main(){
    char caracter = 0;
    printf("RESP:");

    while (caracter != '!' && caracter != '?' && caracter != '.') {
        scanf("%c", &caracter);
        
        if (caracter == ' ') continue;
        
        printf("%c", caracter);
    }
    return 0;
}