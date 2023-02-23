#include <stdio.h>
#include <malloc.h>

// Experiment 17: Implement operations on Binary Search Tree (Insertion, Deletion, Search, Traversals (using recursion)- Inorder, Preorder, Postorder).

struct node {
    int val;
    struct node* left;
    struct node* right;
};

struct node* insertBST(struct node* cur,int val) {
    if (cur == NULL) {
        struct node* p = (struct node*)malloc(sizeof(struct node));
        p->val = val;
        p->left = NULL;
        p->right = NULL;
        return p;
    }

    if (cur->val > val) cur->left = insertBST(cur->left,val);
    if (cur->val <= val) cur->right = insertBST(cur->right,val);
    return cur;
}

struct node* deleteBST(struct node* cur,int val) {
    if (cur == NULL) return NULL;

    if (cur->val == val) {
        if (cur->left == NULL && cur->right == NULL) {
            free(cur);
            return NULL;
        }

        if (cur->left != NULL) {
            struct node* leftLargest=cur->left;
            while (leftLargest->right != NULL)
                leftLargest = leftLargest->right;
            cur->val = leftLargest->val;
            cur->left = deleteBST(cur->left,leftLargest->val);
            return cur;
        }
        
        struct node* rightSmallest=cur->right;
        while (rightSmallest->left != NULL)
            rightSmallest = rightSmallest->left;
        cur->val = rightSmallest->val;
        cur->right = deleteBST(cur->right,rightSmallest->val);
        return cur;
    }

    if (cur->val > val) cur->left = deleteBST(cur->left,val);
    if (cur->val < val) cur->right = deleteBST(cur->right,val);
    return cur;
}

int searchBST(struct node* cur,int elem) {
    if (cur == NULL) return 0;

    if (cur->val > elem) return searchBST(cur->left,elem);
    if (cur->val < elem) return searchBST(cur->right,elem);
    return 1;
}

void preorder(struct node* cur) {
    if (cur == NULL) return;

    printf("%d ",cur->val);
    preorder(cur->left);
    preorder(cur->right);
}

void inorder(struct node* cur) {
    if (cur == NULL) return;

    inorder(cur->left);
    printf("%d ",cur->val);
    inorder(cur->right);
}

void postorder(struct node* cur) {
    if (cur == NULL) return;

    postorder(cur->left);
    postorder(cur->right);
    printf("%d ",cur->val);
}

int main() {
    struct node* root = NULL;

    int ch=1;
    while (ch != 7) {
        printf("\nMenu:\n1. Insert\n2. Delete\n3. Preorder\n4. Inorder\n5. Postorder\n6. Search\n7. Exit\nEnter your choice: ");
        scanf("%d",&ch);

        switch (ch) {
        case 1: {
            int elem;
            printf("Enter element to insert: ");
            scanf("%d",&elem);
            root = insertBST(root,elem);
            break;
        }
        case 2: {
            int elem;
            printf("Enter element to delete: ");
            scanf("%d",&elem);
            root = deleteBST(root,elem);
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
        case 6:{
            int elem;
            printf("Enter element to search: ");
            scanf("%d",&elem);
            int ch = searchBST(root,elem);
            if (ch == 1) printf("Element found\n");
            else printf("Element not found\n");
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