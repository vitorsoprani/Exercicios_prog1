#include <stdio.h>

int main(){
    int i = 2, den = 0, qtd = 0, cont = 0;

    scanf("%d", &qtd);

    for(i; i <= qtd; i++){
        den = 1;
        cont = 0;
        for(den; den <= i; den++){
            if(!(i % den)){
                cont++;
            }
        }
        if(cont == 2)
            printf("%d ", i);
    }
    return 0;
}
