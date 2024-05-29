#include <stdio.h>

int main()
{
    int modo = 0, chave = 0;
    char caracter = 0, operando = 1;

    scanf("%d", &modo);
    scanf("%d", &chave);
    scanf("%*c");
    switch (modo)
    {
    case 1:
        while (operando)
        {
            scanf("%c", &caracter);
            if (caracter == '.')
            {
                operando = 0;
            }
            else if (caracter >= 'a' && caracter <= 'z')
            {
                caracter += chave % 26;
                if (caracter > 'z')
                {
                    caracter -= 26;
                }
            }
            printf("%c", caracter);
        }
        break;

    case 2:
        while (operando)
        {
            scanf("%c", &caracter);
            if (caracter == '.')
            {
                operando = 0;
            }
            else if (caracter >= 'a' && caracter <= 'z')
            {
                caracter -= chave % 26;
                if (caracter < 'a')
                {
                    caracter += 26;
                }
            }
            printf("%c", caracter);
        }
        break;

    default:
        printf("Operacao invalida.");
        break;
    }
    return 0;
}