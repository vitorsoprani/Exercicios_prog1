#include <stdio.h>

int main() {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    if (x1 < x2) {
        if (y1 < y2) {
            //p1 é o canto inferior esquerdo
            printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)\n", x1, y2, x1, y1, x2, y1, x2, y2);
        } else {
            //p1 é o canto superior esquerdo
            printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)\n", x1, y1, x1, y2, x2, y2, x2, y1);
        }
    } else {
        if (y1 < y2) {
            //p1 é o canto inferior direito
            printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)\n", x2, y2, x2, y1, x1, y1, x1, y2);
        } else {
            //p1 é o canto superior direito
            printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)\n", x2, y1, x2, y2, x1, y2, x1, y1);
        }
    }
    return 0;
}