#include <stdio.h>
#include <math.h>

int main(){
    int k = 0, n = 0;
    float pi2 = 0, pi = 0;

    scanf("%d", &n);

    for(k = 1; k <= n; k++){
        pi2 += ((float)6)/pow(k, 2);
    }
    pi = sqrt(pi2);

    printf("%.6f", pi);
    return 0;
}