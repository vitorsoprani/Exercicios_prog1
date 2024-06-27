#include <stdio.h>

#define QTD_MAX_CARACTERES 400

/*Dados a palavra alvo e a palavra fonte, esta função analisa o caso e imprime o 
 resultado na saída padrão*/
void AnalisaCaso(char alvo[], char fonte[]);

/*Checa se duas letras são iguais (desconsiderando se a letra é maiuscula ou nao)*/
int EhIgualLetra(char l1, char l2);

/*Retorna a letra maiuscula*/
char TransformaMaiuscula(char c);

int main() {
    int qtdCasos;
    scanf("%d\n", &qtdCasos);
    
    char alvo[QTD_MAX_CARACTERES];
    char fonte[QTD_MAX_CARACTERES];
    
    int i;
    for (int i = 0; i < qtdCasos; i++) {
        scanf("%s %s\n", alvo, fonte);
        AnalisaCaso(alvo, fonte);
    }
    
    return 0;
}

void AnalisaCaso(char alvo[], char fonte[]) {
    int i = 0, j;
    
    for (j = 0; fonte[j] != 0; j++) {
        if(alvo[i] == 0) break;
        if (EhIgualLetra(alvo[i], fonte[j])) {
            i++;
        }
    }
    
    if (alvo[i] != 0) {
        printf("NAO PODE!\n");
    } else {
        printf("PODE!\n");
    }
}

int EhIgualLetra(char l1, char l2) {
    return TransformaMaiuscula(l1) == TransformaMaiuscula(l2);
}

char TransformaMaiuscula(char c) {
    if ('A'<= c && c <= 'Z') return c;
    
    return (char)((int)c + ((int)'A' - (int)'a'));
}