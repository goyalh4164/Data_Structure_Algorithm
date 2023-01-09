#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node
{
    int data;
    struct Node * right;
    struct Node * left;
};

void preorder(struct Node * root){
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node * root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void postorder(struct Node * root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
struct Node * search(struct Node * root,int target){
    if(root==NULL) {printf("No such Node exist\n"); return NULL;}
    if(root->data==target) {return root;}
    if(root->data < target) search(root->right,target);
    if(root->data > target) search(root->left,target);
}
struct Node * insert(struct Node * root,int data){
    //Tree is empty
    if(root==NULL){
        struct Node * node=(struct Node *)malloc(sizeof(struct Node *));
        node->data=data;
        node->left=NULL;
        node->right=NULL;
        return node;
    }
    if(root->data > data) {root->left=insert(root->left,data);}
    else{root->right= insert(root->right,data);}
    return root;

}
struct Node * delete(struct Node * root,int data){
    if(root== NULL){
        return NULL;
    }
    if(data > root->data){
        root->right=delete(root->right,data);
        return root;
    }
    else if(data < root->data){
        root->left=delete(root->left,data);
        return root;
    }
    else{
        if(root->left == NULL && root->right == NULL){
            
            return NULL;
        }
        else if(root->left == NULL){
            struct Node * temp=root->right;
            root->right=NULL;
            
            return temp;
        }
        else if(root->right ==  NULL){
            struct Node * temp=root->left;
            root->left=NULL;
            
            return temp;
        }
        else{
            struct Node * minNode=root->right;
            while(minNode->left != NULL){
                minNode=minNode->left;
            }
            int rightMin = minNode->data;
            root->data=rightMin;
            root->right=delete(root->right,rightMin);
            return root; 
        }
    }
    


}
int main()
{
    struct Node * root=NULL;
    while (true)
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Search\n");
        printf("4.Preorder\n");
        printf("5.Inorder\n");
        printf("6.Postorder\n");
        printf("7.Exit\n");
        int choice;
        scanf("%d",&choice);
        if(choice ==1){
            int n;
            scanf("%d",&n);
            root=insert(root,n);
        }
        else if(choice ==2){
            int n;
            scanf("%d",&n);
            root=delete(root,n);
        }
        else if(choice ==3){
            int n;
            scanf("%d",&n);
            struct Node * temp=search(root,n);
            if(!root) printf("Value is not Present in the tree");
            else printf("Value present");
        }
        else if (choice==4)
        {
            preorder(root);
            printf("\n");
        }
        else if (choice==5)
        {
            inorder(root);
            printf("\n");
        }
        else if (choice==6)
        {
            postorder(root);
            printf("\n");
        }
        else if(choice==7)
        {
            printf("Thanks for using the program");
            break;
        }
        else{
            printf("Wrong Input");
        }

        

    }
    
    return 0;
}