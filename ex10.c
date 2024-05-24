#include <stdio.h>
#include <time.h>

int main() {
    clock_t inicio, fim;
    double tempo_gasto;

    inicio = clock();

    for(long i = 0; i < 100000000; i++);

    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("O tempo de execução é: %f segundos\n", tempo_gasto);
    return 0;
}
