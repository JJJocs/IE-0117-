#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct DoublyLinkedList {
    Node* head;
    Node* tail;
} DoublyLinkedList;

// Prototipos de funciones
DoublyLinkedList* createList();
void insertAtBeginning(DoublyLinkedList* list, int data);
void insertAtEnd(DoublyLinkedList* list, int data);
void insertAtPosition(DoublyLinkedList* list, int data, int position);
void deleteNode(DoublyLinkedList* list, int data);
Node* search(DoublyLinkedList* list, int data);
void printListForward(DoublyLinkedList* list);
void printListBackward(DoublyLinkedList* list);
void freeList(DoublyLinkedList* list);

#endif // DOUBLE_LIST_H
