#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float salario;
} Funcionario;

void adicionar_funcionario(FILE *file) {
    Funcionario func;
    printf("Nome: ");
    scanf("%s", func.nome);
    printf("Idade: ");
    scanf("%d", &func.idade);
    printf("Salário: ");
    scanf("%f", &func.salario);

    fwrite(&func, sizeof(Funcionario), 1, file);
}

void listar_funcionarios(FILE *file) {
    Funcionario func;
    rewind(file);
    while(fread(&func, sizeof(Funcionario), 1, file) == 1) {
        printf("Nome: %s, Idade: %d, Salário: %.2f\n", func.nome, func.idade, func.salario);
    }
}

void buscar_funcionario(FILE *file, char *nome) {
    Funcionario func;
    rewind(file);
    while(fread(&func, sizeof(Funcionario), 1, file) == 1) {
        if(strcmp(func.nome, nome) == 0) {
            printf("Nome: %s, Idade: %d, Salário: %.2f\n", func.nome, func.idade, func.salario);
            return;
        }
    }
    printf("Funcionário não encontrado.\n");
}

int main() {
    FILE *file = fopen("funcionarios.dat", "wb+");
    if(file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int opcao;
    char nome[50];
    do {
        printf("1. Adicionar Funcionário\n2. Listar Funcionários\n3. Buscar Funcionário\n4. Sair\nEscolha uma opção: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                adicionar_funcionario(file);
                break;
            case 2:
                listar_funcionarios(file);
                break;
            case 3:
                printf("Digite o nome do funcionário: ");
                scanf("%s", nome);
                buscar_funcionario(file, nome);
                break;
            case 4:
                fclose(file);
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while(opcao != 4);

    return 0;
}
