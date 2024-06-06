#include <stdio.h>

int EhStrValida(char *str1);
void AnalisaStrings(char *str1, char *str2, FILE* f);

int main(){

    FILE *arq, *arq2;
    char str1[4], str2[4];
    int i = 0;

    arq = fopen("input/entrada.txt", "r");
    arq2 = fopen("output/saida.txt", "w");

    while(i < 8){
        fscanf(arq, "%s %s", str1, str2);
        if(!(EhStrValida(str1)) || !(EhStrValida(str2))){
            fprintf(arq2, "INVALIDO\n");
        } else{
            AnalisaStrings(str1, str2, arq2);
        }
        i++;
    }

    fclose(arq);
    fclose(arq2);
    return 0;
}

int EhStrValida(char *str){
    int i = 0, valido = 1;
    for(i = 0; i < 3; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            valido = 1;
        } else if(str[i] >= 'a' && str[i] <= 'z'){
            valido = 1;
        } else if(str[i] >= 'A' && str[i] <= 'Z'){
            valido = 1;
        } else{
            valido = 0;
            break;
        }
    }
    return valido;
}

void AnalisaStrings(char *str1, char *str2, FILE* f){

    int i = 0, iguais = 1;
    for(i = 0; i < 3; i++){
        if(str1[i] == str2[i] || str1[i] == str2[i]+32 || str1[i] == str2[i]-32){
            iguais = 1;
        } else{
            iguais = 0;
            break;
        }
    }

    if(iguais){
        fprintf(f, "IGUAIS\n");
    } else{
        fprintf(f, "DIFERENTES\n");
    }
}