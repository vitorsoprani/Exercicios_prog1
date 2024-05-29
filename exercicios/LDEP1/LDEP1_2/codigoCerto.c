#include <stdio.h>
#include <stdlib.h>

int main() {
    int idade = 0;

    scanf("%d", &idade);

    if (idade < 16){
        printf("vc nao pode votar!\n");
    } else if ((idade >= 16 && idade < 18) || idade >= 65){
        printf("vc pode votar, mas nao eh obrigado!\n");
    } else {
        printf("vc eh obrigado a votar!\n");
    }

    return 0;
}
