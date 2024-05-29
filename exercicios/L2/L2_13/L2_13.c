#include <stdio.h>

int main(){
    char caracter = 0, rodando = 1;
    while (1){
        scanf("%c", &caracter);
        if (caracter == '!' || caracter == '.' || caracter == '?'){
            printf("%c",caracter);
            break;
        }
        if (caracter <= 'z' && caracter >= 'a'){
            caracter -= 32; 
        }
        printf("%c", caracter);
    }
    return 0;
}