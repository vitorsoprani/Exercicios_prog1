#include <stdio.h>

int main() {
    int topo = 0, meio = 0;
    int i;
    scanf("%d %d", &topo, &meio);

    for (i = topo; i < meio; i += 2) {
        int lateral = (meio - i) / 2;
        int ii;

        for (ii = 1; ii <= lateral; ii++) printf("_");
        for (ii = 1; ii <= i; ii++) printf("$");
        for (ii = 1; ii <= lateral; ii++) printf("_");
        printf("\n");
    }
    for (i = meio; i >= 1; i -= 2) {
        int lateral = (meio - i) / 2;
        int ii;

        for (ii = 1; ii <= lateral; ii++) printf("_");
        for (ii = 1; ii <= i; ii++) printf("$");
        for (ii = 1; ii <= lateral; ii++) printf("_");
        printf("\n");
    }
}