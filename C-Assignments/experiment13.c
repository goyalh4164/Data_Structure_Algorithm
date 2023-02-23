#include <stdio.h>
#include  <malloc.h>

// Experiment 13: Implement operations (enqueue, dequeue) on a queue using arrays. Check the status of the queue whether it is empty or full.

struct queue {
    int *Q;
    int front;
    int rear;
    int size;
};

int isEmpty(struct queue *x) {
    if (x->rear == x->front) {
        // if (x->rear != -1) x->rear = x->front = -1; //For Optimization
        return 1;
    }
    return 0;
}

int isFull(struct queue *x) {
    if (x->rear == x->size-1) return 1;
    return 0;
}

int enqueue(struct queue *x,int elem) {
    if (isFull(x)) {
        printf("Queue is Full\n");
        return 0;
    }

    x->Q[++x->rear]=elem;
    return 1;
}

int dequeue(struct queue *x) {
    if (isEmpty(x)) {
        printf("Queue is empty\n");
        return -1;
    }

    return x->Q[++x->front];
}


void display(struct queue *x) {
    if (isEmpty(x)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue is: \nFront-> ");
    for (int i=x->front+1;i<x->rear;i++)
        printf("%d, ",x->Q[i]);
    printf("%d <-Rear\n",x->Q[x->rear]);
}

int main() {
    int temp;
    printf("Enter max size of queue: ");
    scanf("%d",&temp);
    if (temp <=0) return 0;

    struct queue q;
    q.size = temp;
    q.Q = (int *)malloc(sizeof(int)*temp);
    q.front = q.rear = -1;

    int exit=0;
    while (exit == 0) {
        int ch;
        printf("\nMenu:\n1. Display\n2. Enqueue\n3. Dequeue\n4. Check Full\n5. Check Empty\n6. Exit\nEnter your choice: ");
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
                int status = enqueue(&q,elem);
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
                printf(isFull(&q) ? "Queue is full\n": "Queue is not full\n");
                break;
            }
            case 5: {
                printf(isEmpty(&q) ? "Queue is empty\n": "Queue is not empty\n");
                break;
            }
            case 6: {
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