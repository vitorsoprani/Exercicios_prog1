#include <stdio.h>

int main(){
    int n = 0, m = 0, i = 0;
    scanf("%d %d", &n, &m);

    for (i = n + 1; i < m; i++){
        if (!(i % 3) || !(i % 4) || !(i % 7)){
            printf("%d ", i);
        }
    }

    return 0;
}
