#include <stdio.h>
#define CODIFICA 1
#define DECODIFICA 2
#define TAM_ALFABETO 26

char Codifica(char letra, int n);
char Decodifica(char letra, int n);
int EhLetra(char c);
int EhLetraMaiuscula(char c);
int EhLetraMinuscula(char c);

int main() {
    int modo = 0, chave = 0;
    

    scanf("%d %d", &modo, &chave);
    scanf("%*c");

    if (modo == CODIFICA) {
        while (1) {
            char caracter;
            scanf("%c", &caracter);

            if (EhLetra(caracter)) {
                caracter = Codifica(caracter, chave);
            }
            printf("%c", caracter);
            if (caracter == '.') break;
        }
    } else if (modo == DECODIFICA) {
        while (1) {
            char caracter;
            scanf("%c", &caracter);
            
            if (EhLetra(caracter)) {
                caracter = Decodifica(caracter, chave);
            }
            printf("%c", caracter);
            if (caracter == '.') break;
        }
    } else {
        printf("Operacao invalida.");
    }

    return 0;
}

char Codifica(char letra, int n) {
    int letraINT = (int)letra;
    
    if (EhLetraMaiuscula(letra)){
        letraINT += (n*2) % TAM_ALFABETO;
    
        if (letraINT > (int)'Z'){
            letraINT -= TAM_ALFABETO;
        } else if (letraINT < (int)'A'){
            letraINT += TAM_ALFABETO;
        }
    } else if (EhLetraMinuscula(letra)){
        letraINT += n % TAM_ALFABETO;
    
        if (letraINT > (int)'z'){
            letraINT -= TAM_ALFABETO;
        } else if (letraINT < (int)'a'){
            letraINT += TAM_ALFABETO;
        }
    }

    return (char)letraINT;
}

char Decodifica(char letra, int n) {
    int letraINT = (int)letra;
    
    if (EhLetraMaiuscula(letra)){
        letraINT -= (n*2) % TAM_ALFABETO;
    
        if (letraINT < (int)'A'){
            letraINT += TAM_ALFABETO;
        } else if (letraINT > (int)'Z'){
            letraINT -= TAM_ALFABETO;
        }
    } else if (EhLetraMinuscula(letra)){
        letraINT -= n % TAM_ALFABETO;
    
        if (letraINT < (int)'a'){
            letraINT += TAM_ALFABETO;
        } else if (letraINT > (int)'z'){
            letraINT -= TAM_ALFABETO;
        }
    } 
    
    return (char)letraINT;
}

int EhLetra(char c) {
    return (c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A');
}

int EhLetraMaiuscula(char c) {
    return c <= 'Z' && c >= 'A';
}

int EhLetraMinuscula(char c) {
    return c <= 'z' && c >= 'a';
}