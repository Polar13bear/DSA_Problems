#include <stdio.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char ch) {
    if (top < MAX - 1)
        stack[++top] = ch;
}
char pop() {
    if (top >= 0)
        return stack[top--];
    else
        return '\0';
}
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}
int isBalanced(char expr[]) {
    top = -1;  // reset stack
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            char open = pop();
            if (!isMatchingPair(open, ch))
                return 0;
        }
    }
    return (top == -1);
}
int main() {
    char expression[MAX];
    printf("Enter expression with parentheses: ");
    scanf("%s", expression);

    if (isBalanced(expression))
        printf("Parentheses are balanced.\n");
    else
        printf("Parentheses are NOT balanced.\n");

    return 0;
}
