#include <stdio.h>

int PegaCentena(int n);

int main() {
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);
    
    n1 = PegaCentena(n1);
    n2 = PegaCentena(n2);
    n3 = PegaCentena(n3);

    if (!n1 && !n2 && !n3) {
        printf("Nenhum");
        return 0;
    }
    
    if (!n1) n1 = 99999;
    if (!n2) n2 = 99999;
    if (!n3) n3 = 99999;

    if (n1 <= n2) {
        if (n2 <= n3) {
            printf("N1");
        } else {
            if (n1 <= n3) {
                printf("N1");
            } else {
                printf("N3");
            }
        }
    } else {
        if (n2 <= n3) {
            printf("N2");
        } else {
            printf("N3");
        }
    }
    return 0;
}

int PegaCentena(int n) {
    n -= n - (n % 10000);
    n -= n - (n % 1000);
    n -= n % 100;
    return n;
}