#include <stdio.h>
#include  <malloc.h>

// Experiment 14: Implement circular queue using arrays and linked list. (Part 1-Using Array)

struct queue {
    int *Q;
    int front;
    int rear;
    int size;
};

int isEmpty(struct queue *x) {
    if (x->rear == x->front) return 1;
    return 0;
}

int isFull(struct queue *x) {
    if ((x->rear+1)%x->size == x->front) return 1;
    return 0;
}

int enqueue(struct queue *x,int elem) {
    if (isFull(x)) {
        printf("Queue is Full\n");
        return 0;
    }

    x->rear = (x->rear+1)%x->size;
    x->Q[x->rear]=elem;
    return 1;
}

int dequeue(struct queue *x) {
    if (isEmpty(x)) {
        printf("Queue is empty\n");
        return -1;
    }

    x->front = (x->front+1)%x->size;
    return x->Q[x->front];
}


void display(struct queue *x) {
    if (isEmpty(x)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue is: \nFront-> ");
    for (int i=(x->front+1)%x->size;i!=x->rear;i=(i+1)%x->size)
        printf("%d, ",x->Q[i]);
    printf("%d <-Rear\n",x->Q[x->rear]);
}

int main() {
    int temp;
    printf("Enter max size of queue: ");
    scanf("%d",&temp);
    if (temp <=0) return 0;

    struct queue q;
    q.size = temp+1;
    q.Q = (int *)malloc(sizeof(int)*temp+1);
    q.front = q.rear = 0;

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
