#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    int capacity;
    int size;
    struct Node *front;
};

struct Stack *createStack(int n)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    if (!stack)
        return NULL;
    stack->capacity = n;
    stack->size = 0;
    stack->front = NULL;
    return stack;
}

bool isEmpty(struct Stack *stack)
{
    return stack->size == 0;
}
bool isFull(struct Stack *stack)
{
    return stack->size == stack->capacity;
}
void push(struct Stack *stack, int element)
{
    if (isFull(stack))
    {
        printf("Stack OverFlow\n");
        return;
    }
    // First time insertion
    if (isEmpty(stack))
    {
        struct Node *node = (struct Node *)malloc(sizeof(struct Node));
        node->data = element;
        node->next = NULL;
        stack->front = node;
        stack->size++;
        return;
    }
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = element;
    node->next = NULL;
    node->next = stack->front;
    stack->front = node;
    stack->size++;
}
void pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack UnderFlow\n");
        return;
    }
    // if we are removing the last node
    if (stack->size == 1)
    {
        printf("Poped Element is :%d\n", stack->front->data);
        stack->size--;
        stack->front = NULL;
        return;
    }
    printf("Poped Element is :%d\n", stack->front->data);
    stack->front = stack->front->next;
    stack->size--;
}
void top(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is Empty \n");
        return;
    }
    printf("Top Element is :%d\n", stack->front->data);
}

int main()
{
    printf("----------------WELCOME TO Stack PROGRAM-----------------------------------\n");
    printf("Enter the size of the stack you want: \n");
    int d;
    scanf("%d", &d);
    if (d <= 0)
    {
        printf("Invalid Size\n");
    }
    else
    {
        struct Stack *stack = createStack(d);
        while (true)
        {
            printf("Press 1 To Push in stack\n");
            printf("Press 2 To Pop in stack\n");
            printf("Press 3 To View Top in stack\n");
            printf("Press 4 To check Empty or not\n");
            printf("Press 5 To check Full or not\n");
            printf("Press 6 To Exit\n");
            int ch;
            scanf("%d", &ch);
            if (ch == 1)
            {
                int item;
                scanf("%d", &item);
                push(stack, item);
            }
            else if (ch == 2)
            {
                pop(stack);
            }
            else if (ch == 3)
            {
                top(stack);
            }
            else if (ch == 4)
            {
                if (isEmpty(stack))
                {
                    printf("Stack is Empty\n");
                }
                else
                {
                    printf("Not Empty\n");
                }
            }
            else if (ch == 5)
            {
                if (isFull(stack))
                {
                    printf("stack is Full\n");
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