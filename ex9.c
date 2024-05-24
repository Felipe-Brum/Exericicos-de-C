#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

float calcular_media(int *array, int tamanho) {
    int soma = 0;
    for(int i = 0; i < tamanho; i++) {
        soma += array[i];
    }
    return (float)soma / tamanho;
}

float calcular_mediana(int *array, int tamanho) {
    qsort(array, tamanho, sizeof(int), comparar);
    if(tamanho % 2 == 0) {
        return (array[tamanho/2 - 1] + array[tamanho/2]) / 2.0;
    } else {
        return array[tamanho/2];
    }
}

int calcular_moda(int *array, int tamanho) {
    int max_count = 0, moda = array[0], count = 1;
    for(int i = 1; i < tamanho; i++) {
        if(array[i] == array[i - 1]) {
            count++;
        } else {
            if(count > max_count) {
                max_count = count;
                moda = array[i - 1];
            }
            count = 1;
        }
    }
    return (max_count > 1) ? moda : -1; 
}

int main() {
    int array[] = {1, 2, 2, 3, 4};
    int tamanho = sizeof(array) / sizeof(array[0]);

    float media = calcular_media(array, tamanho);
    float mediana = calcular_mediana(array, tamanho);
    int moda = calcular_moda(array, tamanho);

    printf("Média: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    printf("Moda: %d\n", (moda == -1) ? "Não há moda" : moda);
    
    return 0;
}
