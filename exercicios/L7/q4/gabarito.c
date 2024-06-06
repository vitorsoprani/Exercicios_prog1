#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int codigo;
    char nome[16];
    float preco;
    int qtd;
    int qtdVendida;
} tProduto;

tProduto LeProdutos(FILE *produtos);


int main(int argc, char *argv[]){

    FILE *products, *pedidos, *resumo;
    char diretorio[1001];
    int qtdProdutos = 0, i = 0, j = 1, cod = 0, quantidade = 0, x = 0;
    int maiorCliente = 0, maiorQtdVendida = 0, maiorProduto = 0;
    float gasto = 0, maiorGasto = 0;

    sprintf(diretorio, "%s/PRODUTOS.txt", argv[1]);
    products = fopen(diretorio, "r");

    fscanf(products, "%d", &qtdProdutos);
    tProduto produtos[qtdProdutos], maisVendido;

    while(i < qtdProdutos){
        produtos[i] = LeProdutos(products);
        i++;
    }

    while(x < qtdProdutos){
        produtos[x].qtdVendida = 0;
        x++;
    }

    sprintf(diretorio, "%s/PEDIDOS.txt", argv[1]);
    pedidos = fopen(diretorio, "r");

    sprintf(diretorio, "%s/RESUMO.txt", argv[2]);
    resumo = fopen(diretorio, "w");

    fprintf(resumo, "CLIENTE %d\n", j);
    while(!feof(pedidos)){

        fscanf(pedidos, "%d", &cod);

        if(cod == 0){
            if(gasto > maiorGasto){
                maiorGasto = gasto;
                maiorCliente = j;
            }
            gasto = 0;
            j++;
            fprintf(resumo, "\nCLIENTE %d\n", j);
            continue;
        } else if(cod == -1){
            if(gasto > maiorGasto){
                maiorGasto = gasto;
                maiorCliente = j;
            }
            break;
        } else{
            fscanf(pedidos, "%d", &quantidade);
        }

        x = 0;
        while(x < qtdProdutos){
            if(produtos[x].codigo == cod){
                if(produtos[x].qtd >= quantidade){
                    fprintf(resumo, "Gastou %.2f reais comprando %s.\n", (produtos[x].preco*quantidade), produtos[x].nome);
                    produtos[x].qtd = produtos[x].qtd - quantidade;
                    gasto = gasto + (produtos[x].preco*quantidade);
                    produtos[x].qtdVendida = produtos[x].qtdVendida + quantidade;
                } else{
                    fprintf(resumo, "Não temos a quantidade suficiente de %s no estoque.\n", produtos[x].nome);
                }
                break;
            }
            x++;
        }
    }

    x = 0;
    while(x < qtdProdutos){
        if(produtos[x].qtdVendida > maiorQtdVendida){
            maiorQtdVendida = produtos[x].qtdVendida;
            maiorProduto = x;
        }
        x++;
    }
    

    fprintf(resumo, "\nO cliente %d gastou %.2f reais\n", maiorCliente, maiorGasto);
    fprintf(resumo, "O produto mais vendido foi: %s", produtos[maiorProduto].nome);

    fclose(products);
    fclose(pedidos);
    fclose(resumo);

    return 0;
}

tProduto LeProdutos(FILE *products){

    tProduto prod;

    fscanf(products, "%d", &prod.codigo);
    fscanf(products, "%s", prod.nome);
    fscanf(products, "%f", &prod.preco);
    fscanf(products, "%d", &prod.qtd);

    return prod;
}