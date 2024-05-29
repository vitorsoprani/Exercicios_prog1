#include <stdio.h>
#include <math.h>

float Modulo(float numero);

int main(){
	float n = 0;
	scanf("%f", &n);
	n = Modulo(7-n);
	printf("%.2f", n);
	return 0;
}

float Modulo(float numero){
	return sqrt(pow(numero, 2));
}
