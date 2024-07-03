#include <stdio.h>

#define MAX_CARROS 100
#define MAX_CARACTERES_TIPO 101 //100 + o \0

typedef struct {
    int id;
    int qtdPassageiros;
    char tipo[MAX_CARACTERES_TIPO];
    int quilometragem;
    int cliente; //indica o cliente que alugou o carro. caso o o cliente seja "-1 significa que o carro está disponível
} tCarro;

tCarro LeCarro();

void ImprimeCarro(tCarro carro);

int ObtemNumPassageirosCarro(tCarro carro);

int ObtemKmCarro(tCarro carro);

int ObtemClienteAlugouCarro(tCarro carro);

int EstaDisponivelCarro(tCarro carro);

tCarro AlugaCarro(tCarro carro, int cliente);

tCarro DevolveCarro(tCarro carro);

int ObtemIdCarro(tCarro carro);

typedef struct {
    int qtdCarros;
    tCarro carros[MAX_CARROS];
} tConcessionaria;

tConcessionaria LeCarrosConcessionaria();

void ListaCarrosConcessionaria(tConcessionaria concessionaria, int pass, int km);

tConcessionaria AlugaCarroConcessionaria(tConcessionaria concessionaria, int cliente, int pass, int km);

tConcessionaria DevolveCarroConcessionaria(tConcessionaria concessionaria, int cliente);

int main() {
    tConcessionaria concessionaria;

    concessionaria = LeCarrosConcessionaria();

    int qtdPassageiros, km, cliente;
    char acao;
    while (scanf("%d,%c\n", &cliente, &acao) == 2) {
        if (acao == 'A') {
            scanf("%d,%d\n", &qtdPassageiros, &km);
            concessionaria = AlugaCarroConcessionaria(concessionaria, cliente, qtdPassageiros, km);
        } else if (acao == 'D') {
            concessionaria = DevolveCarroConcessionaria(concessionaria, cliente);
        }
    }

    return 0;
}

tCarro LeCarro() {
    tCarro c;
    scanf("%d %d %s %d\n", &c.id, &c.qtdPassageiros, c.tipo, &c.quilometragem);
    c.cliente = -1;
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

int ObtemClienteAlugouCarro(tCarro carro) {
    return carro.cliente;
}

int EstaDisponivelCarro(tCarro carro) {
    return carro.cliente == -1;
}

tCarro AlugaCarro(tCarro carro, int cliente) {
    carro.cliente = cliente;
    return carro;
}

tCarro DevolveCarro(tCarro carro) {
    carro.cliente = -1;
    return carro;
}

int ObtemIdCarro(tCarro carro) {
    return carro.id;
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
    int i;
    for (i = 0; i < concessionaria.qtdCarros; i++) {
        if (ObtemNumPassageirosCarro(concessionaria.carros[i]) == pass || pass == -1) {
            if (ObtemKmCarro(concessionaria.carros[i]) <= km || km == -1) {
                ImprimeCarro(concessionaria.carros[i]);
            }
        }
    }
}

tConcessionaria AlugaCarroConcessionaria(tConcessionaria concessionaria, int cliente, int pass, int km) {
    int i;
    int disponivel = 0;
    for (i = 0; i < concessionaria.qtdCarros; i++) {
        if (ObtemNumPassageirosCarro(concessionaria.carros[i]) == pass || pass == -1) {
            if (ObtemKmCarro(concessionaria.carros[i]) <= km || km == -1) {
                if (EstaDisponivelCarro(concessionaria.carros[i])) {
                    concessionaria.carros[i] = AlugaCarro(concessionaria.carros[i], cliente);
                    printf("Alugado (cliente %d) -> ", cliente);
                    ImprimeCarro(concessionaria.carros[i]);
                    disponivel = 1;
                    break;
                }
            }
        }
    }
    if (!disponivel) {
        printf("Carro Indisponivel\n");
    }
    return concessionaria;
}

tConcessionaria DevolveCarroConcessionaria(tConcessionaria concessionaria, int cliente) {
    int i;
    for (i = 0; i < concessionaria.qtdCarros; i++) {
        if (ObtemClienteAlugouCarro(concessionaria.carros[i]) == cliente) {
            concessionaria.carros[i] = DevolveCarro(concessionaria.carros[i]);
            printf("Devolvido (cliente %d) -> ", cliente);
            ImprimeCarro(concessionaria.carros[i]);
        }
    }
    return concessionaria;
}
