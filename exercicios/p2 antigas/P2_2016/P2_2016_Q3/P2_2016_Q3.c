#include <stdio.h>

int EhProduto(char prd);
int AcabaramOsProdutos(char prd);
int QtdDoProdutoMaisComprado();

int main() {
    int clienteMaisGuloso, qtdPrdMaisComprado = 0;
    
    while (1) {
        int cliente, qtdPrdCliente;
        scanf("%d", &cliente);
        scanf("%*c");

        if (cliente == -1) break;

        qtdPrdCliente = QtdDoProdutoMaisComprado();
        if (qtdPrdCliente > qtdPrdMaisComprado) {
            clienteMaisGuloso = cliente;
            qtdPrdMaisComprado = qtdPrdCliente;
        }
    }
    
    printf("CLIENT:%d QTD:%d", clienteMaisGuloso, qtdPrdMaisComprado);
    return 0;
}

int EhProduto(char prd) {
    return prd >= 'A' && prd <= 'Z';
}

int AcabaramOsProdutos(char prd) {
    return prd == '0';
}

int QtdDoProdutoMaisComprado() {
    char prdAtual = 0, prdAnterior = 1;
    int qtdPrd = 1;
    int qtdMaisComprado = 0;

    while (1) {
        scanf("%c", &prdAtual);
        if (AcabaramOsProdutos(prdAtual)){
            scanf("%*c");
            return qtdMaisComprado;
        }
        
        if (EhProduto(prdAtual)) {
            if (prdAtual == prdAnterior) {
                qtdPrd++;
            } else {
                if (qtdPrd > qtdMaisComprado) {
                    qtdMaisComprado = qtdPrd;
                }
                qtdPrd = 1;
            }
            prdAnterior = prdAtual;
        }
    }
}
