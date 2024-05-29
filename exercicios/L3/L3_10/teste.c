#include <stdio.h>

int main(){
	char c = 'a';
	int i = (int)c;
	printf("%d", i);
	i = i+1;
	i = (char)i;
	printf("%c", i);
}
