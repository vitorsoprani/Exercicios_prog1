#include <stdio.h>

#define MAX_CARROS 100
#define MAX_CARACTERES_TIPO 101 //100 + o \0

typedef struct {
    int id;
    int qtdPassageiros;
    char tipo[MAX_CARACTERES_TIPO];
    int quilometragem;
} tCarro;

tCarro LeCarro();

void ImprimeCarro(tCarro carro);

int ObtemNumPassageirosCarro(tCarro carro);

int ObtemKmCarro(tCarro carro);

typedef struct {
    int qtdCarros;
    tCarro carros[MAX_CARROS];
} tConcessionaria;

tConcessionaria LeCarrosConcessionaria();

void ListaCarrosConcessionaria(tConcessionaria concessionaria, int pass, int km);

int main() {
    tConcessionaria concessionaria;

    concessionaria = LeCarrosConcessionaria();

    int qtdPassageiros, km, i = 0;
    while (scanf("%d,%d", &qtdPassageiros, &km) == 2) {
        printf("Caso %d:\n", ++i);
        ListaCarrosConcessionaria(concessionaria, qtdPassageiros, km);
    }

    return 0;
}

tCarro LeCarro() {
    tCarro c;
    scanf("%d %d %s %d\n", &c.id, &c.qtdPassageiros, c.tipo, &c.quilometragem);
//    ImprimeCarro(c);
    return c;
}

void ImprimeCarro(tCarro carro) {
    printf("CARRO (%d): ", carro.id);
    printf("%s de %d passageiros ", carro.tipo, carro.qtdPassageiros);
    printf("e com %d km\n", carro.quilometragem);
}

int ObtemNumPassageirosCarro(tCarro carro) {
    return carro.qtdPassageiros;
}

int ObtemKmCarro(tCarro carro) {
    return carro.quilometragem;
}

tConcessionaria LeCarrosConcessionaria() {
    tConcessionaria concessionaria;
    scanf("%d\n", &concessionaria.qtdCarros);
    
    int i;
    for (i = 0; i < concessionaria.qtdCarros; i++) {
        concessionaria.carros[i] = LeCarro();
    }
    
    return concessionaria;
}

void ListaCarrosConcessionaria(tConcessionaria concessionaria, int pass, int km) {
//    printf("Listando carros\n");
    int i;
    for (i = 0; i < concessionaria.qtdCarros; i++) {
//        printf("DentroDoFor\n");
        if (ObtemNumPassageirosCarro(concessionaria.carros[i]) == pass || pass == -1) {
            if (ObtemKmCarro(concessionaria.carros[i]) <= km || km == -1) {
                ImprimeCarro(concessionaria.carros[i]);
            } else {
//                printf("%d > %d\n", ObtemKmCarro(concessionaria.carros[i]), km);
            }
        } else {
//            printf("%d != %d\n", ObtemNumPassageirosCarro(concessionaria.carros[i]), pass);
        }
    }
}