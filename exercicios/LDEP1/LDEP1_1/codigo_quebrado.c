#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    int nPares = 0, n1 = 0, n2 = 0, count = 0;

	scanf("%d", &nPares);
    while(count < nPares){
        scanf("%d %d", &n1, &n2);
        printf("%d\n", n1 + n2);
        count++;
    }

    return 0;
}
