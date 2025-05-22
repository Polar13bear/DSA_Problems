#include <stdio.h>
#include <stdlib.h>
#define EMPTY -1
int SIZE;
int *t;
void init() {
    for(int i = 0; i < SIZE; i++) t[i] = EMPTY;
}
void insert(int k) {
    int h1 = k % SIZE;
    int h2 = 7 - (k % 7);
    for(int i = 0; i < SIZE; i++) {
        int pos = (h1 + i*h2) % SIZE;
        if(t[pos] == EMPTY || t[pos] == k) {
            t[pos] = k;
            return;
        }
    }
}
int search(int k) {
    int h1 = k % SIZE;
    int h2 = 7 - (k % 7);
    for(int i = 0; i < SIZE; i++) {
        int pos = (h1 + i*h2) % SIZE;
        if(t[pos] == EMPTY) return 0;
        if(t[pos] == k) return 1;
    }
    return 0;
}
int main() {
    printf("DOUBLE HASHING:\n");
    printf("Enter hash table size: ");
    scanf("%d", &SIZE);
    t = (int*)malloc(SIZE * sizeof(int));
    init();
    int n, x;
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(x);
    }
    printf("Enter element to search: ");
    scanf("%d", &x);
    printf("Search %d: %s\n", x, search(x) ? "Found" : "Not Found");
    free(t);
    return 0;
}