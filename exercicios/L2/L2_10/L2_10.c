#include <stdio.h>

int main(){
    int n = 0, m = 0, cont = 0, i = 0;
    scanf("%d %d", &n, &m);
    for (cont = n; cont <= m; cont++){
        for(i = 1; i <= 10; i++){
            printf("%d x %d = %d\n", cont, i, (cont * i));
        }
    }
    return 0;
}