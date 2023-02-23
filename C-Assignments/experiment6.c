#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

// Experiment 6: Write a program to count the number of nodes & reverse the single linked list.

struct node {
    int val;
    struct node *next;
};

void display(struct node *head) {
    if (head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }

    struct node *temp = head;
    while (temp != NULL && temp->next != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("%d\n",temp->val);
}

struct node *insertAtBegin(struct node *head, int val) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->val = val;
    p->next = head;
    printf("Inserted Successfully\n");
    display(p);
    return p;
}

struct node *insertAtEnd(struct node *head, int val) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->val = val;
    p->next = NULL;

    if (head == NULL) {
        printf("Inserted Successfully\n");
        display(p);
        return p;
    }

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = p;

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
    while (temp != NULL && temp->val != loc) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("No such node with given loc\n");
        display(head);
        return head;
    }

    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->val = val;
    p->next = temp->next;
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

    struct node *p = head;
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

    struct node *p = head, *q = NULL;
    while (p != NULL && p->next != NULL) {
        q = p;
        p = p->next;
    }

    if (p == head) {
        free(p);
        printf("Deleted Successfully\n");
        display(NULL);
        return NULL;
    }

    free(p);
    q->next = NULL;
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
    while (p != NULL && p->val != loc) {
        q = p;
        p = p->next;
    }

    if (p == NULL) {
        printf("No such node with value as given loc\n");
        display(head);
        return head;
    }

    if (p == head) return deleteFromBegin(head);

    q->next = p->next;
    free(p);
    printf("Deleted Successfully\n");
    display(head);
    return head;
}

struct node *reverse(struct node * head) {
    if (head == NULL || head->next == NULL) return head;

    struct node *p = NULL, *q = head, *r = head->next; 
    while (q != NULL) {
        q->next = p;
        p = q;
        q = r;
        if (r != NULL) r = r->next;
    }

    return p;
}

int countNodes(struct node * head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    struct node *head = NULL;
    int ch;
    bool exit = false;
    while (exit == false) {
        printf("1. Display\n2. Insert\n3. Delete\n4. Reverse\n5. Count Nodes\n6. End\nEnter your choice: ");
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
                head = reverse(head);
                display(head);
                break;
            case 5:
                printf("There are %d node(s) in the linked list\n",countNodes(head));
                break;
            case 6:
                exit = true;
                printf("Thank You! Created by Harsh Goyal");
                break;
            default:
                printf("Invalid Choice");
                break;
        }
        printf("\n");
    }

    return 0;
}