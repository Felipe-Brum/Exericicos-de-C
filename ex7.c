#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int idade;
    float salario;
} Funcionario;

int comparar(const void *a, const void *b) {
    Funcionario *funcA = (Funcionario *)a;
    Funcionario *funcB = (Funcionario *)b;
    return (funcA->idade - funcB->idade);
}

int main() {
    Funcionario funcs[3] = {
        {"João", 25, 2500.50},
        {"Maria", 30, 3000.75},
        {"José", 22, 2200.00}
    };

    int n = 3;

    qsort(funcs, n, sizeof(Funcionario), comparar);

    for(int i = 0; i < n; i++) {
        printf("Nome: %s, Idade: %d, Salário: %.2f\n", funcs[i].nome, funcs[i].idade, funcs[i].salario);
    }

    return 0;
}
