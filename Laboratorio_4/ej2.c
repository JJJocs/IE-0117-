#include <stdio.h>

// Función para encontrar el valor mínimo dentro del arreglo
int encontrarMinimo(int arreglo[], int longitud) {
    int minimo = arreglo[0];
    for (int i = 1; i < longitud; i++) {
        if (arreglo[i] < minimo) {
            minimo = arreglo[i];
        }
    }
    return minimo;
}

// Función para encontrar el valor máximo dentro del arreglo
int encontrarMaximo(int arreglo[], int longitud) {
    int maximo = arreglo[0];
    for (int i = 1; i < longitud; i++) {
        if (arreglo[i] > maximo) {
            maximo = arreglo[i];
        }
    }
    return maximo;
}

// Función para encontrar el valor mínimo y máximo utilizando punteros
void encontrarMinMax(int *arreglo, int *minimo, int *maximo, int longitud) {
    *minimo = arreglo[0];
    *maximo = arreglo[0];
    for (int i = 1; i < longitud; i++) {
        if (arreglo[i] < *minimo) {
            *minimo = arreglo[i];
        }
        if (arreglo[i] > *maximo) {
            *maximo = arreglo[i];
        }
    }
}

int main() {
    int arreglo[] = {21, 24, 65, 3, 56, 12, 35, 15};
    int longitud = sizeof(arreglo) / sizeof(arreglo[0]);

    // Encontrar el valor mínimo
    int min = encontrarMinimo(arreglo, longitud);
    printf("El valor mínimo en el arreglo es: %d\n", min);

    // Encontrar el valor máximo
    int max = encontrarMaximo(arreglo, longitud);
    printf("El valor máximo en el arreglo es: %d\n", max);

    // Encontrar el valor mínimo y máximo utilizando punteros
    int minimo, maximo;
    encontrarMinMax(arreglo, &minimo, &maximo, longitud);
    printf("Usando punteros, el valor mínimo es: %d y el valor máximo es: %d\n", minimo, maximo);

    return 0;
}
