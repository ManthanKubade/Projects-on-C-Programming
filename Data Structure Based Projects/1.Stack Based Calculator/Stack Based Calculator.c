#include <stdio.h>
#include <ctype.h>
#include <math.h>

int stack[100];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int applyOperator(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int evaluate(char exp[]) {
    int i;
    for(i = 0; exp[i]; i++) {
        if(isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            int b = pop();
            int a = pop();
            push(applyOperator(a, b, exp[i]));
        }
    }
    return pop();
}

int main() {
    char exp[100];
    printf("Enter postfix expression: ");
    scanf("%s", exp);

    printf("Result = %d\n", evaluate(exp));
    return 0;
}
