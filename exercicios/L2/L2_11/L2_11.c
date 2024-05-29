#include <stdio.h>

int main(){
    int abcd = 0, ab = 0, cd = 0, ef = 0;
    int n = 0, m = 0;

    scanf("%d %d", &n, &m);
    for (n += 1; n < m; n++){
        abcd = n;
        ab = abcd - (abcd%100);
        cd = abcd - ab;
        ab = ab/100;
        ef = ab + cd;
        if ((ef * ef) == abcd) printf("%d\n", abcd);
    }
    return 0;
}