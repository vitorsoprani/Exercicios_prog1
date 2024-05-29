#include <stdio.h>

int AreaTotal(
        int r1_x1,
        int r1_y1,
        int r1_x2,
        int r1_y2,
        int r2_x1,
        int r2_y1,
        int r2_x2,
        int r2_y2);

int AreaRetangulo(int x1, int y1, int x2, int y2);

int main() {
    int r1_x1, r1_y1, r1_x2, r1_y2, r2_x1, r2_y1, r2_x2, r2_y2;
    int area;
    scanf("%d %d %d %d", &r1_x1, &r1_y1, &r1_x2, &r1_y2);
    scanf("%d %d %d %d", &r2_x1, &r2_y1, &r2_x2, &r2_y2);

    area = AreaTotal(r1_x1, r1_y1, r1_x2, r1_y2, r2_x1, r2_y1, r2_x2, r2_y2);

    printf("RESP:%d", area);

    return 0;
}

int AreaTotal(
        int r1_x1,
        int r1_y1,
        int r1_x2,
        int r1_y2,
        int r2_x1,
        int r2_y1,
        int r2_x2,
        int r2_y2) {

    int areaTotal = 0;
    areaTotal += AreaRetangulo(r1_x1, r1_y1, r1_x2, r1_y2);
    areaTotal += AreaRetangulo(r2_x1, r2_y1, r2_x2, r2_y2);

    if ((r2_x1 < r1_x2) && (r2_y1 < r1_y2)) {
        areaTotal -= AreaRetangulo(r2_x1, r2_y1, r1_x2, r1_y2);
    }
    return areaTotal;
}

int AreaRetangulo(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (y2 - y1);
}
