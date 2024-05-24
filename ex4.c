#include <stdio.h>
#include <stdlib.h>

void multiplicar_matrizes(int **A, int **B, int **C, int m, int n, int p) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < p; j++) {
            C[i][j] = 0;
            for(int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transpor_matriz(int **A, int **T, int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            T[j][i] = A[i][j];
        }
    }
}

int main() {
    int m = 2, n = 3, p = 2;

    int **A = (int **)malloc(m * sizeof(int *));
    int **B = (int **)malloc(n * sizeof(int *));
    int **C = (int **)malloc(m * sizeof(int *));
    int **T = (int **)malloc(n * sizeof(int *));

    for(int i = 0; i < m; i++) A[i] = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) B[i] = (int *)malloc(p * sizeof(int));
    for(int i = 0; i < m; i++) C[i] = (int *)malloc(p * sizeof(int));
    for(int i = 0; i < n; i++) T[i] = (int *)malloc(m * sizeof(int));

    // Preencher matrizes A e B com valores de exemplo
    printf("Matriz A:\n");
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            A[i][j] = i + j;

    printf("Matriz B:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < p; j++)
            B[i][j] = i - j;

    multiplicar_matrizes(A, B, C, m, n, p);
    printf("Matriz C (resultado da multiplicação A * B):\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < p; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    transpor_matriz(A, T, m, n);
    printf("Matriz T (transposição de A):\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", T[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < m; i++) free(A[i]);
    for(int i = 0; i < n; i++) free(B[i]);
    for(int i = 0; i < m; i++) free(C[i]);
    for(int i = 0; i < n; i++) free(T[i]);

    free(A);
    free(B);
    free(C);
    free(T);

    return 0;
}
