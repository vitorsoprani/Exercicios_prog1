#include <stdio.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} tPonto;

typedef struct {
    tPonto pi;
    tPonto pf;
} tReta;

tReta InicializaReta(tPonto pi, tPonto pf);
tReta LeReta();
void ImprimeReta(tReta);
tPonto PontoInicialReta(tReta);
tPonto PontoFinalReta(tReta);
tReta MovimentaReta();
float TamanhoDaReta(tReta);

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
    int qtdLeituras, i;
    scanf("%d", &qtdLeituras);

    for (i = 1; i <= qtdLeituras; i++) {
        tPonto ponto = LePonto();
        tReta reta = LeReta();
        float distanciaPontoPi, distanciaPontoPf;
        
        distanciaPontoPi = DistanciaEntre2Pontos(ponto, PontoInicialReta(reta));
        distanciaPontoPf = DistanciaEntre2Pontos(ponto, PontoFinalReta(reta));
        
        if (distanciaPontoPi < distanciaPontoPf) {
            printf("INICIO\n");
        } else if (distanciaPontoPi > distanciaPontoPf) {
            printf("FIM\n");
        } else {
            printf("EQUIDISTANTE\n");
        }
    }
    return 0;
}

tPonto InicializaPonto(int x, int y) {
    tPonto p = {x, y};
    return p;
}

tPonto LePonto() {
    int x, y;
    scanf("%d%d", &x, &y);

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

tReta InicializaReta(tPonto pi, tPonto pf) {
    tReta reta = {pi, pf};
    return reta;
}

tReta LeReta() {
    tPonto pi, pf;
    pi = LePonto();
    pf = LePonto();

    return InicializaReta(pi, pf);
}

void ImprimeReta(tReta reta) {
    printf("[(%d,%d):(%d,%d)]", reta.pi.x, reta.pi.y, reta.pf.x, reta.pf.y);
}

tPonto PontoInicialReta(tReta reta) {
    return reta.pi;
}

tPonto PontoFinalReta(tReta reta) {
    return reta.pf;
}

tReta MovimentaReta() {
}

float TamanhoDaReta(tReta reta) {
    return DistanciaEntre2Pontos(reta.pi, reta.pf);
}
