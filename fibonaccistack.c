#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int val) {
    if (top < MAX - 1)
        stack[++top] = val;
}
int pop() {
    if (top >= 0)
        return stack[top--];
    return 0;
}
void fibonacci(int n) {
    if (n <= 0) return;
    // Push first two numbers
    push(0);
    if (n > 1) push(1);
    // Generate remaining numbers using stack
    while (top < n - 1) {
        int a = pop();
        int b = pop();
        int next = a + b;
        // Put back b and next to maintain order
        push(b);
        push(a);
        push(next);
    }
    printf("Fibonacci series: ");
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}
int main() {
    int n;
    printf("Enter number of Fibonacci terms: ");
    scanf("%d", &n);
    if (n < 1)
        printf("Invalid input.\n");
    else
        fibonacci(n);
    return 0;
}
