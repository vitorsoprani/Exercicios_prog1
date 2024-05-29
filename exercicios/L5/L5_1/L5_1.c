#include <stdio.h>
#include <math.h>

int main() {
    int qtdParticipantes, i, maiorNota = 0, menorNota = 150, somatorioNotas = 0;
    int qtdAcimaDaMedia = 0, qtdReprovados = 0;
    scanf("%d", &qtdParticipantes);
    float media, somatorioDesvio = 0, desvioPadrao = 0;
    int notas[qtdParticipantes];

    for (i = 0; i < qtdParticipantes; i++) {
        scanf("%d", &notas[i]);

        if (notas[i] > maiorNota) maiorNota = notas[i];
        if (notas[i] < menorNota) menorNota = notas[i];

        somatorioNotas += notas[i];
    }

    media = ((float) somatorioNotas / (float) qtdParticipantes);

    for (i = 0; i < qtdParticipantes; i++) {
        //armazena o somatório necessário para a fórmula do desvio padrão:
        somatorioDesvio += pow((notas[i] - media), 2);

        //contabiliza os alunos acima e abaixo d média:
        if (notas[i] < 70) qtdReprovados++;
        if (notas[i] > media) qtdAcimaDaMedia++;
    }
    desvioPadrao = sqrt(somatorioDesvio / qtdParticipantes);

    printf("MENOR:%d, MAIOR:%d, MEDIA:%.2f, STD:%.2f, ACIMA_MEDIA_CONC:%d, REPROV:%d",
            menorNota, maiorNota, media, desvioPadrao, qtdAcimaDaMedia, qtdReprovados);
    return 0;
}