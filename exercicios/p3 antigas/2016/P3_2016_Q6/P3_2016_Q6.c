#include <stdio.h>

int EhBorda(int h, int w, char matriz[h][w], int i, int j);

void LeMatrizChar(int l, int c, char matriz[l][c]);

int main() {
    int w, h; //largura e altura;
    scanf("%d %d\n", &w, &h);

    char mapa[h][w];

    LeMatrizChar(h, w, mapa);

    int custo = 0;
    int i, j;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            if (mapa[i][j] == '0') {
                if (EhBorda(h, w, mapa, i, j)) custo++;
            }
        }
    }
    
    printf("%d\n", custo);
    return 0;
}

void LeMatrizChar(int l, int c, char matriz[l][c]) {
    int i, j;

    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            scanf("%c", &matriz[i][j]);
        }
        scanf("%*c"); //apaga o \n;
    }
}

int EhBorda(int h, int w, char matriz[h][w], int i, int j) {
    int i2, j2;
    
    for (i2 = -1; i2 <= 1; i2++) {
        for (j2 = -1; j2 <= 1; j2++) {
            if (i2 == 0 && j2 == 0) continue;
            if (matriz[i + i2][j + j2] == '1') {
                return 1;
            }
        }
    }
    return 0;
}