#include <stdio.h>

void LeMatriz(int l, int c, char mat[l][c]);

int ContaDefeitos(int lImg, int cImg, char img[lImg][cImg], int lTemp, int cTemp, char temp[lTemp][cTemp]);

int main() {
    int lImg, cImg;
    scanf("%d %d\n", &lImg, &cImg);
    char img[lImg][cImg];

    LeMatriz(lImg, cImg, img);

    int lTemp, cTemp;
    scanf("%d %d\n", &lTemp, &cTemp);
    char temp[lTemp][cTemp];

    LeMatriz(lTemp, cTemp, temp);

    int qtdDefeitos = ContaDefeitos(lImg, cImg, img, lTemp, cTemp, temp);

    printf("RESP:%d", qtdDefeitos);

    return 0;
}

void LeMatriz(int l, int c, char mat[l][c]) {
    int i, j;

    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            scanf("%c", &mat[i][j]);
        }
        scanf("%*c");
    }
}

int ContaDefeitos(int lImg, int cImg, char img[lImg][cImg], int lTemp, int cTemp, char temp[lTemp][cTemp]) {
    int qtdDefeitos = 0;

    int i, j, k, l;

    for (i = 0; i + lTemp <= lImg; i++) {
//        if (i + lTemp > lImg) break;

        for (j = 0; j + cTemp <= cImg; j++) {
//            if (j + cTemp > cImg) break;

            int compativel = 1;
            for (k = 0; k < lTemp; k++) {
                for (l = 0; l < cTemp; l++) {
                    if (img[i + k][j + l] != temp[k][l]) {
                        compativel = 0;
//                        printf("Incompativel %d %d | %d %d\n", i + k, j + l, k, l);
//                        printf("%c != %c\n", img[i + k][j + l], temp[k][l]);
                        break;
                    }
                }
                if (compativel == 0) {
//                    printf("Incompativel %d %d\n", i, j);
                    break;
                }
            }
            if (compativel) {
//                printf("Compativel %d %d\n", i, j);
                qtdDefeitos++;
            }
        }
    }

    return qtdDefeitos;
}