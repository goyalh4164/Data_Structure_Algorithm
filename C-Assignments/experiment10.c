#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>


// Experiment 10: Implement the conversion of infix notation to postfix notation.

struct stack {
    char *stk;
    int size;
    int top;
};

bool isEmpty(struct stack *s) {
    return (s->top == -1);
}

bool isFull(struct stack *s) {
    return (s->top == s->size - 1);
}

void push(struct stack *s,char x) {
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

int isOperator(char x) { // This function is used in checking infix expression
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^') return 1;
    return 0;
}

int checkInfixExpression(char *infix) {
    int noOfOperators=0,noOfOperands=0,noOfOpenBrackets=0;
    for (int i=0;infix[i] != '\0';i++) {
        if (isOperator(infix[i])) {
            if (i == 0 || infix[i+1] == '\0') return 0; // If last or first char is operator
            if (isOperator(infix[i+1])) return 0; // If next char is operator
            if (infix[i-1] == '(' || infix[i+1] == ')') return 0; // Unnecessary opening bracket before or closing bracket after
            noOfOperators++;
        } else if (infix[i] == '(')
            noOfOpenBrackets++;
        else if (infix[i] == ')') {
            noOfOpenBrackets--;
            if (noOfOpenBrackets < 0) return 0;
        } else
            noOfOperands++;
    }
    if (noOfOpenBrackets > 0  || noOfOperands != noOfOperators+1) return 0;
    return 1;
}

int isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x =='(' || x == ')') return 0;
    return 1;
}

int precedence(char x,int inStack) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    if (x == '(') return inStack ? 0:4;
    if (x == ')') return 0;
    return -1;
} 

void convert(char *infix,char *postfix) {
    struct stack s;
    s.stk = (char *)malloc(sizeof(char)*100);
    s.top=-1;
    s.size=100;
    int i=0,j=0;
    while (infix[i] != '\0') {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else {
            char stackTop = top(&s);
            if (precedence(infix[i],0) > precedence(stackTop,1))
                push(&s,infix[i++]);
            else {
                if (precedence(infix[i],0) == precedence(stackTop,1) && precedence(infix[i],0) == 0) {
                    pop(&s);
                    i++;
                } else {
                    postfix[j++] = pop(&s);
                }
            }                
        }
    }
    while (!isEmpty(&s))
        postfix[j++] = pop(&s);
    postfix[j] = '\0';
}

void display(char *x) {
    for (int i=0;x[i] != '\0';i++) {
        printf("%c",x[i]);
    }
}

int main() {
    char infix[100],postfix[100],temp;
    printf("Enter your infix expression(enter '?' whenever to stop): ");

    int i=0;
    for (;i<99;i++) {
        // printf("Input %d: ",i+1);
        scanf(" %c",&temp);
        if (temp == '?') break;
        infix[i] = temp;
    }
    if (i == 99) printf("You have reached max size of array");
    infix[i] = '\0';

    int ch = checkInfixExpression(infix);
    if (ch == 0) {
        printf("Entered infix expression is not valid\n");
        return 0;
    }

    convert(infix,postfix);

    printf("Given infix expression: ");
    display(infix);
    printf("\n\nGiven postfix expression: ");
    display(postfix);
    printf("\n");

    return 0;
}
