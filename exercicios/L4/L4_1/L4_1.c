#include <stdio.h>

typedef struct {
    int codigo;
    int quantidade;
    float preco;
} tProduto;

tProduto LeProduto();
int EhProduto1MaiorQ2(tProduto p1, tProduto p2);
int EhProduto1MenorQ2(tProduto p1, tProduto p2);
int TemProdutoEmEstoque(tProduto p);
void ImprimeProduto(tProduto p);

int main() {
    int qtdProdutos, i;
    tProduto produtoMaisCaro, produtoMaisBarato;
    scanf("%d", &qtdProdutos);

    for (i = 1; i <= qtdProdutos; i++) {
        tProduto produtoAtual = LeProduto();
        if (i == 1) {
            produtoMaisCaro = produtoAtual;
            produtoMaisBarato = produtoAtual;
        } else {
            if (EhProduto1MaiorQ2(produtoAtual, produtoMaisCaro)) {
                produtoMaisCaro = produtoAtual;
            }
            if (EhProduto1MenorQ2(produtoAtual, produtoMaisBarato)) {
                produtoMaisBarato = produtoAtual;
            }
        }

        if (!TemProdutoEmEstoque(produtoAtual)) {
            printf("FALTA:");
            ImprimeProduto(produtoAtual);
        }
    }

    printf("MAIOR:");
    ImprimeProduto(produtoMaisCaro);

    printf("MENOR:");
    ImprimeProduto(produtoMaisBarato);

    return 0;
}

tProduto LeProduto() {
    tProduto p;
    scanf("%d;%f;%d", &p.codigo, &p.preco, &p.quantidade);
    return p;
}

int EhProduto1MaiorQ2(tProduto p1, tProduto p2) {
    return p1.preco > p2.preco;
}

int EhProduto1MenorQ2(tProduto p1, tProduto p2) {
    return p1.preco < p2.preco;
}

int TemProdutoEmEstoque(tProduto p) {
    return p.quantidade > 0;
}

void ImprimeProduto(tProduto p) {
    printf("COD %d, PRE %.2f, QTD %d\n", p.codigo, p.preco, p.quantidade);
}
