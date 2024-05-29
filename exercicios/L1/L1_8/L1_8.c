#include <stdio.h>
#include <ctype.h>

int main(){

    char letra = 0;

    scanf("%c", &letra);
    letra = toupper(letra);
    
    if (letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U'){
        printf("Vogal");
    } else {
        printf("Nao vogal");
    }

    return 0;
}