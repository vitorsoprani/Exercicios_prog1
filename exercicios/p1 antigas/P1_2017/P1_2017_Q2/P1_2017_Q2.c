#include <stdio.h>
#define INVALIDO    0
#define HOMEM       1
#define MULHER      2

int DefineGenero(int id);

int main() {
    int id1, id2;
    int genero1 = 0, genero2 = 0;

    scanf("%d %d", &id1, &id2);
    genero1 = DefineGenero(id1);
    genero2 = DefineGenero(id2);

    if (genero1 == INVALIDO || genero2 == INVALIDO) {
        printf("Invalido");
    } else if (genero1 == genero2) {
        if (genero1 == HOMEM && id1 != id2) printf("Par de homens");
        else if (genero1 == HOMEM && id1 == id2) printf("Um homem");
        else if (genero1 == MULHER && id1 != id2) printf("Par de mulheres");
        else if (genero1 == MULHER && id1 == id2) printf("Uma mulher");
    } else if (genero1 != genero2) {
        printf("Um casal");
    }

    return 0;
}

int DefineGenero(int id) {
    if (id >= 1 && id <= 5) return HOMEM;
    else if (id >= 6 && id <= 10) return MULHER;
    else return INVALIDO;
}