#include <stdio.h>

#define TAM_MAX_CARTELA     7
#define QTD_MAX_CARTELAS    100

typedef struct {
    int id;
    int tamanho;
    int numeros[TAM_MAX_CARTELA][TAM_MAX_CARTELA];
    int marcacoes[TAM_MAX_CARTELA][TAM_MAX_CARTELA];
} tCartela;

tCartela LeCartela();

void ImprimeCartela(tCartela cartela);

tCartela MarcaCartela(tCartela cartela, int numero);

int VenceuCartela(tCartela cartela);

tCartela ResetaCartela(tCartela cartela);

typedef struct {
    int qtdCartelas;
    tCartela cartelas[QTD_MAX_CARTELAS];
} tPartida;

tPartida LeCartelasPartida();

void ImprimeInvCartelasPartida(tPartida partida);

tPartida ResetaPartida(tPartida partida);

void JogaPartida(tPartida partida);

int main() {
    tPartida partida;
    int qtdPartidas, i;

    partida = LeCartelasPartida();

    scanf("%d", &qtdPartidas);
    for (i = 0; i < qtdPartidas; i++) {
        if (i != 0) printf("\n");
        printf("PARTIDA %d\n", i + 1);
        partida = ResetaPartida(partida);
        JogaPartida(partida);
    }

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

tCartela MarcaCartela(tCartela cartela, int numero) {
    int i, j;

    for (i = 0; i < cartela.tamanho; i++) {
        for (j = 0; j < cartela.tamanho; j++) {
            if (cartela.numeros[i][j] == numero) {
                cartela.marcacoes[i][j] = 1;
            }
        }
    }
    return cartela;
}

int VenceuCartela(tCartela cartela) {
    int i, j;

    for (i = 0; i < cartela.tamanho; i++) {
        for (j = 0; j < cartela.tamanho; j++) {
            if (cartela.marcacoes[i][j] == 0) return 0;
        }
    }
    return 1;
}

tCartela ResetaCartela(tCartela cartela) {
    int i, j;

    for (i = 0; i < cartela.tamanho; i++) {
        for (j = 0; j < cartela.tamanho; j++) {
            cartela.marcacoes[i][j] = 0;
        }
    }

    return cartela;
}

tPartida LeCartelasPartida() {
    tPartida partida;

    scanf("%d", &partida.qtdCartelas);

    int i;
    for (i = 0; i < partida.qtdCartelas; i++) {
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

tPartida ResetaPartida(tPartida partida) {
    int i;

    for (i = 0; i < partida.qtdCartelas; i++) {
        partida.cartelas[i] = ResetaCartela(partida.cartelas[i]);
    }

    return partida;
}

void JogaPartida(tPartida partida) {
    int numero, temVencedores = 0;
    int i;

    scanf("%d", &numero);
    while (numero != -1) {
        if (!temVencedores) {
            for (i = 0; i < partida.qtdCartelas; i++) {
                partida.cartelas[i] = MarcaCartela(partida.cartelas[i], numero);

                if (VenceuCartela(partida.cartelas[i])) {
                    if (!temVencedores){
                        temVencedores = 1;
                        printf("COM VENCEDOR\n");
                    }
                    ImprimeCartela(partida.cartelas[i]);
                }
            }
        }
        scanf("%d", &numero);
    }

    if (!temVencedores) {
        printf("SEM VENCEDOR\n");
    }
}