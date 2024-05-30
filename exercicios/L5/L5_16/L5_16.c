#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    char sobrenome[21];
    char nome[21];
    int nota;
    int idade;
} tCandidato;

tCandidato LeCandidato();
void ImprimeCandidato(tCandidato candidato);
void OrdenaCrescente(tCandidato * vet, int qtd);
void TrocaDeLugar(tCandidato *vet, int idx1, int idx2);
int EhMenorQue(tCandidato cand1, tCandidato cand2);
int EncontraMenorEntreAeB(tCandidato *vet, int a, int b);

int main() {
    int qtdCand, i = 0, j;
    scanf("%d", &qtdCand);
    tCandidato candidatos[qtdCand];

    for (i = 0; i < qtdCand; i++) {
        candidatos[i] = LeCandidato();
    }

    OrdenaCrescente(candidatos, qtdCand);

    for (i = qtdCand - 1; i >= 0; i--) {
        ImprimeCandidato(candidatos[i]);
    }

    return 0;
}

tCandidato LeCandidato() {
    tCandidato candidato;
    scanf("%*[^{]");
    scanf("%*[{ ]");
    scanf("%d", &candidato.codigo);
    scanf("%*[, ]");
    scanf("%[^,],", candidato.sobrenome);
    scanf("%*[ ]");
    scanf("%[^,],", candidato.nome);
    scanf("%d", &candidato.nota);
    scanf("%*[, ]");
    scanf("%d", &candidato.idade);
    scanf("%*[^\n]\n");
    return candidato;
}

void ImprimeCandidato(tCandidato candidato) {
    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n",
            candidato.codigo, candidato.nome,
            candidato.sobrenome, candidato.nota, candidato.idade);
}

void OrdenaCrescente(tCandidato * vet, int qtd) {
    int i, idxAux;

    for (i = 0; i < qtd - 1; i++) {
        idxAux = EncontraMenorEntreAeB(vet, i + 1, qtd - 1);

        if (EhMenorQue(vet[idxAux], vet[i])) {
            TrocaDeLugar(vet, i, idxAux);
        }
    }
}

void TrocaDeLugar(tCandidato *vet, int idx1, int idx2) {
    tCandidato aux = vet[idx1];
    vet[idx1] = vet[idx2];
    vet[idx2] = aux;
}

int EhMenorQue(tCandidato cand1, tCandidato cand2) {
    if (cand1.nota < cand2.nota) return 1;

    if (cand1.nota == cand2.nota) {
        if (cand1.idade > cand2.idade) return 1;

        if (cand1.idade == cand2.idade) {
            if (cand1.codigo > cand2.codigo) return 1;
        }
    }

    return 0;
}

int EncontraMenorEntreAeB(tCandidato *vet, int a, int b) {
    int idxMenor = a;
    int i;

    for (i = a + 1; i <= b; i++) {
        if (EhMenorQue(vet[i], vet[idxMenor])) {
            idxMenor = i;
        }
    }

    return idxMenor;
}