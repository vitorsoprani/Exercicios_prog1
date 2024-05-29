#include <stdio.h>

int Propriedade(int num);

int main() {
    int n, m, i;
    scanf("%d %d", &n, &m);

    for (i = n + 1; i < m; i++) {
        if (Propriedade(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}

int Propriedade(int num) {
    int ab, cd, ef;
    ab = (num - num % 100) / 100;
    cd = num - ab * 100;
    ef = ab + cd;

    return (ef * ef == num);
}