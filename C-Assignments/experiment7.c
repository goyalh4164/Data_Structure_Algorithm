#include <stdio.h>
#include <malloc.h>

// Experiment 7: Write a program to merge two sorted linked list and display the final sorted linked list.

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

struct node* copy(struct node * p) {
    if (p==NULL) return NULL;

    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->val = p->val;
    head->next = NULL;
    p = p->next;

    struct node* last = head;

    while (p!=NULL) {
        struct node* temp =  (struct node*)malloc(sizeof(struct node));
        temp->val = p->val;
        temp->next = NULL;
        p = p->next;
        last->next = temp;
        last = last->next;
    }

    return head;
}

struct node * merge(struct node* p, struct node* q) {
    if (p == NULL || q == NULL) return copy(p != NULL ? p : q);

    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->next = NULL;
    if (p->val  <= q->val) {
        head->val = p->val;
        p=p->next;
    } else {
        head->val = q->val;
        q = q->next;
    }

    struct node* last = head;
    while (p != NULL && q != NULL) {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->next = NULL;
        if (p->val  <= q->val) {
            temp->val = p->val;
            p=p->next;
        } else {
            temp->val = q->val;
            q = q->next;
        }
        last->next = temp;
        last = last->next;
    }

    if (p != NULL) {
        last->next = copy(p);
    }
    if (q != NULL) {
        last->next = copy(q);
    }

    return head;
}

struct node* create() {
    struct node* last,*head;
    last = head = NULL;

    int ch=1;
    while (ch == 1) {
        int val;
        printf("Enter value: ");
        scanf("%d",&val);

        if (last != NULL && last->val > val) {
            printf("Value should be greater than value of last node\n");
            display(head);
            continue;
        }

        struct node* q = (struct node*)malloc(sizeof(struct node));
        q->val = val;
        q->next = NULL; 

        if (last == NULL) {
            last = head = q;
        } else {
            last->next = q;
            last = q;
        }

        display(head);

        printf("Do u want to enter more elements(1 for yes): ");
        scanf("%d",&ch);
    }
    return head;
}


int main() {
    printf("For 1st linked list..\n");
    struct node* head1= create();

    printf("\nFor 2nd linked list..\n");
    struct node* head2 = create();

    struct node* head = merge(head1,head2);

    printf("1st linked list: ");
    display(head1);
    printf("2nd linked list: ");
    display(head2);
    printf("\nMerged linked list: ");
    display(head);

    return 0;
}