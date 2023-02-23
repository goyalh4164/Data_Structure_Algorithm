#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>


// Experiment 9: Implement operations (push, pop) on a stack using arrays. Check the status of the stack whether there is underflow or overflow.

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
        printf("Stack Overflow\n");
        return;
    }

    s->top++;
    s->stk[s->top] = x;
}

int pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }

    s->top--;
    return s->stk[s->top+1];
}

int top(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }

    return s->stk[s->top];
}

void display(struct stack *s) {
    if (isEmpty(s)) {
        printf("\nStack is empty\n");
        return;
    }

    printf("\nStack looks like below: \n");
    int i=s->top;
    printf("%d <- Top\n",s->stk[i--]);
    while (i>=0) {
        printf("%d\n",s->stk[i]);
        i--;
    }
}

int main() {
    int n;
    printf("Enter max size of stack: ");
    scanf("%d",&n);
    struct stack s;
    s.stk = (int *)malloc(sizeof(int)*n);
    s.top=-1;
    s.size=n;

    bool exit = false;
    while (!exit) {
        printf("\nMenu: \n1. Push\n2. Pop\n3. Top\n4. Display\n5. Exit\nEnter your choice: ");
        int ch;
        scanf("%d",&ch);
        switch (ch) {
            case 1: {
                printf("Enter an element: ");
                int elem;
                scanf("%d",&elem);
                push(&s,elem);
                display(&s);
                break;
            }
            case 2: {
                int elem = pop(&s);
                if (elem != -1) {
                    printf("\nPopped element is %d\n",elem);
                    display(&s);
                }
                break;
            }
            case 3: {
                int elem = top(&s);
                if (elem != -1)
                    printf("\nTopmost element of stack: %d\n",elem);
                break;
            }
            case 4: {
                display(&s);
                break;
            }
            case 5: {
                exit = true;
                break;
            }
            default: {
                printf("Invalid option.\n");
                break;
            }
        }
    }

    return 0;
}