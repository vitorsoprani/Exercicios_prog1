#include <stdio.h>

int main(){
    int n = 0, m = 0, nAtual = 0;
    scanf("%d %d", &n, &m);
    printf("RESP:");
    for (nAtual = n + 1; nAtual < m; nAtual++){
        if (!(nAtual %2 )){
            printf("%d ", nAtual);
        }
    }
    return 0;
}