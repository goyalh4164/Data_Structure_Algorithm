#include <stdio.h>
#include <malloc.h>

// Experiment 8: Implement addition of two polynomial expressions using singly linked list.

struct node {
    int coeff,exp;
    struct node *next;
};

void display(struct node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    printf("(%d)x^(%d) ",head->coeff,head->exp);
    head = head->next;
    while (head != NULL) {
        if (head->exp == 0) printf("+ (%d) ",head->coeff);
        else printf("+ (%d)x^(%d) ",head->coeff,head->exp);
        head = head->next;
    }
    printf("\n");
}

struct node* addition(struct node* x1, struct node* x2) {
    if (x1 == NULL || x2 == NULL) return (x1 != NULL ? x1 : x2);

    struct node* head=(struct node*)malloc(sizeof(struct node));
    head->next = NULL;
    if (x1->exp > x2->exp) {
        head->exp = x1->exp;
        head->coeff = x1->coeff;
        x1 = x1->next;
    } else if (x1->exp < x2->exp) {
        head->exp = x2->exp;
        head->coeff = x2->coeff;
        x2 = x2->next;
    } else {
        head->exp = x1->exp;
        head->coeff = x1->coeff+x2->coeff;
        x1 = x1->next;
        x2 = x2->next;
    }

    struct node* last = head;
    while (x1 != NULL && x2 != NULL) {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->next = NULL;

        if (x1->exp > x2->exp) {
            temp->exp = x1->exp;
            temp->coeff = x1->coeff;
            x1 = x1->next;
        } else if (x1->exp < x2->exp) {
            temp->exp = x2->exp;
            temp->coeff = x2->coeff;
            x2 = x2->next;
        } else {
            temp->exp = x1->exp;
            temp->coeff = x1->coeff+x2->coeff;
            x1 = x1->next;
            x2 = x2->next;
        }

        last->next = temp;
        last = last->next;
    }
    
    if (x1 != NULL) {
        while (x1 != NULL) {
            struct node* temp = (struct node*)malloc(sizeof(struct node));
            temp->next = NULL;
            temp->exp = x1->exp;
            temp->coeff = x1->coeff;
            x1 = x1->next;
            
            last->next = temp;
            last = last->next;
        }
    } else if (x2 != NULL) {
        while (x2 != NULL) {
            struct node* temp = (struct node*)malloc(sizeof(struct node));
            temp->next = NULL;
            temp->exp = x2->exp;
            temp->coeff = x2->coeff;
            x2 = x2->next;
            
            last->next = temp;
            last = last->next;
        }
    }

    return head;
}

struct node* create() {
    struct node* head,*last;
    head=last=NULL;

    int ch=1;
    while (ch == 1) {
        int exp;
        printf("Enter exponent: ");
        scanf("%d",&exp);

        if (last != NULL && last->exp <= exp) {
            printf("Pls enter expression in decreasing exponent\n");
            display(head);
            continue;
        }

        int coeff;
        printf("Enter coefficient: ");
        scanf("%d",&coeff);

        struct node* q = (struct node*)malloc(sizeof(struct node));
        q->exp = exp;
        q->coeff = coeff;
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
    printf("For 1st polynomial..\n");
    struct node* head1= create();

    printf("\nFor 2nd polynomial..\n");
    struct node* head2 = create();

    struct node* head = addition(head1,head2);
    printf("\n\nNow adding both polynomials\n");
    printf("Polynomial 1: ");
    display(head1);
    printf("Polynomial 2: ");
    display(head2);
    printf("\nAfter addition: ");
    display(head);

    return 0;
}