#include <stdio.h>

int main(){
    float temp1 = 0, temp2 = 0;
    int escala = 0;

    scanf("%f", &temp1);
    scanf("%c");//lendo um valor lixo, só para eliminar a tecla espaço do buffer
    scanf("%c", &escala);

    if ((escala == 70) || (escala == 102)){ //valores de F e f na tabela ascii
        temp2 = (temp1 - 32) * (5.0/9.0);
        printf("%.2f (C)", temp2);
    }else if((escala == 67) || (escala == 99)){//valores de C e c na tabela ascii
        temp2 = (temp1 * (9.0/5.0)) + 32;
        printf("%.2f (F)", temp2);
    }
    
    return 0;
}