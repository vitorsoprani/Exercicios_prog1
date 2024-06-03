#include <stdio.h>
#define ESCOVADO 1
#define ARRUMADA 1
#define PREPARADO 1
#define PENDENTE 0

#define ESCOVAR_DENTES 1
#define ARRUMAR_CAMA 2
#define PREPARAR_CAFE 3
#define SAIR_DE_CASA 0

int EscovarDentes(int dentes);
int ArrumarCama(int cama);
int PrepararCafe(int cafe);

int main()
{
    int acao = -1;
    int dentes = PENDENTE, cama = PENDENTE, cafe = PENDENTE;
    while (1)
    {
        scanf("%d", &acao);

        if (acao == ESCOVAR_DENTES)
        {
            dentes = EscovarDentes(dentes);
        }
        else if (acao == ARRUMAR_CAMA)
        {
            cama = ArrumarCama(cama);
        }
        else if (acao == PREPARAR_CAFE)
        {
            cafe = PrepararCafe(cafe);
        }
        else if (acao == SAIR_DE_CASA)
        {
            if (dentes && cama && cafe)
            {
                printf("Saindo de casa!\n");
                break;
            }
            else
            {
                printf("### Ainda ha tarefas pendentes! ###\n");
            }
        }
    }
    return 0;
}

int EscovarDentes(int dentes)
{
    if (dentes == PENDENTE)
    {
        printf("Escovando os dentes!\n");
    }
    else
    {
        printf("Isso ja foi feito!\n");
    }
    return ESCOVADO;
}

int ArrumarCama(int cama)
{
    if (cama == PENDENTE)
    {
        printf("Arrumando a cama!\n");
    }
    else
    {
        printf("Isso ja foi feito!\n");
    }
    return ARRUMADA;
}

int PrepararCafe(int cafe)
{
    if (cafe == PENDENTE)
    {
        printf("Preparando o cafe!\n");
    }
    else
    {
        printf("Isso ja foi feito!\n");
    }
    return PREPARADO;
}