#include <stdio.h>
#include <math.h>

#define PI 3.141592
int main(){
    float raio1 = 0, raio2 = 0, area = 0;

    scanf("%f", &raio1);

    area = PI * pow(raio1, 2);
    raio2 = raio1/sqrt(2);

    printf("%.2f %.2f", area, raio2);

    return 0;
}