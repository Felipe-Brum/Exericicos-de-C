#include <stdio.h>
#include <stdlib.h>

int* inverter_array(int *array, int tamanho) {
    int *invertido = (int *)malloc(tamanho * sizeof(int));
    for(int i = 0; i < tamanho; i++) {
        invertido[i] = array[tamanho - 1 - i];
    }
    return invertido;
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(array) / sizeof(array[0]);

    int *invertido = inverter_array(array, tamanho);

    printf("Array invertido: ");
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", invertido[i]);
    }
    printf("\n");

    free(invertido);
    return 0;
}
