#include <stdio.h>

int main()
  int i=0, den=0, primo=0, qtd=0, cont=0;

  scanf("%d", &qtd);

  for(i=2; i<qtd; i++){
    while(den < i){
      if(i%den==0){
        cont++;
      }
    }
    if(cont==2)
      printf("%d\n", i);
  }

  return 0;
