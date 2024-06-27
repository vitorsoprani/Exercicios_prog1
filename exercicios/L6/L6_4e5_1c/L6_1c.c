#include <stdio.h>

#define TAM_MAX_MENSAGEM 10 //9 caracteres + o \0
#define MAX_PACOTES_MENSAGEM 100

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

/*Ordena os pacotes levando em conta o id da mensage. caso o id da mensagem seja igual
será levado em conta o id do pacote*/
void OrdenaPacotes(tPacote pacotes[], int qtdPacotes);

/*Dados um indice a e um indice b, essa função retorna o indice do "menor" pacote
 entre eles {incluindo a e b}*/
int IdxMenorEntreAeBPacotes(tPacote pacotes[], int a, int b);

/*Indica se o pacote a é "menor" que o pacote b*/
int EhMenorPacoteAQueB(tPacote a, tPacote b);

/*Dado um vetor de pacotes e dois indices essa função troca os pacotes
 dos respectivos indices entre si*/
void TrocaDeLugarPacotes(tPacote pacotes[], int a, int b);

/*Dados um pacote a e b, essa função indica se o pacote b pertence à mesma mensagem
 que o pacote a*/
int EhDaMesmaMensagemPacotes(tPacote a, tPacote b);

typedef struct {
    int qtdPacotes;
    tPacote pacotes[MAX_PACOTES_MENSAGEM];
} tMensagens;

tMensagens LePacotesMensagens();

tMensagens OrganizaMensagens(tMensagens mensagens);

void ImprimeMensagens(tMensagens mensagens);

int main() {
    
    tMensagens mensagens = LePacotesMensagens();

    mensagens = OrganizaMensagens(mensagens);

    ImprimeMensagens(mensagens);

    return 0;
}

tPacote LePacote() {
    tPacote pct;
    scanf("%3d", &pct.idMensagem);
    scanf("%3d", &pct.idPacote);
    scanf("%1d", &pct.tamMensagem);
    scanf(" ");

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

    scanf("%d", &pct.codigoDeErro);
        
    return pct;
}

void ImprimePacote(tPacote pacote) {
    if (TemErroPacote(pacote)) {
        printf("##FALHA##");
    } else {
        printf("%s", pacote.mensagem);
    }
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

void OrdenaPacotes(tPacote pacotes[], int qtdPacotes) {
    int i;
    int idxAux;
    for (i = 0; i < qtdPacotes - 1; i++) {
        idxAux = IdxMenorEntreAeBPacotes(pacotes, i + 1, qtdPacotes - 1);
        if (EhMenorPacoteAQueB(pacotes[idxAux], pacotes[i])) {
            TrocaDeLugarPacotes(pacotes, i, idxAux);
        }
    }
}

int IdxMenorEntreAeBPacotes(tPacote pacotes[], int a, int b) {
    int idxMenor = a;
    int i;
    for (i = a + 1; i <= b; i++) {
        if (EhMenorPacoteAQueB(pacotes[i], pacotes[idxMenor])) {
            idxMenor = i;
        }
    }

    return idxMenor;
}

int EhMenorPacoteAQueB(tPacote a, tPacote b) {
    if (a.idMensagem == b.idMensagem) {
        return a.idPacote < b.idPacote;
    }

    return a.idMensagem < b.idMensagem;
}

void TrocaDeLugarPacotes(tPacote pacotes[], int a, int b) {
    tPacote aux;

    aux = pacotes[a];
    pacotes[a] = pacotes[b];
    pacotes[b] = aux;
}

int EhDaMesmaMensagemPacotes(tPacote a, tPacote b) {
    return a.idMensagem == b.idMensagem;
}

tMensagens LePacotesMensagens() {
    tMensagens mensagens;
    
    scanf("%d\n", &mensagens.qtdPacotes);

    int i;
    for (i = 0; i < mensagens.qtdPacotes; i++) {
        mensagens.pacotes[i] = LePacote();
    }
    
    return mensagens;
}

tMensagens OrganizaMensagens(tMensagens mensagens) {
    OrdenaPacotes(mensagens.pacotes, mensagens.qtdPacotes);
    
    return mensagens;
}

void ImprimeMensagens(tMensagens mensagens) {
    tPacote pacoteAnterior = mensagens.pacotes[0];
    tPacote pacoteAtual;
    
    ImprimePacote(mensagens.pacotes[0]);
    
    int i;
    for (i = 1; i < mensagens.qtdPacotes; i++) {
        pacoteAtual = mensagens.pacotes[i];
        if (EhDaMesmaMensagemPacotes(pacoteAtual, pacoteAnterior)) {
            ImprimePacote(pacoteAtual);
        } else {
            printf("\n");
            ImprimePacote(pacoteAtual);
        }
        pacoteAnterior = pacoteAtual;
    }
}