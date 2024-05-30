#include <stdio.h>

int main(){
    int linha = 0, coluna = 0, i = 0, ii;
    char escolha = 0;
    
    while (escolha != 'Q'){
        printf("\nMenu:");
        printf("\nR - Rei");
        printf("\nT - Torre");
        printf("\nQ - Sair");
        printf("\nEscolha uma opcao: ");

        scanf("%c", &escolha);
        scanf("%*[^\n]");
        scanf("%*c");

        switch (escolha){
            case 'Q':
                printf("\n");
                break;

            case 'R':
                printf("\nIndique a coordenada (X,Y):");
                scanf("%d %d", &linha, &coluna);
                scanf("%*[^\n]");
                scanf("%*c");
                printf("\n");

                for (i = 1; i <= 8; i++){
                    for (ii = 1; ii <= 8; ii++){
                        if (((i >= linha - 1) && (i <= linha + 1)) && ((ii >= coluna - 1) && (ii <= coluna + 1))){
                            printf("X ");
                        } else {
                            printf("- ");
                        }
                    }
                    printf("\n");
                }
                break;

            case 'T':
                printf("\nIndique a coordenada (X,Y):");
                scanf("%d %d", &linha, &coluna);
                scanf("%*[^\n]");
                scanf("%*c");
                printf("\n");

                for (i = 1; i <= 8; i++){
                    for(ii = 1; ii <= 8; ii++){
                        if ((i == linha) || (ii == coluna)){
                            printf("X ");
                        } else {
                            printf("- ");
                        }
                    }
                    printf("\n");
                }
                break;
            
            default:
                printf("\nOpcao invalida! Escolha novamente.\n");
        }
    }
    return 0;
}