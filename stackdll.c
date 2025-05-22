#include <stdio.h>
#include <stdlib.h>
// Define a node in doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
// Head pointer to represent the top of the stack
struct Node* head = NULL;
// Push operation (insert at beginning)
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
    printf("Pushed %d\n", value);
}
// Pop operation (remove from beginning)
void pop() {
    if (head == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    struct Node* temp = head;
    printf("Popped %d\n", temp->data);
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
}
// Display stack from top to bottom
void display() {
    struct Node* temp = head;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// Main function to test push and pop
int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    pop();
    pop();
    pop();  // Extra pop to show underflow
    return 0;
}
