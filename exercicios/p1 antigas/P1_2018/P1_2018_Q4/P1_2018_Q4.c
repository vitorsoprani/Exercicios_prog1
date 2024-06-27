#include <stdio.h>

int main() {
    int dia = 0, hora = 0, minuto = 0, incremento = 0;
    scanf("%d:%d %d", &hora, &minuto, &incremento);
    
    minuto += incremento;
    hora += minuto / 60;
    minuto = minuto % 60;
    dia = hora / 24;
    hora = hora % 24;
    
    if (dia) {
        if (dia > 1) printf("(%d dias)", dia);
        else printf("(%d dia)", dia);
    }
    if (hora) {
        if (hora > 1) printf("(%d horas)", hora);
        else printf("(%d hora)", hora);
    }
    if (minuto) {
        if (minuto > 1) printf("(%d minutos)", minuto);
        else printf("(%d minuto)", minuto);
    }
    printf("\n");
    return 0;
}