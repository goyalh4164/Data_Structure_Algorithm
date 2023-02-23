#include <stdio.h>
#include <malloc.h>

#define STACK_MAX_SIZE 100

// Experiment 18: Implement operations on Binary Search Tree (Insertion, Deletion, Search, Traversals (using stacks)- Inorder, Preorder, Postorder).

struct node
{
    int val;
    struct node *left;
    struct node *right;
};

struct nodeForSingleStack
{
    struct node *val;
    struct nodeForSingleStack *next;
};

// Functions and struct of stack

struct singleStack
{
    struct nodeForSingleStack *top;
};

int isEmptySingleStack(struct singleStack *stk)
{
    if (stk->top == NULL)
        return 1;
    return 0;
}

void pushSingleStack(struct singleStack *stk, struct node *elem)
{
    struct nodeForSingleStack *p = (struct nodeForSingleStack *)malloc(sizeof(struct nodeForSingleStack));
    if (p == NULL)
        return;
    p->val = elem;
    p->next = stk->top;
    stk->top = p;
}

struct node *popSingleStack(struct singleStack *stk)
{
    if (isEmptySingleStack(stk))
    {
        return NULL;
    }

    struct nodeForSingleStack *p = stk->top;
    stk->top = stk->top->next;
    struct node *elem = p->val;
    free(p);
    return elem;
}

struct nodeForDualStack
{
    struct node *val;
    int status;
    struct nodeForDualStack *next;
};

// Functions and struct of stack

struct dualStack
{
    struct nodeForDualStack *top;
};

int isEmptyDualStack(struct dualStack *stk)
{
    if (stk->top == NULL)
        return 1;
    return 0;
}

void pushDualStack(struct dualStack *stk, struct node *elem, int status)
{
    struct nodeForDualStack *p = (struct nodeForDualStack *)malloc(sizeof(struct nodeForDualStack));
    if (p == NULL)
        return;
    p->val = elem;
    p->status = status;
    p->next = stk->top;
    stk->top = p;
}

struct nodeForDualStack *popDualStack(struct dualStack *stk)
{
    if (isEmptyDualStack(stk))
        return NULL;

    struct nodeForDualStack *p = stk->top;
    stk->top = stk->top->next;
    return p;
}

struct node *insertBST(struct node *cur, int val)
{
    if (cur == NULL)
    {
        struct node *p = (struct node *)malloc(sizeof(struct node));
        p->val = val;
        p->left = NULL;
        p->right = NULL;
        return p;
    }

    if (cur->val > val)
        cur->left = insertBST(cur->left, val);
    if (cur->val <= val)
        cur->right = insertBST(cur->right, val);
    return cur;
}

struct node *deleteBST(struct node *cur, int val)
{
    if (cur == NULL)
        return NULL;

    if (cur->val == val)
    {
        if (cur->left == NULL && cur->right == NULL)
        {
            free(cur);
            return NULL;
        }

        if (cur->left != NULL)
        {
            struct node *leftLargest = cur->left;
            while (leftLargest->right != NULL)
                leftLargest = leftLargest->right;
            cur->val = leftLargest->val;
            cur->left = deleteBST(cur->left, leftLargest->val);
            return cur;
        }

        struct node *rightSmallest = cur->right;
        while (rightSmallest->left != NULL)
            rightSmallest = rightSmallest->left;
        cur->val = rightSmallest->val;
        cur->right = deleteBST(cur->right, rightSmallest->val);
        return cur;
    }

    if (cur->val > val)
        cur->left = deleteBST(cur->left, val);
    if (cur->val < val)
        cur->right = deleteBST(cur->right, val);
    return cur;
}

void preorder(struct node *root)
{
    struct singleStack s;
    s.top = NULL;

    struct node *cur = root;
    while (cur != NULL || !isEmptySingleStack(&s))
    {
        if (cur != NULL)
        {
            printf("%d ", cur->val);
            pushSingleStack(&s, cur);
            cur = cur->left;
            continue;
        }

        cur = popSingleStack(&s);
        cur = cur->right;
    }
}

void inorder(struct node *root)
{
    struct singleStack s;
    s.top = NULL;

    struct node *cur = root;
    while (cur != NULL || !isEmptySingleStack(&s))
    {
        if (cur != NULL)
        {
            pushSingleStack(&s, cur);
            cur = cur->left;
            continue;
        }

        cur = popSingleStack(&s);
        printf("%d ", cur->val);
        cur = cur->right;
    }
}

void postorder(struct node *root)
{
    struct dualStack s;
    s.top = NULL;

    struct node *cur = root;
    while (cur != NULL || !isEmptyDualStack(&s))
    {
        if (cur != NULL)
        {
            pushDualStack(&s, cur, 0);
            cur = cur->left;
            continue;
        }

        struct nodeForDualStack *r = popDualStack(&s);
        cur = r->val;
        if (r->status == 0)
        {
            pushDualStack(&s, cur, 1);
            cur = cur->right;
        }
        else
        {
            printf("%d ", cur->val);
            cur = NULL;
        }
        free(r);
    }
}

int main()
{
    struct node *root = NULL;

    int ch = 1;
    while (ch != 7)
    {
        printf("\nMenu:\n1. Insert\n2. Delete\n3. Preorder\n4. Inorder\n5. Postorder\n6. Search\n7. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            int elem;
            printf("Enter element to insert: ");
            scanf("%d", &elem);
            root = insertBST(root, elem);
            break;
        }
        case 2:
        {
            int elem;
            printf("Enter element to delete: ");
            scanf("%d", &elem);
            root = deleteBST(root, elem);
            break;
        }
        case 3:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;
        case 5:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;
        case 6:
        {
            int elem;
            printf("Enter element to search: ");
            scanf("%d", &elem);
            int ch = searchBST(root, elem);
            if (ch == 1)
                printf("Element found\n");
            else
                printf("Element not found\n");
        }
        case 7:
            break;
        default:
            printf("Invalid Choice");
            break;
        }
    }

    return 0;
}