#include <stdio.h>

/*
    MELHOR SOLÇÃO:
    garantir que os pontos sejam dados na "ordem correta"
    superior esquerdo com menor x e maior y
    inferior direito com o maior x e menor y
*/

    int main(){
        char estaDentroX = 0, estaDentroY = 0;
        float x1 = 0, y1 = 0, x2 = 0, y2 = 0, xp = 0, yp = 0;
        scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &xp, &yp);

        if (((xp >= x1) && (xp <= x2)) || ((xp <= x1) && (xp >= x2))){
            estaDentroX = 1;
        }
        if (((yp >= y1) && (yp <= y2)) || ((yp <= y1) && (yp >= y2))){
            estaDentroY = 1;
        }
        if (estaDentroX && estaDentroY){
            printf("Dentro");
        } else {
            printf("Fora");
        }
        return 0;
    }