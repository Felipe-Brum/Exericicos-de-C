#include <stdio.h>

int main() {
    int n, sum = 0;
    printf("Digite o número de elementos: ");
    scanf("%d", &n);

    int array[n];
    printf("Digite os elementos:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        sum += array[i];
    }

    printf("A soma dos elementos é: %d\n", sum);
    return 0;
}
