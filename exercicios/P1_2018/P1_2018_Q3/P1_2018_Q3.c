#include <stdio.h>

int EhValido(char c1, char c2, char c3);
int ConverteMaiusculo(char c);
void Compara(char c1, char c2);

int main() {
    char c1, c2, c3, c4, c5, c6;
    scanf("%c%c%c %c%c%c", &c1, &c2, &c3, &c4, &c5, &c6);
    
    if (!EhValido(c1, c2, c3) || !EhValido(c4, c5, c6)){
        printf("Codigo invalido!");
    } else {
        Compara(c1, c4);
        Compara(c2, c5);
        Compara(c3, c6);
    }
    printf("\n");
    return 0;
}

int EhValido(char c1, char c2, char c3){
    if (c1 < '0' || c1 > '9') return 0;
    if (c2 < 'a' || c2 > 'z') return 0;
    if (!(c3 >= 'a' && c3 <= 'z' || c3 >= 'A' && c3 <= 'Z')) return 0;
    
    return 1;
 }

void Compara(char c1, char c2) {
    if (c1 == c2) printf("I");
    else if (ConverteMaiusculo(c1) == ConverteMaiusculo(c2)) printf("C");
    else printf("D");
}

int ConverteMaiusculo(char c){
    if (c >= 'a' && c <= 'z') return c + ((int)'A' - (int)'a');
    return c;
}