#include <stdio.h>
#include <math.h>

int main(){
    int escolha = 0, i = 0, ii = 0;
    double s = 0;

    scanf("%d", &escolha);

    switch(escolha){
        case 1:
            for (i = 1, ii = 1; (i <= 99) && (ii <= 50); i += 2, ii++){
                s += ((double)i)/ii;
            }
            break;
        case 2:
            for (i = 1, ii = 50; (i <= 50) && (ii >= 1); i++, ii--){
                s += pow(2, i)/((double) ii);
            }
            break;
        case 3:
            int iii = 1;
            for (i = 1, ii = 1, iii = 1; (i <= 10) && (iii <= 100); i++, ii += 2, iii += ii){
                s += i/((double)iii);
            }
            break;
    }
    printf("%lf", s);
    return 0;
}