#include <stdio.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

void cadastrar_produto(Produto *produto) {
    printf("Nome do produto: ");
    scanf("%s", produto->nome);
    printf("Preço do produto: ");
    scanf("%f", &produto->preco);
    printf("Quantidade em estoque: ");
    scanf("%d", &produto->quantidade);
}

void exibir_produto(Produto produto) {
    printf("Nome: %s\n", produto.nome);
    printf("Preço: %.2f\n", produto.preco);
    printf("Quantidade: %d\n", produto.quantidade);
}

float calcular_valor_total(Produto produto) {
    return produto.preco * produto.quantidade;
}

int main() {
    Produto produto;
    cadastrar_produto(&produto);
    exibir_produto(produto);
    float valor_total = calcular_valor_total(produto);
    printf("Valor total em estoque: %.2f\n", valor_total);
    return 0;
}
