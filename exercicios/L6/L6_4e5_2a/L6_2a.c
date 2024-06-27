#include <stdio.h>

#define TAM_MAX_CARTELA 7

typedef struct {
    int id;
    int tamanho;
    int numeros[TAM_MAX_CARTELA][TAM_MAX_CARTELA];
} tCartela;

tCartela LeCartela();

void ImprimeCartela(tCartela cartela);

int main() {
    tCartela cartela;

    cartela = LeCartela();

    ImprimeCartela(cartela);

    return 0;
}

tCartela LeCartela() {
    tCartela cartela;
    
    scanf("%d %d\n", &cartela.id, &cartela.tamanho);
    
    int i, j;
    for(i = 0; i < cartela.tamanho; i++) {
        for (j = 0; j< cartela.tamanho; j++) {
            scanf("%d", &cartela.numeros[j][i]);
        }
    }
    
    scanf("%*[^\n]\n");
    
    return cartela;
}

void ImprimeCartela(tCartela cartela) {
    printf("ID:%d\n", cartela.id);
    
    int i, j;
    for (i = 0; i < cartela.tamanho; i++) {
        for (j = 0; j < cartela.tamanho - 1; j++) {
            printf("%.3d|", cartela.numeros[i][j]);
        }
        printf("%.3d\n", cartela.numeros[i][j]);
    }
}
