#include <stdio.h>

double LeNotasECalculaMediaAluno();
int ContaAlunosAprovadosTurma();

int main() {
    int turma, qtdTurmas;
    int melhorTurma, aprovadosMelhorTurma = 0;
    int piorTurma, aprovadosPiorTurma = 32000;
    scanf("%d", &qtdTurmas);
    scanf("%*c"); //apaga o \n

    for (turma = 1; turma <= qtdTurmas; turma++) {
        int qtdAprovados = 0;
        printf("TURMA:%d\n", turma);
        
        qtdAprovados = ContaAlunosAprovadosTurma();
        
        if (qtdAprovados > aprovadosMelhorTurma) {
            melhorTurma = turma;
            aprovadosMelhorTurma = qtdAprovados;
        }
        if (qtdAprovados < aprovadosPiorTurma) {
            piorTurma = turma;
            aprovadosPiorTurma = qtdAprovados;
        }
    }

    printf("MAIOR:TURMA %d MENOR:TURMA %d", melhorTurma, piorTurma);
    return 0;
}

double LeNotasECalculaMediaAluno() {
    int notaAtual, somatorioNotas = 0, menorNota = 101, qtdNotas = 0;
    scanf("%*c"); //apaga a abertura de colchetes;

    while (scanf("%d", &notaAtual) == 1) {
        scanf("%*c");// apaga o caracter seguinte (' ' ou ']')
        somatorioNotas += notaAtual;
        qtdNotas++;

        if (notaAtual < menorNota) {
            menorNota = notaAtual;
        }
    }
    scanf("%*c"); //apaga o \n

    if (menorNota != somatorioNotas) {
        return (somatorioNotas - menorNota) / (qtdNotas - 1);
    } else {
        return somatorioNotas;
    }
}

int ContaAlunosAprovadosTurma() {
    int qtdAlunos, qtdAprovados = 0, i;

    scanf("%d", &qtdAlunos);
    scanf("%*c"); //apaga o \n

    for (i = 1; i <= qtdAlunos; i++) {
        double media;
        char nomeAluno;
        scanf("%c", &nomeAluno); //Lê a priimeira letra do nome do aluno
        scanf("%*c"); //apaga o caracter seguinte
        media = LeNotasECalculaMediaAluno();

        if (media >= 70.0) {
            qtdAprovados++;
            printf("%c\n", nomeAluno);
        }
    }
    return qtdAprovados;
}
