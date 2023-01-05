#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    int capacity;
    int size;
    struct Node *front;
    struct Node *tail;
};

struct Queue *createQueue(int n)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    if (!queue)
        return NULL;
    queue->capacity = n;
    queue->size = 0;
    queue->front = NULL;
    queue->tail=NULL;
    return queue;
}

bool isEmpty(struct Queue *queue)
{
    return queue->size == 0;
}
bool isFull(struct Queue *queue)
{
    return queue->size == queue->capacity;
}
void Enqueue(struct Queue *queue, int element)
{
    if (isFull(queue))
    {
        printf("Queue OverFlow\n");
        return;
    }
    // First time insertion
    if (isEmpty(queue))
    {
        struct Node *node = (struct Node *)malloc(sizeof(struct Node));
        node->data = element;
        node->next = NULL;
        queue->front = node;
        queue->tail = node;
        queue->size++;
        return;
    }
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = element;
    node->next = NULL;
    queue->tail->next=node;
    queue->tail=queue->tail->next;
    queue->size++;
}
void Dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue UnderFlow\n");
        return;
    }
    // if we are removing the last node
    if (queue->size == 1)
    {
        printf("Dequeued Element is :%d\n", queue->front->data);
        queue->size--;
        queue->front = NULL;
        queue->tail = NULL;
        return;
    }
    printf("Dequeued Element is :%d\n", queue->front->data);
    queue->front=queue->front->next;
    queue->size--;
}
void front(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is Empty \n");
        return;
    }
    printf("Front Element is :%d\n", queue->front->data);
}

int main()
{
    printf("----------------WELCOME TO Queue PROGRAM-----------------------------------\n");
    printf("Enter the size of the queue you want: \n");
    int d;
    scanf("%d", &d);
    if (d <= 0)
    {
        printf("Invalid Size\n");
    }
    else
    {
        struct Queue *queue = createQueue(d);
        while (true)
        {
            printf("Press 1 To Push in queue \n");
            printf("Press 2 To Pop in queue\n");
            printf("Press 3 To View Top in queue\n");
            printf("Press 4 To check Empty or not\n");
            printf("Press 5 To check Full or not\n");
            printf("Press 6 To Exit\n");
            int ch;
            scanf("%d", &ch);
            if (ch == 1)
            {
                int item;
                scanf("%d", &item);
                Enqueue(queue, item);
            }
            else if (ch == 2)
            {
                Dequeue(queue);
            }
            else if (ch == 3)
            {
                front(queue);
            }
            else if (ch == 4)
            {
                if (isEmpty(queue))
                {
                    printf("Queue is Empty\n");
                }
                else
                {
                    printf("Not Empty\n");
                }
            }
            else if (ch == 5)
            {
                if (isFull(queue))
                {
                    printf("queue is Full\n");
                }
                else
                {
                    printf("Not Full\n");
                }
            }
            else if (ch == 6)
            {
                printf("Thanks Program By Harsh Goyal\n");
                break;
            }
            else
            {
                printf("Wrong Choice\n");
            }
        }
    }
    return 0;
}