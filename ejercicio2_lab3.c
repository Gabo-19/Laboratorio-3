#include <stdio.h>

// busca el maximo en arreglo de n elementos
int encontrarMaximo(int arr[], int n) {
    int maximo = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maximo) {  // corregido: buscar mayor, no menor
            maximo = arr[i];
        }
    }
    return maximo;
}

int main() {
    int numeros[] = {10, 20, 5, 40, 30};
    int n = sizeof(numeros) / sizeof(numeros[0]);
    int max = encontrarMaximo(numeros, n);
    printf("El numero mas grande es: %d\n", max);
    return 0;
}

