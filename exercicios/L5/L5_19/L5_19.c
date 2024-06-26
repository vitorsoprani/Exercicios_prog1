#include <stdio.h>
#define TERRA '0'
#define AGUA '1'

void LeMatrizChar(int l, int c, char mat[l][c]);
void ImprimeMatrizChar(int l, int c, char mat[l][c]);
int ContaTerraVisivel(int l, int c, char mat[l][c]);
void SimulaMare(int tempo, int l, int c, char mat[l][c]);
void CopiaMatriz(int l, int c, char mat1[l][c], char mat2[l][c]);
int TemAguaPerto(int l, int c, char mat[l][c], int i, int j);

int main() {
    int tempo, h, w, qtdTerra;
    scanf("%d\n", &tempo);
    scanf("%d %d\n", &w, &h);

    char img[h][w];
    LeMatrizChar(h, w, img);

    qtdTerra = ContaTerraVisivel(h, w, img);
    printf("%d ", qtdTerra);

    SimulaMare(tempo, h, w, img);
    qtdTerra = ContaTerraVisivel(h, w, img);
    printf("%d\n", qtdTerra);

    return 0;
}

void LeMatrizChar(int l, int c, char mat[l][c]) {
    int i, j;

    //procedimento padrão para percorrer todas as posições da matriz
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            scanf("%c", &mat[i][j]);
        }
        scanf("%*c"); //apaga o \n no final de cada linha
    }
}

void ImprimeMatrizChar(int l, int c, char mat[l][c]) {
    int i, j;

    //procedimento padrão para percorrer todas as posições da matriz
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
}

int ContaTerraVisivel(int l, int c, char mat[l][c]) {
    int i, j;
    int qtdTerra = 0;

    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            if (mat[i][j] == TERRA) qtdTerra++;
        }
    }

    return qtdTerra;
}

void SimulaMare(int tempo, int l, int c, char mat[l][c]) {
    int i, j, t;
    char proxMat[l][c];
    
    //cria uma cópia da matriz, onde serão salvas as mudanças antes de
    //transcreve-las para a matriz principal
    CopiaMatriz(l, c, mat, proxMat);

    //laço para reralizar o procedimento o numero de vezes ja definido
    for (t = 1; t <= tempo; t++) {
        //novamente percorre todas as posições da matriz
        for (i = 0; i < l; i++) {
            for (j = 0; j < c; j++) {
                if (TemAguaPerto(l, c, mat, i, j)) proxMat[i][j] = AGUA;
            }
        }
        //transfere as mudanças feitas para a matriz principal
        CopiaMatriz(l, c, proxMat, mat);
    }
}

void CopiaMatriz(int l, int c, char mat1[l][c], char mat2[l][c]) {
    int i, j;

    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            mat2[i][j] = mat1[i][j];
        }
    }
}

int TemAguaPerto(int h, int w, char mat[h][w], int l, int c) {
    int i;

    for (i = -1; i <= 1; i += 2) {
        //checa as posições imediatamente acima/abaixo ou imediatamente ao lado
        //da posiçao indicada
        if (mat[l + i][c] == AGUA) return 1;
        if (mat[l][c + i] == AGUA) return 1;
    }

    return 0;
}