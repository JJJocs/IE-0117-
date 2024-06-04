#include <stdio.h>
#include "double_list.h"


int main() {
    DoublyLinkedList* list = createList();
    
    insertAtBeginning(list, 1);
    insertAtEnd(list, 2);
    insertAtEnd(list, 3);
    insertAtPosition(list, 4, 1); // Insertar 4 en la posición 1
    
    printf("Lista hacia adelante: ");
    printListForward(list);
    
    printf("Lista hacia atrás: ");
    printListBackward(list);
    
    deleteNode(list, 2); // Eliminar nodo con dato 2
    
    printf("Lista después de eliminar: ");
    printListForward(list);
    
    Node* found = search(list, 3);
    if (found != NULL) {
        printf("Nodo con dato 3 encontrado\n");
    } else {
        printf("Nodo con dato 3 no encontrado\n");
    }
    
    freeList(list);
    
    return 0;
}
