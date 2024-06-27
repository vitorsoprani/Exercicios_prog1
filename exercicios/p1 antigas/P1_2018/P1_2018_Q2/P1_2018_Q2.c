#include <stdio.h>

int main() {
    int troco1, troco2, qtdTroco1 = 0, qtdTroco2 = 0;
    scanf("%d %d", &troco1, &troco2);

    qtdTroco1 = troco1 / 5 + troco1 % 5;

    qtdTroco2 = troco2 / 5 + troco2 % 5;


    if (qtdTroco1 < qtdTroco2) {
        printf("QTD troco 2 eh maior!");
    } else if (qtdTroco1 > qtdTroco2) {
        printf("QTD troco 1 eh maior!");
    } else {
        printf("Iguais!");
    }

    return 0;
}