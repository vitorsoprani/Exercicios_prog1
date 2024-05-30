#include <stdio.h>
#include <math.h>

int main(){
    float a = 0, b = 0, c = 0;
    float delta = 0, x1 = 0, x2 = 0;
    scanf("%f %f %f", &a, &b, &c);

    delta = pow(b, 2)-(4*a*c);

    if (delta){
        if (delta > 0){
    	    x2 = (-b - sqrt(delta))/(2 * a);
	    x1 = (-b + sqrt(delta))/(2 * a);
            printf("Duas raízes reais: %.1f e %.1f\n", x1, x2);
        } else {
            printf("Nenhuma raiz real\n");
        }
    } else {
	x2 = -b / (2 * a);
        printf("Uma raiz real: %.1f\n", x2);
    }
    return 0;
}
