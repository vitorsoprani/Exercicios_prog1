#include <stdio.h>

int main(){
    int nota1 = 0, nota2 = 0;
    float notaFinal = 0;

    scanf("%d", &nota1);
    scanf("%d", &nota2);
    notaFinal = (nota1 + nota2)/2.0;

    if(notaFinal>=7){
        printf("%.1f - Aprovado", notaFinal);
    } else if (notaFinal>=5){
        printf("%.1f - De Recuperacao", notaFinal);
    }else {
        printf("%.1f - Reprovado", notaFinal);
    }
    return 0;
}