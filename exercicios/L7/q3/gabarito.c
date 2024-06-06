#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define LOGINNOTFOUND -1
#define WRONGPASSWORD 0

int fazLogin(char *login, char *password);

int main(){
    int n, i=0;
    char login[100], senha[100];
    FILE* saida=fopen("log.txt", "w");
    scanf("%d", &n);
    while(i<n){
        scanf("%s", login);
        scanf("%s", senha);
        switch(fazLogin(login, senha)){
            case SUCCESS:
                fprintf(saida, "Bem vindo, usuario %s\n", login);
                break;
            case LOGINNOTFOUND:
                fprintf(saida, "ERROR! login %s nao existe\n", login);
                break;
            case WRONGPASSWORD:
                fprintf(saida, "Senha incorreta!\n");
                break;
            default:
                break;
        }
        i++;
    }
    fclose(saida);
    return 0;
}

int fazLogin(char *login, char *password){
    char usuario[100], senha[100];
    FILE* entrada = fopen("data.txt", "r");
    while(fscanf(entrada,"%s%s", usuario, senha)!=EOF){
        if(!strcmp(login, usuario)){
            if(!strcmp(password, senha)){
                fclose(entrada);
                return SUCCESS;
            }
            fclose(entrada);
            return WRONGPASSWORD;
        }
    }
    fclose(entrada);
    return LOGINNOTFOUND;
}