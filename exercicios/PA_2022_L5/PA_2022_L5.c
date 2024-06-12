#include <stdio.h>

typedef struct {
    int x;
    int y;
} tPonto;

int EhIgualPonto(tPonto a, tPonto b); //checa se dois pontos são iguais
tPonto InicializaPonto(int x, int y); //retorna um tPonto com os valores indicados
tPonto LePonto(); //Le um ponto da entrada padrão
tPonto MoveRobo(int c, int l, char placa[l][c], tPonto posicaoRobo, tPonto destino);
//dado a posição atual e o destino do robô, essa função desenha os caracteres do
//trajeto do robô na matriz "placa" e retorna o ponto atual do robo
//(que deve ser o destino)
tPonto MoveHorizontal(int c, int l, char placa[l][c], tPonto posicaoRobo, int deltaX);
tPonto MoveVertical(int c, int l, char placa[l][c], tPonto posicaoRobo,int deltaY);
int Modulo(int x);
void ImprimeMatriz(int c, int l, char matriz[l][c]);
void InicializaMatriz(int c, int l, char matriz[l][c]);

int main() {
    int largura, altura;
    scanf("%d %d", &largura, &altura);
    char placa[altura][largura];
    InicializaMatriz(largura, altura, placa);
    tPonto posicaoRobo, pontoInicial, destino;

    pontoInicial = InicializaPonto(0, 0);
    posicaoRobo = pontoInicial;
    destino = LePonto();

    while (!EhIgualPonto(destino, pontoInicial)) {
        posicaoRobo = MoveRobo(largura, altura, placa, posicaoRobo, destino);
        destino = LePonto();
    }
    posicaoRobo = MoveRobo(largura, altura, placa, posicaoRobo, destino);
    ImprimeMatriz(largura, altura, placa);
    
    return 0;
}

int EhIgualPonto(tPonto a, tPonto b) {
    return a.x == b.x && a.y == b.y;
}

tPonto InicializaPonto(int x, int y) {
    tPonto ponto;
    ponto.x = x;
    ponto.y = y;
    return ponto;
}

tPonto LePonto() {
    tPonto ponto;
    int x, y;
    scanf("%d %d", &x, &y);
    ponto = InicializaPonto(x, y);
    return ponto;
}

tPonto MoveRobo(int c, int l, char placa[l][c], tPonto posicaoRobo, tPonto destino) {
    int deltaX = destino.x - posicaoRobo.x;
    int deltaY = destino.y - posicaoRobo.y;
    
    if (Modulo(deltaY) < Modulo(deltaX)) {
        posicaoRobo = MoveVertical(c, l, placa, posicaoRobo, deltaY);
        posicaoRobo = MoveHorizontal(c, l,placa, posicaoRobo, deltaX);
    } else {
        posicaoRobo = MoveHorizontal(c, l, placa, posicaoRobo, deltaX);
        posicaoRobo = MoveVertical(c, l, placa, posicaoRobo, deltaY);
    }
    
    return posicaoRobo;
}

int Modulo(int x) {
    if (x > 0) return x;
    return - x;
}

void ImprimeMatriz(int c, int l, char matriz[l][c]) {
    int i, j;
    for(i = 0; i < l; i++){
        for (j = 0; j < c; j++){
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

void InicializaMatriz(int c, int l, char matriz[l][c]) {
    int i, j;
    for(i = 0; i < l; i++){
        for (j = 0; j < c; j++){
            matriz[i][j] = '0';
        }
    }
}

tPonto MoveHorizontal(int c, int l, char placa[l][c], tPonto posicaoRobo, int deltaX) {
    int i;
    
    if (deltaX > 0) {
        for (i = 1; i <= deltaX; i++) {
            posicaoRobo.x++;
            placa[posicaoRobo.y][posicaoRobo.x] = '1';
        }
    } else {
        for (i = 1; i <= Modulo(deltaX); i++) {
            posicaoRobo.x--;
            placa[posicaoRobo.y][posicaoRobo.x] = '1';
        }
    }
    
    return posicaoRobo;
}
tPonto MoveVertical(int c, int l, char placa[l][c], tPonto posicaoRobo,int deltaY) {
    int i;
    
    if (deltaY > 0) {
        for (i = 1; i <= deltaY; i++) {
            posicaoRobo.y++;
            placa[posicaoRobo.y][posicaoRobo.x] = '1';
        }
    } else {
        for (i = 1; i <= Modulo(deltaY); i++) {
            posicaoRobo.y--;
            placa[posicaoRobo.y][posicaoRobo.x] = '1';
        }
    }
    
    return posicaoRobo;
}