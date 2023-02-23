#include <stdio.h>
#include <malloc.h>

// Experiment 15: Implement stacks and queues using linked list.

struct node {
    int val;
    struct node* next;
};

// Functions and struct of stack

struct stack {
    struct node* top;
};

int isEmptyStack(struct stack* stk) {
    if (stk->top == NULL) return 1;
    return 0;
}

void push(struct stack* stk,int elem) {
    struct node* p = (struct node *)malloc(sizeof(struct node));
    p->val = elem;
    p->next = stk->top;
    stk->top = p;
} 

int pop(struct stack* stk) {
    if (isEmptyStack(stk)) {
        printf("Stack is empty\n");
        return -1;
    }

    struct node* p = stk->top;
    stk->top = stk->top->next;
    int elem = p->val;
    free(p);
    return elem;
}

int peek(struct stack* stk) {
    if (isEmptyStack(stk)) {
        printf("Stack is empty\n");
        return -1;
    }

    return stk->top->val;
}

void displayStack(struct stack* stk) {
    if (isEmptyStack(stk)) {
        printf("Stack is empty\n");
        return ;
    }

    printf("\nStack is:\n%d <- Top\n",stk->top->val);
    struct node* p = stk->top->next;
    while (p != NULL) {
        printf("%d\n",p->val);
        p=p->next;
    }
}

void stackMenu(struct stack* stk) {
    int ch=1;
    while (ch != 5) {
        printf("\nMenu for Stack:\n1. Display\n2. Push\n3. Pop\n4. Peek\n5. Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:{
            displayStack(stk);
            break;
        }
        case 2: {
            int elem;
            printf("Enter element: ");
            scanf("%d",&elem);
            push(stk,elem);
            displayStack(stk);
            break;
        }
        case 3: {
            int elem = pop(stk);
            if (elem != -1) {
                printf("Element popped is %d\n",elem);
                displayStack(stk);
            }
            break;
        }
        case 4: {
            int elem = peek(stk);
            if (elem != -1) {
                printf("Topmost element is %d\n",elem);
            }
            break;
        }
        case 5: {
            printf("Exiting...\n");
            break;
        }
        default:
            printf("Invalid Choice");
            break;
        }
    }
}

// Functions and struct of queue

struct queue {
    struct node* front;
    struct node* rear;
};

int isEmptyQueue(struct queue *x) {
    if (x->front == NULL) return 1;
    return 0;
}

void enqueue(struct queue *x,int elem) {
    struct node* q = (struct node *)malloc(sizeof(struct node));
    q->val = elem;
    q->next = NULL;

    if (x->rear == NULL) {
        // Queue was empty before
        x->front = x->rear = q;
    }
    x->rear->next = q;
    x->rear = q;
}

int dequeue(struct queue *x) {
    if (isEmptyQueue(x)) {
        printf("Queue is empty\n");
        return -1;
    }

    int elem = x->front->val;
    if (x->front == x->rear) {
        // Single element in queue
        free(x->front);
        x->front = x->rear = NULL;
        return elem;
    }
    
    struct node * temp = x->front->next;
    free(x->front);
    x->front = temp;
    return elem;
}


void displayQueue(struct queue *x) {
    if (isEmptyQueue(x)) {
        printf("Queue is empty\n");
        return;
    }

    struct node* p = x->front;
    printf("Queue is: \nFront-> ");
    while (p != x->rear) {
        printf("%d, ",p->val);
        p = p->next;
    }
    printf("%d <-Rear\n",x->rear->val);
}

void queueMenu(struct queue *q) {
    int ch=1;
    while (ch != 5) {
        printf("\nMenu for Queue:\n1. Display\n2. Enqueue\n3. Dequeue\n4. Check Empty\n5. Exit\nEnter your choice: ");
        scanf("%d",&ch);

        switch (ch) {
            case 1: {
                displayQueue(q);
                break;
            }
            case 2: {
                int elem;
                printf("Enter element to insert: ");
                scanf("%d",&elem);
                enqueue(q,elem);
                displayQueue(q);
                break;
            }
            case 3: {
                int elem = dequeue(q);
                if (elem != -1) {
                    printf("Element dequeued is %d\n",elem);
                    displayQueue(q);
                }
                break;
            }
            case 4: {
                printf(isEmptyQueue(q) ? "Queue is empty\n": "Queue is not empty\n");
                break;
            }
            case 5: {
                printf("Exiting...\n");
                break;
            }
            default:{
                printf("Invalid choice\n");
                break;
            }
        }
    }
}

int main() {
    struct stack stk;
    stk.top = NULL;
    
    struct queue q;
    q.front = q.rear = NULL;
    
    int ch=1;
    while (ch!=3) {
        printf("\nMenu:\n1. Stack\n2. Queue\n3. Exit\nEnter your choice: ");
        scanf("%d",&ch);

        switch (ch) {
        case 1:
            stackMenu(&stk);
            break;
        case 2:
            queueMenu(&q);
            break;
        case 3:
            printf("Exiting...");
            break;
        default:
            printf("Invalid Choice");
            break;
        }
    }
}