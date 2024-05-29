#include <stdio.h>

typedef struct {
    int x;
    int y;
} tPonto;

tPonto InicializaPonto(int x, int y);
tPonto LePonto();
void ImprimePonto(tPonto p);
tPonto AlteraX(tPonto p, int novoX);
tPonto AlteraY(tPonto p, int novoY);
int XPonto(tPonto p);
int YPonto(tPonto p);
tPonto MovePonto(tPonto pontoInicial, int deltaX, int deltaY);
float DistanciaEntre2Pontos(tPonto p1, tPonto p2);
int QuadranteDoPonto(tPonto p);
tPonto CimetricoPonto(tPonto p);

int main() {
    int qtdPontos, i;
    scanf("%d", &qtdPontos);

    for (i = 1; i <= qtdPontos; i++) {
        tPonto ponto = LePonto(ponto);
        ImprimePonto(ponto);
        printf(" %d ", QuadranteDoPonto(ponto));
        ponto = CimetricoPonto(ponto);
        ImprimePonto(ponto);
        printf(" %d\n", QuadranteDoPonto(ponto));
    }
    return 0;
}

tPonto InicializaPonto(int x, int y) {
    tPonto p = {x, y};
    return p;
}

tPonto LePonto() {
    int x, y;
    scanf("%d %d\n", &x, &y);

    return InicializaPonto(x, y);
}

void ImprimePonto(tPonto p) {
    printf("(%d,%d)", p.x, p.y);
}

tPonto AlteraX(tPonto p, int novoX) {
    p.x = novoX;
    return p;
}

tPonto AlteraY(tPonto p, int novoY) {
    p.y = novoY;
    return p;
}

int XPonto(tPonto p) {
    return p.x;
}

int YPonto(tPonto p) {
    return p.y;
}

tPonto MovePonto(tPonto pontoInicial, int deltaX, int deltaY) {
    pontoInicial.x += deltaX;
    pontoInicial.y += deltaY;

    return pontoInicial;
}

float DistanciaEntre2Pontos(tPonto p1, tPonto p2) {

}

int QuadranteDoPonto(tPonto p) {
    if (p.x > 0 && p.y > 0) return 1;
    if (p.x < 0 && p.y > 0) return 2;
    if (p.x < 0 && p.y < 0) return 3;
    if (p.x > 0 && p.y < 0) return 4;
    return 0;
}

tPonto CimetricoPonto(tPonto p) {
    p.x = -(p.x);
    p.y = -(p.y);

    return p;
}
