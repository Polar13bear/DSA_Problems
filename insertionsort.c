#include <stdio.h>
#include <stdlib.h>
// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;
// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// Insert node at end
void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
// Display list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
// Insertion Sort on singly linked list
void insertionSort(Node** head) {
    if (*head == NULL || (*head)->next == NULL)
        return;
    Node* sorted = NULL;  // new sorted list
    Node* current = *head;
    while (current != NULL) {
        Node* next = current->next;
        // Insert current in sorted list
        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data)
                temp = temp->next;
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    *head = sorted;
}
int main() {
    Node* head = NULL;
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(&head, val);
    }
    printf("Original list:\n");
    display(head);
    insertionSort(&head);
    printf("Sorted list:\n");
    display(head);
    return 0;
}
