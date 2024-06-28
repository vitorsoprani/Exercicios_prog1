#include <stdio.h>

void LeMatriz(int l, int c, char mat[l][c]);

void ChecaSoldas(int lPlaca, int cPlaca, char placa[lPlaca][cPlaca], int lTemp, int cTemp, char temp[lTemp][cTemp]);

int main() {
    int lPlaca, cPlaca;
    scanf("%d %d\n", &lPlaca, &cPlaca);
    
    char placa[lPlaca][cPlaca];
    LeMatriz(lPlaca, cPlaca, placa);
    
    int lTemplate, cTemplate;
    scanf("%d %d\n", &lTemplate, &cTemplate);
    
    char template[lTemplate][cTemplate];
    LeMatriz(lTemplate, cTemplate, template); 
    
    ChecaSoldas(lPlaca, cPlaca, placa, lTemplate, cTemplate, template);
    
    return 0;
}

void LeMatriz(int l, int c, char mat[l][c]) {
    int i, j;
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            scanf("%c", &mat[i][j]);
        }
        scanf("%*c");//apaga o \n
    }
}

void ChecaSoldas(int lPlaca, int cPlaca, char placa[lPlaca][cPlaca], int lTemp, int cTemp, char temp[lTemp][cTemp]) {
    int i, j, k, l;
    
    for (i = 0; i < lPlaca; i++) {
        if (i + lTemp > lPlaca) break;
        for (j = 0; j < cPlaca; j++) {
            if (j + cTemp > cPlaca) break;
            
            int compativel = 1;
            for (k = 0; k < lTemp; k++) {
                for (l = 0; l < cTemp; l++) {
                    if (placa[i + k][j + l] != temp[k][l]) {
                        //printf("%d != %d\n", placa[i + k][j + l], temp[k][l]);
                        compativel = 0;
                        break;
                    }
                }
                if (!compativel) break;
            }
            
            if(compativel) printf("%d,%d\n", j, i); 
        }
    }
}