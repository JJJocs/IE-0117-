#include <stdio.h>
#include "stack.h"

/**
 * @brief Función principal para demostrar la funcionalidad del stack.
 * 
 * @return int Código de estado de la ejecución.
 */
int main() {
    Stack stack;
    stack.top = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Elemento superior es %d\n", peek(&stack));

    printf("Elemento sacado es %d\n", pop(&stack));
    printf("Elemento sacado es %d\n", pop(&stack));

    printf("El stack está %svacío\n", isEmpty(&stack) ? "" : "no ");

    // Vaciar el stack para liberar toda la memoria
    while (!isEmpty(&stack)) {
        pop(&stack);
    }

    return 0;
}
