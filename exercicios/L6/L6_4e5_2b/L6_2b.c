#include <stdio.h>

#define TAM_MAX_CARTELA     7
#define QTD_MAX_CARTELAS    100

typedef struct {
    int id;
    int tamanho;
    int numeros[TAM_MAX_CARTELA][TAM_MAX_CARTELA];
} tCartela;

tCartela LeCartela();

void ImprimeCartela(tCartela cartela);

typedef struct {
    int qtdCartelas;
    tCartela cartelas[QTD_MAX_CARTELAS];
} tPartida;

tPartida LeCartelasPartida();

void ImprimeInvCartelasPartida(tPartida partida);

int main() {
    tPartida partida;

    partida = LeCartelasPartida();

    ImprimeInvCartelasPartida(partida);

    return 0;
}

tCartela LeCartela() {
    tCartela cartela;

    scanf("%d %d\n", &cartela.id, &cartela.tamanho);

    int i, j;
    for (i = 0; i < cartela.tamanho; i++) {
        for (j = 0; j < cartela.tamanho; j++) {
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

tPartida LeCartelasPartida() {
    tPartida partida;
    
    scanf("%d", &partida.qtdCartelas);
    
    int i;
    for (i = 0; i < partida.qtdCartelas; i ++) {
        partida.cartelas[i] = LeCartela();
    }
    return partida;
}

void ImprimeInvCartelasPartida(tPartida partida) {
    int i;
    for (i = partida.qtdCartelas - 1; i >= 0; i--) {
        ImprimeCartela(partida.cartelas[i]);
    }
}
