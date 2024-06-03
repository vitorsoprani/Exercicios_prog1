#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct{
/*
contem todas as informacoes do pokemon e informacoes que podem ser uteis, como vidaAtual
*/
}Pokemon;

typedef struct{
/*
acopla o pokemon de diogo, do adversario e informacoes que podem ser uteis, como qtdDeAdversarios
*/    
}Ginasio;

float calculaVantagem(Pokemon atacante, Pokemon defensor);
/*
Retorna o valor de vantagem que é 0.5(desvantagem), 1.5(vantagem) ou 1.0(duelo equilibrado) 
*/

int calculaDano(Pokemon atacante, Pokemon defensor);
/*
Dentro da funcao, recebe o valor da vantagem e utiliza a formula dada para calcular a quantidade de dano na vida do oponente
obs: utilizar floor para arrendondar com mais precisao
*/
int estaVivo(Pokemon p);
/*
Verifica se o pokemon esta vivo
retorna 1 caso verdadeiro
retorna 0 caso falso
*/

int menorNivel(Pokemon atacante, Pokemon defensor);
/*
Verifica se o atacante tem menor nivel que o defensor
retorna 1 caso verdadeiro
retorna 0 caso falso
*/

Pokemon subirDeNivel(Pokemon p);
/*
Sobe o nivel do pokemon e atualiza seus status
retorna p atualizado
obs: utilizar floor para arrendondar com mais precisao
*/
Ginasio batalhar(Pokemon atacante, Pokemon defensor, Ginasio ginasio);
/*
funcao que recebe o pokemon atacante, defensor e o ginasio.
Aqui que a batalha eh efetuada
a batalha continua ateh que alguem morra
no final, atribua defensor e atacante ao ginasio
retorna ginasio atualizado
obs1: o pokemon de maior velocidade ataca primeiro
*/
Pokemon lePokemon();
/*
Declara pokemon
Efetua a leitura do pokemon
retorna pokemon
*/
void imprimePokemon(Pokemon p);
/*
Imprime todas as informacoes do pokemon p
*/
Ginasio inicializaGinasio();
/*
Declara ginasio
Faz a leitura do pokemon de diogo, numDeAdversarios e inicializa as outras variaveis
retorna ginasio 
*/
Ginasio RealizaBatalha(Ginasio ginasio);
/*
Recebe o ginasio inicializado e efetua as batalhas ate que diogo venca ou perca
retorna ginasio atualizado
*/
void FinalizaBatalha(Ginasio ginasio);
/*
Imprime todas as informacoes da batalhas, especificadas no enunciado e casos de teste
*/
int main(){
    Ginasio ginasio = inicializaGinasio();
    ginasio = RealizaBatalha(ginasio);
    FinalizaBatalha(ginasio);
    return 0;
}