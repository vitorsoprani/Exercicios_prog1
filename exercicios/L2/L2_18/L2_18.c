#include <stdio.h>

int main() {
    int L = 0, C = 0, i = 0, ii = 0;
    int V = 0, maiorV = -32767, linha = 0, coluna = 0;

    scanf ("%d", &L);
    scanf("%d", &C);

    for (i = 1; i <= L; i++) {
        for (ii = 1; ii <= C; ii++){
            scanf("%d", &V);
            if (maiorV < V) {
                maiorV = V;
                linha = i;
                coluna = ii;
            }
        }
    }
    printf("%d (%d, %d)", maiorV, linha, coluna);
    return 0;
}