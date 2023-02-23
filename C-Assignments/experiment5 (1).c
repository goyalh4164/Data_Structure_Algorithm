#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

// Experiment 5: Implement insertion and deletion (at the beginning, at specified location, at the end) on circular double linked list.

struct node {
    int val;
    struct node *prev;
    struct node *next;
};

void display(struct node *head) {
    if (head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }

    printf("%d ", head->val);
    struct node *temp = head->next;
    while (temp != head) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

struct node *insertAtBegin(struct node *head, int val) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->val = val;

    if (head == NULL) {
        p->next = p;
        p->prev = p;
        printf("Inserted Successfully\n");
        display(p);
        return p;
    }

    head->prev->next = p;
    p->prev = head->prev;
    head->prev = p;
    p->next = head;

    printf("Inserted Successfully\n");
    display(p);
    return p;
}

struct node *insertAtEnd(struct node *head, int val) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->val = val;

    if (head == NULL) {
        p->next = p;
        printf("Inserted Successfully\n");
        display(p);
        return p;
    }

    head->prev->next = p;
    p->prev = head->prev;
    head->prev = p;
    p->next = head;

    printf("Inserted Successfully\n");
    display(head);
    return head;
}

struct node *insertAtPos(struct node *head, int val, int loc) { // To insert after a certain node with given value 
    if (head == NULL) {
        printf("No such node with given loc\n");
        return NULL;
    }

    struct node *temp = head;
    while (temp->next != head && temp->val != loc)
        temp = temp->next;

    if (temp->next == head && temp->val != loc) {
        printf("No such node with given loc\n");
        display(head);
        return head;
    }

    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->val = val;
    p->next = temp->next;
    p->prev = temp;
    p->next->prev = p;
    temp->next = p;

    printf("Inserted Successfully\n");
    display(head);
    return head;
}

struct node *deleteFromBegin(struct node *head) {
    if (head == NULL) {
        printf("Linked List is already empty");
        return head;
    }

    if (head->next == head) {
        free(head);
        printf("Deleted Successfully\n");
        display(NULL);
        return NULL;
    }

    struct node *p = head;
    head->prev->next = head->next;
    head->next->prev = head->prev;
    head = head->next;
    free(p);
    printf("Deleted Successfully\n");
    display(head);
    return head;
}

struct node *deleteFromEnd(struct node *head) {
    if (head == NULL) {
        printf("Linked List is already empty");
        return head;
    }

    if (head->next == head) { // Only one node
        free(head);
        printf("Deleted Successfully\n");
        display(NULL);
        return NULL;
    }

    struct node *p = head->prev;
    head->prev = p->prev;
    p->prev->next = head;
    free(p);
    printf("Deleted Successfully\n");
    display(head);
    return head;
}

struct node *deleteFromPos(struct node *head, int loc) { // Delete 1st node with value equal to given loc
    if (head == NULL) {
        printf("Linked List is already empty");
        return head;
    }

    struct node *p = head, *q = NULL;
    while (p->next != head && p->val != loc) {
        q = p;
        p = p->next;
    }

    if (p->next == head && p->val != loc) {
        printf("No such node with value as given loc\n");
        display(head);
        return head;
    }

    if (p == head) return deleteFromBegin(head);

    q->next = p->next;
    p->next->prev = q;
    free(p);
    printf("Deleted Successfully\n");
    display(head);
    return head;
}

int main() {
    struct node *head = NULL;
    int n;
    int ch;
    bool exit = false;
    while (exit == false) {
        printf("1. Display\n2. Insert\n3. Delete\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch) {
            case 1:
                display(head);
                break;
            case 2: {
                int val;
                printf("Enter value: ");
                scanf("%d", &val);
                if (head == NULL) {
                    head = insertAtBegin(head, val);
                    break;
                }

                int ch;
                printf("1. Begin\n2. End\n3. Locn\nEnter your choice: ");
                scanf("%d", &ch);
                if (ch == 1) head = insertAtBegin(head, val);
                else if (ch == 2) head = insertAtEnd(head, val);
                else if (ch == 3) {
                    int loc;
                    printf("Enter locn(value of node after which to insert): ");
                    scanf("%d", &loc);
                    head = insertAtPos(head, val, loc);
                } else printf("Invalid choice\n");
                break;
            }
            case 3: {
                if (head == NULL) {
                    printf("Linked List is already empty");
                    break;
                }
                int ch;
                printf("1. Begin\n2. End\n3. Locn\nEnter your choice: ");
                scanf("%d", &ch);
                if (ch == 1) head = deleteFromBegin(head);
                else if (ch == 2) head = deleteFromEnd(head);
                else if (ch == 3) {
                    int loc;
                    printf("Enter locn(value of node to delete): ");
                    scanf("%d", &loc);
                    head = deleteFromPos(head, loc);
                } else printf("Invalid choice\n");
                break;
            }
            case 4:
                exit = true;
                printf("Thank You! Created by Harsh Goyal");
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
        printf("\n");
    }

    return 0;
}