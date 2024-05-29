#include <stdio.h>

int ReduzInteiro(int n);
int MontaSenha(int senha, int dig);
int ReduzCodigo();

int main() {
    int senha = 0, primeiroDigito = 1;
    while (1) {
        char c;
        scanf("%c", &c);

        if (c == '(') {
            int digito;
            digito = ReduzCodigo();
            if (primeiroDigito) {
                if (digito != -1) {
                    digito = ReduzInteiro(digito);
                    printf("[%d]", digito);
                    senha = digito;
                    primeiroDigito = 0;
                } else {
                    printf("[ERRO]");
                }
            } else {
                if (digito != -1) {
                    digito = ReduzInteiro(digito);
                    printf("[%d]", digito);
                    senha = MontaSenha(senha, digito);
                } else {
                    printf("[ERRO]");
                }
            }
        } else {
            printf("%c", c);
        }
        if (c == '.') break;
    }
    printf(" SENHA:%d\n", senha);
    return 0;
}

int ReduzInteiro(int n) {
    int nReduzido = 0;

    while (n) {
        nReduzido += n % 10;
        n /= 10;
    }

    //se nReduzido ainda tem mais que 1 digito;
    if (nReduzido > 9) {
        nReduzido = ReduzInteiro(nReduzido);
    }
    return nReduzido;
}

int MontaSenha(int senha, int dig) {
    return senha * 10 + dig;
}

int ReduzCodigo() {
    int codigoReduzido = 0, flagValido = 0;
    while (1) {
        char c;

        scanf("%c", &c);
        if (c == ')') break;

        codigoReduzido += (int) c - (int) '0';
        
        flagValido = 1;
    }

    if (flagValido) {
        return codigoReduzido;
    } else {
        return -1;
    }
}
