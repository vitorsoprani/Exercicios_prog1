#include <stdio.h>
#define TRUE 1
#define FALSE 0

int EhPrimo(int num);
int EhDivisorDe(int num1, int num2);

int main() {
    int n, m, i;

    scanf("%d %d", &n, &m);

    for (i = n+1; i < m; i++) {
        if (EhPrimo(i)) {
            printf("%d ", i);
        }
    }
    return 0;
}

int EhPrimo(int num) {
    int divisores = 0, i = 0;
    
    for (i = 2; i <= num; i++) {
        if (EhDivisorDe(i, num)) {
            divisores++;
            
            if (divisores > 1) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

int EhDivisorDe(int num1, int num2) {
    return (!(num2 % num1));
}