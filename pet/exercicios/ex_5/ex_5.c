#include <stdio.h>
#include <math.h>
#include <string.h>
#define QTDMAX 10

typedef struct {
    char    nome;
    char    tipo;
    int     nivel;
    int     vidaMaxima;
    int     vidaAtual;
    int     ataque;
    int     defesa;
    int     velocidade;
} Pokemon;

typedef struct {
    /*
    acopla o pokemon de diogo, do adversario e informacoes que podem ser uteis, como qtdDeAdversarios
    */
    Pokemon pokemonDiogo;
    int qtdDeAdversarios;
    int batalhaAtual;
    Pokemon adversarios[QTDMAX];

} Ginasio;

float calculaVantagem(Pokemon atacante, Pokemon defensor);//feito
/*
Retorna o valor de vantagem que é 0.5(desvantagem), 1.5(vantagem) ou 1.0(duelo equilibrado)
*/

int calculaDano(Pokemon atacante, Pokemon defensor);//feito
/*
Dentro da funcao, recebe o valor da vantagem e utiliza a formula dada para calcular a quantidade de dano na vida do oponente
obs: utilizar floor para arrendondar com mais precisao
*/
int estaVivo(Pokemon p); //feito
/*
Verifica se o pokemon esta vivo
retorna 1 caso verdadeiro
retorna 0 caso falso
*/

int menorNivel(Pokemon atacante, Pokemon defensor);//feito
/*
Verifica se o atacante tem menor nivel que o defensor
retorna 1 caso verdadeiro
retorna 0 caso falso
*/

Pokemon subirDeNivel(Pokemon p);//feito
/*
Sobe o nivel do pokemon e atualiza seus status
retorna p atualizado
obs: utilizar floor para arrendondar com mais precisao
*/
Ginasio batalhar(Pokemon atacante, Pokemon defensor, Ginasio ginasio);//feito
/*
funcao que recebe o pokemon atacante, defensor e o ginasio.
Aqui que a batalha eh efetuada
a batalha continua ateh que alguem morra
no final, atribua defensor e atacante ao ginasio
retorna ginasio atualizado
obs1: o pokemon de maior velocidade ataca primeiro
*/
Pokemon lePokemon(); //feito
/*
Declara pokemon
Efetua a leitura do pokemon
retorna pokemon
*/
void imprimePokemon(Pokemon p); //feito
/*
Imprime todas as informacoes do pokemon p
*/
Ginasio inicializaGinasio(); //feito
/*
Declara ginasio
Faz a leitura do pokemon de diogo, numDeAdversarios e inicializa as outras variaveis
retorna ginasio
*/

Ginasio RealizaBatalha(Ginasio ginasio); //feito
/*
Recebe o ginasio inicializado e efetua as batalhas ate que diogo venca ou perca
retorna ginasio atualizado
*/
void FinalizaBatalha(Ginasio ginasio);
/*
Imprime todas as informacoes da batalhas, especificadas no enunciado e casos de teste
*/

int main() {
    Ginasio ginasio = inicializaGinasio(); //ok
    ginasio = RealizaBatalha(ginasio);
    FinalizaBatalha(ginasio);//ok
    return 0;
}

float calculaVantagem(Pokemon atacante, Pokemon defensor) {
    switch (atacante.tipo) {
    case 'W':
        if (defensor.tipo == 'F' || defensor.tipo == 'R' || defensor.tipo == 'G') {
            return 1.5;
        } else if (defensor.tipo == 'E' || defensor.tipo == 'P') {
            return 0.5;
        } else {
            return 1;
        }
        break;
    case 'F':
        if (defensor.tipo == 'P') {
            return 1.5;
        } else if (defensor.tipo == 'W' || defensor.tipo == 'G' || defensor.tipo == 'R') {
            return 0.5;
        } else {
            return 1;
        }
        break;
    case 'P':
        if (defensor.tipo == 'W' || defensor.tipo == 'G' || defensor.tipo == 'R') {
            return 1.5;
        } else if (defensor.tipo == 'F') {
            return 0.5;
        } else {
            return 1;
        }
        break;
    case 'G':
        if (defensor.tipo == 'F' || defensor.tipo == 'E' || defensor.tipo == 'R') {
            return 1.5;
        } else if (defensor.tipo == 'W' || defensor.tipo == 'P') {
            return 0.5;
        } else {
            return 1;
        }
        break;
    case 'E':
        if (defensor.tipo == 'W') {
            return 1.5;
        } else if (defensor.tipo == 'G') {
            return 0.5;
        } else {
            return 1;
        }
        break;
    case 'R':
        if (defensor.tipo == 'F') {
            return 1.5;
        } else if (defensor.tipo == 'W' || defensor.tipo == 'P' || defensor.tipo == 'G') {
            return 0.5;
        } else {
            return 1;
        }
        break;
    }
}

