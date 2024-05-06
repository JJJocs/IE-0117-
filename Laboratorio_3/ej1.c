#include <stdio.h>

int main() {
    int i;
    for (i = 0; i <= 99; i++) {
        int numero_triangular = (i * (i + 1)) / 2;  // Calcular el número triangular para el valor actual de i
        printf("%d-", numero_triangular);  // Imprimir el número triangular utilizando un guión como separador
    }
    return 0;  // Indicar que el programa se ejecutó correctamente
}
