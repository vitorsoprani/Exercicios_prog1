#include <stdio.h>
#include <math.h>

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
    tPonto pontoAtual, pontoAnterior;

    scanf("%d", &qtdPontos);

    for (i = 1; i <= qtdPontos; i++) {
        pontoAtual = LePonto();
        if (i == 1) {
            printf("-\n");
        } else {
            printf("%.2f\n", DistanciaEntre2Pontos(pontoAtual, pontoAnterior));
        }
        pontoAnterior = pontoAtual;
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
    int deltaX, deltaY;
    float distancia;
    deltaX = p1.x - p2.x;
    deltaY = p1.y - p2.y;

    distancia = sqrt((float) pow(deltaX, 2) + (float) pow(deltaY, 2));
    return distancia;
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
