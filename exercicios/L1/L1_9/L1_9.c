#include <stdio.h>

int main()
{
    int ascii = 0;

    scanf("%c", &ascii);

    if (97 <= ascii && ascii <= 122)
    {
        printf("%c(%d)", (ascii - 32), (ascii - 32));
    }
    else if (65 <= ascii && ascii <= 90)
    {
        printf("A letra deve ser minuscula!");
    }
    else
    {
        printf("Nao e letra!");
    }

    return 0;
}