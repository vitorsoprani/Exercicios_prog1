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
int ComparaString(char * str1, char * str2);
void ImprimeRepetidos(tCandidato candidatos[], int qtd);

int main() {
    int qtdCand, i = 0;
    scanf("%d", &qtdCand);
    tCandidato candidatos[qtdCand];

    for (i = 0; i < qtdCand; i++) {
        candidatos[i] = LeCandidato();
    }
    
    ImprimeRepetidos(candidatos, qtdCand);
    
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

int ComparaString(char * str1, char * str2) {
    int i = 0;

    while (str1[i] && str2[i]) {
        if (str1[i] != str2[i]) return 0;
        i++;
    }

    if (str1[i] || str2[i]) return 0;

    return 1;
}

void ImprimeRepetidos(tCandidato candidatos[], int qtd) {
    int i, j;
    int impressos[qtd]; //vetor para verificar quais candidatos ja foram impresssos
    
    for (i = 0; i < qtd; i ++) impressos[i] = 0; //inicializando todos os valore4s como 0
    
    for (i = 0; i < qtd; i++) {
        for (j = i + 1; j < qtd; j++) {
            if (ComparaString(candidatos[i].sobrenome, candidatos[j].sobrenome)) {
                if (!impressos[i]) {
                    ImprimeCandidato(candidatos[i]);
                    impressos[i] = !impressos[i];
                }
                if (!impressos[j]) {
                    ImprimeCandidato(candidatos[j]);
                    impressos[j] = !impressos[j];
                }
            }
        }
    }
}