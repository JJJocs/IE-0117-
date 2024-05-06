#include <stdio.h>

// Función para calcular el factorial de un número entero positivo
int factorial (int n) {
    int i = 1;
    while (n > 1) {
        i = i * n;  // Multiplicar el número actual por el acumulador
        n = n - 1;  // Decrementar el número para el siguiente ciclo
    }
    return i;  // Devolver el factorial calculado
}

// Función principal
int main( ) {
    int valor_ingresado;

    // Solicitar al usuario que ingrese un número entero positivo
    do {
        printf("Ingrese un número entero positivo: ");
        if (scanf("%d", &valor_ingresado) != 1 || valor_ingresado <= 0) {
            // Si la entrada no es un número entero positivo, limpiar el búfer de entrada
            printf("Error: Debe ingresar un número entero positivo.\n");
            while (getchar() != '\n'); // Limpiar el búfer de entrada
        }
    } while (valor_ingresado <= 0);

    // Calcular el factorial del número ingresado utilizando la función factorial
    int fac_valor_ingresado = factorial(valor_ingresado);

    // Imprimir el valor ingresado y su factorial
    printf("El valor ingresado es: %d, su factorial es: %d\n", valor_ingresado, factorial(valor_ingresado));

    return 0;  // Indicar que el programa se ejecutó correctamente
}
