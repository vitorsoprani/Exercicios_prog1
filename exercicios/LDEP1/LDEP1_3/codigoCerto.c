#include <stdio.h>

int main() {
    int n = 0, i = 1;

    scanf("%d", &n);

    while(i < n){
        if(!(i % 2) || !(i % 3))
            printf("%d ", i);
        i++;
    }
    printf("\n");
    return 0;
}
