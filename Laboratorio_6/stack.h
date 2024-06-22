#ifndef STACK_H
#define STACK_H

/**
 * @brief Estructura que representa un nodo de la lista enlazada.
 */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/**
 * @brief Estructura que representa un stack.
 */
typedef struct Stack {
    Node* top;
} Stack;

/**
 * @brief Agrega un elemento al tope del stack.
 * 
 * @param stack Puntero al stack.
 * @param data Elemento a agregar.
 */
void push(Stack* stack, int data);

/**
 * @brief Elimina y devuelve el elemento en el tope del stack.
 * 
 * @param stack Puntero al stack.
 * @return Elemento eliminado del tope del stack.
 */
int pop(Stack* stack);

/**
 * @brief Devuelve el elemento en el tope del stack sin eliminarlo.
 * 
 * @param stack Puntero al stack.
 * @return Elemento en el tope del stack.
 */
int peek(Stack* stack);

/**
 * @brief Verifica si el stack está vacío.
 * 
 * @param stack Puntero al stack.
 * @return 1 si el stack está vacío, 0 en caso contrario.
 */
int isEmpty(Stack* stack);

/**
 * @brief Imprime los elementos del stack.
 * 
 * @param stack Puntero al stack.
 */
void printStack(Stack* stack);

#endif // STACK_H
