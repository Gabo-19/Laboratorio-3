#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Encuentra la secuencia de 1s más larga en todas las diagonales
int findLargestLine(int n, int matrix[n][n]) {
    int maxLen = 0;

    // Diagonales principales (\)
    for (int start = 0; start < n; start++) {
        // desde primera fila
        int len = 0;
        for (int i = 0, j = start; i < n && j < n; i++, j++) {
            if (matrix[i][j] == 1) len++;
            else len = 0;
            if (len > maxLen) maxLen = len;
        }
    }
    for (int start = 1; start < n; start++) {
        // desde primera columna (sin repetir la principal)
        int len = 0;
        for (int i = start, j = 0; i < n && j < n; i++, j++) {
            if (matrix[i][j] == 1) len++;
            else len = 0;
            if (len > maxLen) maxLen = len;
        }
    }

    // Diagonales secundarias (/)
    for (int start = 0; start < n; start++) {
        // desde primera fila (derecha a izquierda)
        int len = 0;
        for (int i = 0, j = start; i < n && j >= 0; i++, j--) {
            if (matrix[i][j] == 1) len++;
            else len = 0;
            if (len > maxLen) maxLen = len;
        }
    }
    for (int start = 1; start < n; start++) {
        // desde última columna hacia abajo (sin repetir la principal)
        int len = 0;
        for (int i = start, j = n - 1; i < n && j >= 0; i++, j--) {
            if (matrix[i][j] == 1) len++;
            else len = 0;
            if (len > maxLen) maxLen = len;
        }
    }

    return maxLen;
}

// Imprime la matriz
void printMatrix(int n, int mat[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size;
    printf("Ingrese el tamaño de la matriz: ");
    scanf("%d", &size);

    int matrix[size][size];
    srand(time(NULL));

    // Llenar matriz con 0 o 1 aleatorios
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 2;
        }
    }

    printf("Matriz generada:\n");
    printMatrix(size, matrix);

    int largest = findLargestLine(size, matrix);
    printf("El tamaño de la secuencia de 1s más grande en diagonales es: %d\n", largest);

    return 0;
}

