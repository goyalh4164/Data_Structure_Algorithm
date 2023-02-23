#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>


// Experiment 11: Implement the evaluation of postfix notation using stacks.

struct stack {
    int *stk;
    int size;
    int top;
};

bool isEmpty(struct stack *s) {
    return (s->top == -1);
}

bool isFull(struct stack *s) {
    return (s->top == s->size - 1);
}

void push(struct stack *s,int x) {
    if (isFull(s)) {
        return;
    }

    s->top++;
    s->stk[s->top] = x;
}

char pop(struct stack *s) {
    if (isEmpty(s)) {
        return '?'; // ? is just a symbol to know that stack is empty
    }

    s->top--;
    return s->stk[s->top+1];
}

char top(struct stack *s) {
    if (isEmpty(s)) {
        return '?'; // ? is just a symbol to know that stack is empty
    }

    return s->stk[s->top];
}

int isOperator(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^') return 1;
    return 0;
}

int isNumber(char x) {
    if (x >= 48 && x <= 57) return 1;
    return 0;
}

int checkPostfixExpression(char *postfix) {
    int noOfOperators=0,noOfOperands=0;
    for (int i=0;postfix[i] != '\0';i++) {
        if (isOperator(postfix[i])) {
            if (i == 0) return 0; // If last or first char is operator
            if (noOfOperands <= noOfOperators) return 0;
            noOfOperators++;
        } else if (isNumber(postfix[i]))
            noOfOperands++;
        else // Since we are supposed to evaluate the postfix expression , we cannot accept anything other than numbers and operators
            return 0;
    }
    if (noOfOperands != noOfOperators+1) return 0;
    return 1;
}

int calculate(char * postfix) {
    struct stack s;
    s.stk = (int *)malloc(sizeof(int)*100);
    s.size = 100;
    s.top = -1;

    for (int i=0;postfix[i] != '\0';i++) {
        if (isNumber(postfix[i]))
            push(&s,postfix[i]-'0');
        else {
            int a,b,result;
            b = pop(&s);
            a = pop(&s);
            switch (postfix[i])
            {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;          
            case '^':
                result = a ^ b;
                break;
            default:
                printf("Unexpected operator encountered");
                return 0;
                break;
            }
            push(&s,result);
        }
    }

    if (s.top != 0) {
        printf("Unexpected error occurred. More than one values in stack after executing postfix expression");
        return 0;
    }
    return pop(&s);
}

void display(char *x) {
    for (int i=0;x[i] != '\0';i++) {
        printf("%c",x[i]);
    }
}

int main() {
    char postfix[100],temp;
    printf("Enter your postfix expression(enter '?' whenever to stop): ");

    int i=0;
    for (;i<99;i++) {
        // printf("Input %d: ",i+1);
        scanf(" %c",&temp);
        if (temp == '?') break;
        postfix[i] = temp;
    }
    if (i == 99) printf("You have reached max size of array");
    postfix[i] = '\0';

    int ch = checkPostfixExpression(postfix);
    if (ch == 0) {
        printf("Entered postfix expression is not valid\n");
        return 0;
    }

    int result = calculate(postfix);

    printf("\n\nGiven postfix expression: ");
    display(postfix);
    printf("\nResult: %d\n",result);

    return 0;
}
