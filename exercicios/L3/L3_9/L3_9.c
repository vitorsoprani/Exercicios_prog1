#include <stdio.h>
#include <math.h>
#define NEUTRO 0
#define ACIDO 1
#define BASICO 2

float Modulo(float numero);
int VerificaPH(float pH);
int VerificaGotaChuvaAcida(float pH);
float Porcentagem(float total, float valor);
void ImprimeResultadosAnalise(
        float porcentagemGotasChuvaAcida,
        float porcentagemGotasChuvaNormal);

int main() {
    int area = 0, densidade = 0, tempo = 0;
    int totalGotas = 0, gotasNeutras = 0, gotasAcidas = 0, gotasBasicas = 0;
    int gotasChuvaAcida = 0, gotasChuvaNormal = 0;
    int i;
    float pHMaisAcido = 15.00, pHMaisNeutro = 15.00, pHMaisBasico = -1.00;
    float porcentagemGotasChuvaAcida = 0, porcentagemGotasChuvaNormal = 0;

    scanf("%d %d %d", &area, &densidade, &tempo);
    totalGotas = area * densidade * tempo;

    for (i = 1; i <= totalGotas; i++) {
        int condicao;
        float pH;

        scanf("%f", &pH);

        if (pH < pHMaisAcido) pHMaisAcido = pH;
        if (pH > pHMaisBasico) pHMaisBasico = pH;
        if (Modulo(7 - pH) < Modulo(7 - pHMaisNeutro)) pHMaisNeutro = pH;

        condicao = VerificaPH(pH);

        if (condicao == NEUTRO) {
            gotasNeutras++;
            gotasChuvaNormal++;

        } else if (condicao == ACIDO) {
            gotasAcidas++;
            if (VerificaGotaChuvaAcida(pH)) {
                gotasChuvaAcida++;
            } else {
                gotasChuvaNormal++;
            }

        } else if (condicao == BASICO) {
            gotasBasicas++;
            gotasChuvaNormal++;
        } //end if - else if
    }//end for

    if (totalGotas) { //roda esse bloco caso alguma gota tenha sido avaliada
        porcentagemGotasChuvaAcida = Porcentagem(totalGotas, gotasChuvaAcida);
        porcentagemGotasChuvaNormal = Porcentagem(totalGotas, gotasChuvaNormal);

        printf("%d %d %d ", gotasAcidas, gotasBasicas, gotasNeutras);
        printf("%.2f %.2f %.2f\n", pHMaisAcido, pHMaisBasico, pHMaisNeutro);
        ImprimeResultadosAnalise(
                porcentagemGotasChuvaAcida,
                porcentagemGotasChuvaNormal);
    } else {
        printf("Nenhuma gota foi avaliada");
    }
    return 0;
}

float Modulo(float numero) {
    return sqrt(pow(numero, 2));
}

int VerificaPH(float pH) {
    if (pH == 7.00) {
        return 0;
    } else if (pH < 7.00) {
        return 1;
    } else if (pH > 7.00) {
        return 2;
    }
}

int VerificaGotaChuvaAcida(float pH) {
    return pH < 5.70;
}

float Porcentagem(float total, float valor) {
    return (valor * 100) / total;
}

void ImprimeResultadosAnalise(
        float porcentagemGotasChuvaAcida,
        float porcentagemGotasChuvaNormal) {
    if (porcentagemGotasChuvaAcida > 75.00) {
        printf("Chuva Acida ");
    } else if (porcentagemGotasChuvaNormal > 75.00) {
        printf("Chuva Normal ");
    } else {
        printf("Chuva com indicios de chuva acida ");
    }
    printf("%.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
}