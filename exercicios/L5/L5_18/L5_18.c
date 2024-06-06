#include <stdio.h>

void LeMatriz(int l, int c, int mat[l][c]);
void ImprimeMatriz(int l, int c, int mat[l][c]);
int MultiplicaMatriz(int l1,
        int c1,
        int mat1[l1][c1],
        int l2,
        int c2,
        int mat2[l2][c2],
        int matProduto[l1][c2]);

int main() {
    int qtdPares, i;
    scanf("%d", &qtdPares);

    for (i = 1; i <= qtdPares; i++) {
        int l1, c1, l2, c2;
        scanf("%d%d", &c1, &l1);

        int matriz1[l1][c1];
        LeMatriz(l1, c1, matriz1);

        scanf("%d%d", &c2, &l2);
        int matriz2[l2][c2];
        LeMatriz(l2, c2, matriz2);

        int produto[l1][c2];

        if (MultiplicaMatriz(l1, c1, matriz1, l2, c2, matriz2, produto)) {
            ImprimeMatriz(l1, c2, produto);
        } else {
            printf("IMPOSSIVEL\n");
        }
        printf("\n");
    }
    return 0;
}

void LeMatriz(int l, int c, int mat[l][c]) {
    int i, j;
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void ImprimeMatriz(int l, int c, int mat[l][c]) {
    int i, j;
    for (i = 0; i < l; i++) {
        for (j = 0; j < c - 1; j++) {
            printf("%d ", mat[i][j]);
        }

        printf("%d\n", mat[i][j]);

    }
}

int MultiplicaMatriz(int l1,
        int c1,
        int mat1[l1][c1],
        int l2,
        int c2,
        int mat2[l2][c2],
        int matProduto[l1][c2]) {
    //essa funbção realiza o produto caso seja possível e retorna 1 ou 0
    //(1 caso o produto seja reaçliza\dop com sucesso e 0 caso contrário).

    //c1 deve ser igual a l2
    //ordem do algoritimo: primeira linha * primeira coluna (elemento a elemento)
    //a soma será o primeiro elemento da matriz produto.

    if (c1 != l2) return 0;

    int i, j, k;

    //para cada linha de mat1
    for (i = 0; i < l1; i++) {
        //para cada coluna de mat2
        for (j = 0; j < c2; j++) {
            int soma = 0;

            for (k = 0; k < c1; k++) {
                soma += mat1[i][k] * mat2 [k][j];
            }
            //a matriz produdo, na linha e coluna correspondente, recbe o somatório
            //do produto dos elementos correspondentes;
            matProduto[i][j] = soma;
        }
    }

    return 1;
}
