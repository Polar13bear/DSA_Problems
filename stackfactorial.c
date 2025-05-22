#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int val) {
    if (top < MAX - 1)
        stack[++top] = val;
    else
        printf("Stack overflow\n");
}
int pop() {
    if (top >= 0)
        return stack[top--];
    else {
        printf("Stack underflow\n");
        return -1;  // Indicate error
    }
}
int factorial(int n) {
    int result = 1;
    // Push all values from n down to 2 onto the stack
    for (int i = n; i > 1; i--)
        push(i);
    // Multiply all popped values
    while (top != -1) {
        int val = pop();
        if (val == -1)  // Just a safety check
            break;
        result *= val;
    }
    return result;
}
int main() {
    int num;
    printf("Enter number to calculate factorial: ");
    scanf("%d", &num);

    if (num < 0)
        printf("Factorial not defined for negative numbers.\n");
    else
        printf("Factorial of %d is %d\n", num, factorial(num));

    return 0;
}
