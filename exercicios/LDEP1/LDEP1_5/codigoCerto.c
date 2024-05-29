#include <stdio.h>

int main(){
	int a = 0, b = 0 , den = 1, i = 0, mdc = 0, mmc = 0, limMDC = 0 , limMMC = 0;

	scanf("%d %d", &a, &b);

	//Acha limites da busca
	if (a < b){ 
		limMDC = a;
		limMMC = b;
	} else {
		limMDC = b;
		limMMC = a;
	}
	
	//MDC
	for(den=1; den <= limMDC; den++){   
		if(!(a % den) && !(b % den)){ 
            if (mdc < den){
                mdc = den;
            }
		}
	}
	
	//MMC
	i = limMMC;
	while(!(mmc)){
		if(!(i%a) && !(i%b)){
			mmc = i;
			break;
        }
		i++;
	}

    printf("%d %d", mdc, mmc);

	return 0;
}
