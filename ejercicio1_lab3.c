#include <stdio.h>

// Funcion que imprime una matriz de tamaño n x n
void imprimirMatriz(int n, int mat[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Funcion que suma las diagonales de una matriz
int sumaDiagonales(int n, int mat[n][n]) {
    int suma = 0;

    for (int i = 0; i < n; i++) {
        suma += mat[i][i];             // Diagonal principal
        suma += mat[i][n - i - 1];     // Diagonal secundaria
    }

    if (n % 2 == 1) {
        // Si n es impar, se repite el centro, se resta una vez
        suma -= mat[n / 2][n / 2];
    }

    return suma;
}

int main() {
    // Se definen 3 matrices de prueba
    int mat3[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int mat4[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int mat5[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    printf("Matriz 3x3:\n");
    imprimirMatriz(3, mat3);
    printf("Suma de diagonales: %d\n\n", sumaDiagonales(3, mat3));

    printf("Matriz 4x4:\n");
    imprimirMatriz(4, mat4);
    printf("Suma de diagonales: %d\n\n", sumaDiagonales(4, mat4));

    printf("Matriz 5x5:\n");
    imprimirMatriz(5, mat5);
    printf("Suma de diagonales: %d\n", sumaDiagonales(5, mat5));

    return 0;
}