int calculaDano(Pokemon atacante, Pokemon defensor) {
    int dano;
    int nivel = atacante.nivel;
    int def = defensor.defesa;
    int adv = calculaVantagem(atacante, defensor);

    dano = floor((((0.4 * nivel + 2) * (def)) + 2) * adv);

    return dano;
}

int estaVivo(Pokemon p) {
    return p.vidaAtual > 0;
}

int menorNivel(Pokemon atacante, Pokemon defensor) {
    return atacante.nivel < defensor.nivel;
}

Pokemon subirDeNivel(Pokemon p) {
    p.ataque += floor(p.ataque * 0.1);
    p.defesa += floor(p.defesa * 0.1);
    p.velocidade += floor(p.velocidade * 0.1);
    p.vidaMaxima += floor(p.vidaAtual * 0.1);
    p.vidaAtual = p.vidaMaxima;
    p.nivel++;

    return p;
}

Ginasio batalhar(Pokemon atacante, Pokemon defensor, Ginasio ginasio) {
    int vezDoAtacante;
    vezDoAtacante = atacante.velocidade > defensor.velocidade;

    while (1) {
        if (vezDoAtacante) {
            defensor.vidaAtual -= calculaDano(atacante, defensor);

            if (!estaVivo(defensor)) {
                if (menorNivel(atacante, defensor)) {
                    atacante = subirDeNivel(atacante);
                }
                break;
            }

            vezDoAtacante = !vezDoAtacante;
        } else {
            atacante.vidaAtual -= calculaDano(defensor, atacante);

            if (!estaVivo(atacante)) {
                break;
            }

            vezDoAtacante = !vezDoAtacante;
        }
    }

    ginasio.pokemonDiogo = atacante;
    ginasio.adversarios[ginasio.batalhaAtual] = defensor;
    ginasio.batalhaAtual++;

    return ginasio;
}

Pokemon lePokemon() {
    Pokemon pokemon;

    scanf("%c\n", &pokemon.nome);
    scanf("%c\n", &pokemon.tipo);
    scanf("%d\n", &pokemon.nivel);
    scanf("%d\n", &pokemon.vidaMaxima);
    pokemon.vidaAtual = pokemon.vidaMaxima;
    scanf("%d\n", &pokemon.ataque);
    scanf("%d\n", &pokemon.defesa);
    scanf("%d", &pokemon.velocidade);

    return pokemon;
}

void imprimePokemon(Pokemon p) {
    printf("Nome: %c\n", p.nome);
    printf("Tipo: %c\n", p.tipo);
    printf("Nivel: %d\n", p.nivel);
    printf("VidaMax: %d\n", p.vidaMaxima);
    printf("VidaAtual: %d\n", p.vidaAtual);
    printf("Ataque: %d\n", p.ataque);
    printf("Defesa: %d\n", p.defesa);
    printf("Velocidade: %d\n", p.velocidade);
}

Ginasio inicializaGinasio() {
    Ginasio ginasio;
    int i;

    scanf("%d\n", &ginasio.qtdDeAdversarios);
    ginasio.pokemonDiogo = lePokemon();
    ginasio.batalhaAtual = 0;

    for (i = 0; i < ginasio.qtdDeAdversarios; i++) {
        scanf("%*c"); //apaga o \n que sobrou
        ginasio.adversarios[i] = lePokemon(0);
    }

    return ginasio;
}

Ginasio RealizaBatalha(Ginasio ginasio) {
    int i = 0;
    while (estaVivo(ginasio.pokemonDiogo) && i < ginasio.qtdDeAdversarios) {
        ginasio = batalhar(ginasio.pokemonDiogo, ginasio.adversarios[i], ginasio);
        i++;
    }
    return ginasio;
}

void FinalizaBatalha(Ginasio ginasio) {
    if (estaVivo(ginasio.pokemonDiogo)) {
        printf("Diogo venceu todas as %d batalhas!\n", ginasio.batalhaAtual);
        printf("Pokemon de Diogo:\n");
        imprimePokemon(ginasio.pokemonDiogo);
    } else {
        printf("Diogo perdeu na %d batalha\n", ginasio.batalhaAtual);
        printf("Ultimo Pokemon adversario:\n");
        imprimePokemon(ginasio.adversarios[ginasio.batalhaAtual]);
    }
}