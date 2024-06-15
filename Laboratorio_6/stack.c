#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/**
 * @brief Agrega un elemento al tope del stack.
 * 
 * @param stack Puntero al stack.
 * @param data Elemento a agregar.
 */
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Error de asignación de memoria\n");
        return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    printStack(stack);
}

/**
 * @brief Elimina y devuelve el elemento en el tope del stack.
 * 
 * @param stack Puntero al stack.
 * @return Elemento eliminado del tope del stack.
 */
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack underflow\n");
        return -1;
    }
    Node* temp = stack->top;
    int poppedData = temp->data;
    stack->top = temp->next;
    free(temp);
    printStack(stack);
    return poppedData;
}

/**
 * @brief Devuelve el elemento en el tope del stack sin eliminarlo.
 * 
 * @param stack Puntero al stack.
 * @return Elemento en el tope del stack.
 */
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack está vacío\n");
        return -1;
    }
    return stack->top->data;
}

/**
 * @brief Verifica si el stack está vacío.
 * 
 * @param stack Puntero al stack.
 * @return 1 si el stack está vacío, 0 en caso contrario.
 */
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

/**
 * @brief Imprime los elementos del stack.
 * 
 * @param stack Puntero al stack.
 */
void printStack(Stack* stack) {
    Node* current = stack->top;
    printf("Stack: ");
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
