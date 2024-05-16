#include <stdio.h>

// Función para realizar la búsqueda binaria de forma recursiva
int busquedaBinariaRecursiva(int arr[], int inicio, int fin, int valor) {
    if (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;

        // Si el valor está en el medio
        if (arr[medio] == valor) {
            return medio;
        }

        // Si el valor es mayor, buscar en la mitad derecha de forma recursiva
        if (arr[medio] < valor) {
            return busquedaBinariaRecursiva(arr, medio + 1, fin, valor);
        }
        // Si el valor es menor, buscar en la mitad izquierda de forma recursiva
        else {
            return busquedaBinariaRecursiva(arr, inicio, medio - 1, valor);
        }
    }
    // Si el valor no está presente en el arreglo
    return -1;
}

// Función para realizar la búsqueda lineal
int busquedaLineal(int arr[], int tamano, int valor) {
    for (int i = 0; i < tamano; i++) {
        if (arr[i] == valor) {
            return i; // Se encontró el valor, devuelve su posición
        }
    }
    return -1; // Valor no encontrado
}

int main() {
    int arreglo[] = {2, 4, 6, 23, 56, 79}; // Arreglo ordenado
    int valor_a_buscar;
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);

    printf("Ingresa un número entero a buscar: ");
    scanf("%d", &valor_a_buscar);

    // Búsqueda binaria iterativa
    int inicio = 0;
    int fin = tamano - 1;
    int resultado_binario_iterativo = -1;
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        if (arreglo[medio] == valor_a_buscar) {
            resultado_binario_iterativo = medio;
            break;
        } else if (arreglo[medio] < valor_a_buscar) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }

    if (resultado_binario_iterativo != -1) {
        printf("Búsqueda binaria iterativa: El valor %d fue encontrado en la posición %d del arreglo.\n", valor_a_buscar, resultado_binario_iterativo);
    } else {
        printf("Búsqueda binaria iterativa: El valor %d no fue encontrado en el arreglo.\n", valor_a_buscar);
    }

    // Búsqueda lineal
    int resultado_lineal = busquedaLineal(arreglo, tamano, valor_a_buscar);
    if (resultado_lineal != -1) {
        printf("Búsqueda lineal: El valor %d fue encontrado en la posición %d del arreglo.\n", valor_a_buscar, resultado_lineal);
    } else {
        printf("Búsqueda lineal: El valor %d no fue encontrado en el arreglo.\n", valor_a_buscar);
    }

    // Búsqueda binaria recursiva
    int resultado_binario_recursivo = busquedaBinariaRecursiva(arreglo, 0, tamano - 1, valor_a_buscar);
    if (resultado_binario_recursivo != -1) {
        printf("Búsqueda binaria recursiva: El valor %d fue encontrado en la posición %d del arreglo.\n", valor_a_buscar, resultado_binario_recursivo);
    } else {
        printf("Búsqueda binaria recursiva: El valor %d no fue encontrado en el arreglo.\n", valor_a_buscar);
    }

    return 0;
}