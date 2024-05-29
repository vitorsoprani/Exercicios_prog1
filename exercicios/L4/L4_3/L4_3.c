#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} tData;

tData LeData();
tData InicializaData(int dia, int mes, int ano);
void ImprimeData(tData data);
int EhBissextoData(tData data);
int QtdDiasNoMesData(tData data);
tData Avanca1DiaData(tData data);
int EhIgualData(tData data1, tData data2);

int main() {
    int qtdDatas, i;
    scanf("%d", &qtdDatas);

    for (i = 1; i <= qtdDatas; i++) {
        tData data;
        data = LeData();

        ImprimeData(data);

        if (EhBissextoData(data)) printf(":Bisexto\n");
        else printf(":Normal\n");
    }
    return 0;
}

tData LeData() {
    tData data;
    int dia, mes, ano;

    if (scanf("%d%d%d", &dia, &mes, &ano) != 3) {
        printf("ERRO: formato de entrada nao compativel.");
        exit(1);
    }

    data = InicializaData(dia, mes, ano);

    return data;
}

tData InicializaData(int dia, int mes, int ano) {
    tData data;

    data.ano = ano;
    if (mes > 12) data.mes = 12;
    else if (mes < 1) data.mes = 1;
    else data.mes = mes;

    if (dia < 1) data.dia = 1;
    else if (dia > QtdDiasNoMesData(data)) data.dia = QtdDiasNoMesData(data);
    else data.dia = dia;

    return data;
}

void ImprimeData(tData data) {
    printf("'%02d/%02d/%04d'", data.dia, data.mes, data.ano);
}

int EhBissextoData(tData data) {
    if (!(data.ano % 4) && (data.ano % 100)) { //se é divisivel por 4 mas não por 100
        return 1;
    }
    if (!(data.ano % 400)) { //se é divisivel por 400
        return 1;
    }
    return 0;
}

int QtdDiasNoMesData(tData data) { //31 28 31 30 31 30 31 31 30 31 30 31 
    if (data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11) {
        return 30;
    }
    if (data.mes == 2) {
        if (EhBissextoData(data)) {
            return 29;
        } else {
            return 28;
        }
    }
    return 31;
}

tData Avanca1DiaData(tData data) {
    data.dia++;

    if (data.dia > QtdDiasNoMesData(data)) {
        data.dia = 1;
        data.mes++;
    }
    if (data.mes > 12) {
        data.mes = 1;
        data.ano++;
    }

    return data;
}

int EhIgualData(tData data1, tData data2) {
    return data1.dia == data2.dia &&
            data1.mes == data2.mes &&
            data1.ano == data2.ano;
}