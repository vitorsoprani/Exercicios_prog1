#include <stdio.h>

int ContaOcorrencias(int l, int c, char mat[l][c], int tamPadrao, char tipoPadrao, char padrao[]);

void LeMatriz(int l, int c, char mat[l][c]);

int main() {
    char tipoPadrao;
    int tamPadrao;
    scanf("%d%c\n", &tamPadrao, &tipoPadrao);

    char padrao[tamPadrao];
    int i;
    for (i = 0; i < tamPadrao; i++) {
        padrao[i] = 'X';
    }

    int l, c;
    scanf("%d %d\n", &l, &c);

    char matriz[l][c];
    LeMatriz(l, c, matriz);
    
    int cont = ContaOcorrencias(l, c, matriz, tamPadrao, tipoPadrao, padrao);
    
    printf("CONT: %c %d\n", tipoPadrao, cont);

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

int ContaOcorrencias(int l, int c, char mat[l][c], int tamPadrao, char tipoPadrao, char padrao[]) {
    int i, j, p;
    int cont = 0;

    if (tipoPadrao == 'H') {
        for (i = 0; i < l; i++) {
            for (j = 0; j < c; j++) {
                if(j + tamPadrao > c) break;
                
                int compativel = 1;
                
                for (p = 0; p < tamPadrao; p++) {
                    if (mat[i][j + p] != padrao[p]) {
                        compativel = 0;
                        break;
                    }
                }
                if(compativel) cont++;
            }
        }
    } else if (tipoPadrao == 'V') {
        for (j = 0; j < c; j++) {
            for (i = 0; i < l; i++) {
                if(i + tamPadrao > l) break;
                
                int compativel = 1;
                
                for (p = 0; p < tamPadrao; p++) {
                    if (mat[i + p][j] != padrao[p]) {
                        compativel = 0;
                        break;
                    }
                }
                if(compativel) cont++;
            }
        }
    }

    return cont;
}