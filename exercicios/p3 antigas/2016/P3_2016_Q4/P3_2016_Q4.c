#include <stdio.h> 

int main() {
    int qtdCasos;
    scanf("%d", &qtdCasos);
    
    int i;
    for (i = 0; i < qtdCasos; i++) {
        int qtdNumeros;
        scanf("%d", &qtdNumeros);
        int numeros[qtdNumeros];
        
        int j;
        for (j = 0; j < qtdNumeros; j++) {
            scanf("%d", &numeros[j]);
        }
        
        for (j = 0; j < qtdNumeros; j++) {
            int soma = 0;
            
            int k;
            for (k = 0; k < qtdNumeros; k++){
                if (numeros[k] > numeros[j]) soma++;
            }
            printf("%d ", soma);
        }
        printf("\n");
    }
    
    return 0;
}