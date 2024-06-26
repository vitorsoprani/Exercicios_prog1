#include <stdio.h>

#define TAM_MAX_MENSAGEM 10 //9 caracteres + o \0

typedef struct {
    int idMensagem; //3 digitos
    int idPacote; //3 digitos
    int tamMensagem; //1 digitos
    char mensagem[TAM_MAX_MENSAGEM]; //sempre 9 caracteres, podendo alguns deles serem lixo
    int codigoDeErro; //4 digitos
} tPacote;

tPacote LePacote();

void ImprimePacote(tPacote pacote);

int TemErroPacote(tPacote pct);

int main() {
    int qtdPacotes;
    scanf("%d\n", &qtdPacotes);
    tPacote pacotes[qtdPacotes];

    int i;
    for (i = 0; i < qtdPacotes; i++) {
        pacotes[i] = LePacote();
    }

    for (i = 0; i < qtdPacotes; i++) {
        if (TemErroPacote(pacotes[i])) {
            printf("FALHA!");
        } else {
            ImprimePacote(pacotes[i]);
        }
        printf("\n");
    }

    return 0;
}

tPacote LePacote() {
    tPacote pct;
    scanf("%d ", &pct.idMensagem);
    scanf("%d ", &pct.idPacote);
    scanf("%1d", &pct.tamMensagem);

    int i;
    /*Le a qyantidade de caracteres especificada.*/
    for (i = 0; i < pct.tamMensagem; i++) {
        scanf("%c", &pct.mensagem[i]);
    }

    /*Adciciona p \0 no  final para transformaar em string.*/
    pct.mensagem[pct.tamMensagem] = '\0';

    /*Apaga os demais caracteres (lixo)*/
    for (i = 1; i <= 9 - pct.tamMensagem; i++) {
        scanf("%*c");
    }

    scanf("%d\n", &pct.codigoDeErro);

    return pct;
}

void ImprimePacote(tPacote pacote) {
    printf("PCT: ");
    printf("%d,%d,%d,", pacote.idMensagem, pacote.idPacote, pacote.tamMensagem);
    printf("%s,%d", pacote.mensagem, pacote.codigoDeErro);
}

int TemErroPacote(tPacote pct) {
    int soma = 0;
    soma += pct.idMensagem;
    soma += pct.idPacote;
    soma += pct.tamMensagem;

    int i = 0;
    while (pct.mensagem[i]) {
        soma += (int) pct.mensagem[i];
        i++;
    }

    return soma != pct.codigoDeErro;
}
