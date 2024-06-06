#include <stdio.h>

int main(int argc, char **argv){

    char fileName[50], name[100], course[100];
    int age=0;
    FILE * file=NULL;

    sprintf(fileName,"%s", argv[1]);
    file = fopen(fileName, "r");

    while(!feof(file)){

        fscanf(file,"%[^;];%d;%[^\n]\n", name, &age, course);
        printf("-> %s tem %d anos e cursa %s\n\n", name, age, course);
    }

    fclose(file);

   return 0;
}