#include <stdio.h>

int main(){
    float num = 0;
    int intNum = 0;

    scanf("%f", &num);
    intNum = (int)num;
    printf("INTEIRO:%d,REAL:%.2f", intNum, num - intNum);
    
    return 0;
}