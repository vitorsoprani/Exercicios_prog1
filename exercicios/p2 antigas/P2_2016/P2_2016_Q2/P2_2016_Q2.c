#include <stdio.h>

int EhPrimo(int num);
int MaiorDigitoPrimo(int num);

int main() {
    int soma = 0, numero;
    
    while(scanf("%d", &numero) == 1){
        soma += MaiorDigitoPrimo(numero);
    }
    printf("SOMA:%d", soma);
    return 0;
}

int EhPrimo(int num) {
    int i;
    for (i = 2; i <= num / 2; i++) {
        if (!(num % i)) {
            return 0;
        }
    }
    return num > 1;
}

int MaiorDigitoPrimo(int num) {
    int maiorPrimo = 0;

    while (num) {
        int digito;
        digito = num % 10;
        num /= 10;
        if (EhPrimo(digito)) {
            if (digito > maiorPrimo) maiorPrimo = digito;
        }
    }
    
    return maiorPrimo;
}
