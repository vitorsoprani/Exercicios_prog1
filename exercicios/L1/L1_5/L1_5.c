#include <stdio.h>

int main()
{
    int n1 = 0, n2 = 0;
    scanf("%d %d", &n1, &n2);
    if (n1 > n2)
    {
        printf("N1 = %d", n1);
    }
    else if (n2 > n1)
    {
        printf("N2 = %d", n2);
    }
    else
    {
        printf("N1 = N2");
    }
    return 0;
}