#include <stdio.h>

int main(){
    int numeroAtual = 0, maiorNumero = 0, soma = 0, cont = 0 , running = 1;
    float media = 0;

    while(running){
        scanf("%d", &numeroAtual);

        if(!numeroAtual){
            running = 0;
        } else {
            if (maiorNumero < numeroAtual){
                maiorNumero = numeroAtual;
            }

            soma += numeroAtual;
            cont ++;
            media = ((float)soma)/cont;

            printf("%d %.6f\n", maiorNumero, media);
        }

    }
    return 0;
}