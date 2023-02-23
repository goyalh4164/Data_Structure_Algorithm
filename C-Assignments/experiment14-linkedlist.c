#include <stdio.h>
#include  <malloc.h>

// Experiment 14: Implement circular queue using arrays and linked list. (Part 2-Using Linked List)

struct node {
    int val;
    struct node* next;
};

struct queue {
    struct node* front;
    struct node* rear;
};

int isEmpty(struct queue *x) {
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
    if (isEmpty(x)) {
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


void display(struct queue *x) {
    if (isEmpty(x)) {
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

int main() {
    struct queue q;
    q.front = q.rear = NULL;

    int exit=0;
    while (exit == 0) {
        int ch;
        printf("\nMenu:\n1. Display\n2. Enqueue\n3. Dequeue\n4. Check Empty\n5. Exit\nEnter your choice: ");
        scanf("%d",&ch);

        switch (ch) {
            case 1: {
                display(&q);
                break;
            }
            case 2: {
                int elem;
                printf("Enter element to insert: ");
                scanf("%d",&elem);
                enqueue(&q,elem);
                display(&q);
                break;
            }
            case 3: {
                int elem = dequeue(&q);
                if (elem != -1) {
                    printf("Element dequeued is %d\n",elem);
                    display(&q);
                }
                break;
            }
            case 4: {
                printf(isEmpty(&q) ? "Queue is empty\n": "Queue is not empty\n");
                break;
            }
            case 5: {
                exit = 1;
                break;
            }
            default:{
                printf("Invalid choice\n");
                break;
            }
        }
    }

    return 0;
}
