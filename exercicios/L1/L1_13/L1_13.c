#include <stdio.h>

int main(){
    int pessoas = 0, itens = 0, ultimaPessoa = 0;

    scanf("%d %d", &pessoas, &itens);
    ultimaPessoa = itens % pessoas;
    if (ultimaPessoa == 0) {
        ultimaPessoa = pessoas;
    }
    printf("RESP:%d", ultimaPessoa);

    return 0;
}