#include <stdio.h>
#define MAX 9

typedef struct {
    int idMensagem;
    int idPacote;
    int tamMensagem;
    char mensagem[MAX];
    int codigoDeErro;
} tPacote;

tPacote LePacote();
void ImprimePacote(tPacote pacote);

int main() {
    tPacote pacote;
    pacote = LePacote();
    return 0;
}

tPacote LePacote() {
    tPacote pct;
    scanf("%3d %3d %d %[a-z] %4d", &pct.idMensagem, &pct.idPacote, &pct.tamMensagem, &pct.mensagem, &pct.codigoDeErro);
    return pct;
}

void ImprimePacote(tPacote pacote) {

}