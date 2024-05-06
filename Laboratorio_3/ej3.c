#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define MIN_SIZE 1

// Función para generar una matriz cuadrada binaria aleatoria de tamaño n
void generate_matrix(int n, int matrix[n][n]) {
    srand(time(0));  // Inicializar la semilla del generador de números aleatorios
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 2;  // Generar un número aleatorio: 0 o 1
        }
    }
}

// Función para imprimir una matriz cuadrada de tamaño n
void print_matrix(int n, int matrix[n][n]) {
    printf("La matriz utilizada corresponde a:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Función para calcular el tamaño del cuadrado de unos más grande en una matriz cuadrada de tamaño n
int largest_square_size(int n, int matrix[n][n]) {
    int dp[n][n];  // Matriz auxiliar
    int max_size = 0;  // Tamaño del cuadrado de unos más grande

    // Inicializar la primera fila y primera columna de la matriz auxiliar
    for (int i = 0; i < n; i++) {
        dp[i][0] = matrix[i][0];
        dp[0][i] = matrix[0][i];
        if (dp[i][0] > max_size) max_size = dp[i][0];
        if (dp[0][i] > max_size) max_size = dp[0][i];
    }

    // Calcular el tamaño del cuadrado de unos más grande
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 1) {
                dp[i][j] = 1 + (dp[i-1][j] < dp[i][j-1] ? (dp[i-1][j] < dp[i-1][j-1] ? dp[i-1][j] : dp[i-1][j-1]) : (dp[i][j-1] < dp[i-1][j-1] ? dp[i][j-1] : dp[i-1][j-1]));
                if (dp[i][j] > max_size) max_size = dp[i][j];
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return max_size;
}

int main() {
    int n;

    // Solicitar al usuario que ingrese el tamaño de la matriz
    printf("Ingrese el número de filas de la matriz nxn: ");
    scanf("%d", &n);
    if (n < MIN_SIZE || n > MAX_SIZE) {
        printf("Error: El número ingresado está fuera del rango permitido. Se utilizará un valor por defecto (5)\n");
        n = 5;
    }

    // Generar y mostrar la matriz
    int matrix[n][n];
    generate_matrix(n, matrix);
    print_matrix(n, matrix);

    // Calcular e imprimir el tamaño del cuadrado de unos más grande
    int largestSquareSize = largest_square_size(n, matrix);
    printf("El tamaño del cuadrado más grande de unos es: %dx%d\n", largestSquareSize, largestSquareSize);

    return 0;
}
