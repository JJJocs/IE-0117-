#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

DoublyLinkedList* createList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void insertAtBeginning(DoublyLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    newNode->prev = NULL;
    
    if (list->head != NULL) {
        list->head->prev = newNode;
    }
    
    list->head = newNode;
    
    if (list->tail == NULL) {
        list->tail = newNode;
    }
}

void insertAtEnd(DoublyLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = list->tail;
    
    if (list->tail != NULL) {
        list->tail->next = newNode;
    }
    
    list->tail = newNode;
    
    if (list->head == NULL) {
        list->head = newNode;
    }
}

void insertAtPosition(DoublyLinkedList* list, int data, int position) {
    if (position == 0) {
        insertAtBeginning(list, data);
        return;
    }
    
    Node* current = list->head;
    for (int i = 0; i < position - 1 && current != NULL; ++i) {
        current = current->next;
    }
    
    if (current == NULL) {
        insertAtEnd(list, data);
        return;
    }
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = current->next;
    newNode->prev = current;
    
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    
    current->next = newNode;
    
    if (newNode->next == NULL) {
        list->tail = newNode;
    }
}

void deleteNode(DoublyLinkedList* list, int data) {
    Node* current = list->head;
    while (current != NULL && current->data != data) {
        current = current->next;
    }
    
    if (current == NULL) {
        return;
    }
    
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        list->head = current->next;
    }
    
    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        list->tail = current->prev;
    }
    
    free(current);
}

Node* search(DoublyLinkedList* list, int data) {
    Node* current = list->head;
    while (current != NULL && current->data != data) {
        current = current->next;
    }
    return current;
}

void printListForward(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void printListBackward(DoublyLinkedList* list) {
    Node* current = list->tail;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

void freeList(DoublyLinkedList* list) {
    Node* current = list->head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}
