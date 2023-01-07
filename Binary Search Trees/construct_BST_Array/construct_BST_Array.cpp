#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * left;
    Node * right;
    //constructor
    Node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};

Node * createBST(int low,int high,int arr[]){
    if(low>high){
        return NULL;
    }
    int mid=(low+high)/2;
    Node * node=new Node(arr[mid]);
    node->left=createBST(low,mid-1,arr);
    node->right=createBST(mid+1,high,arr);
    return node;
}

void preOrder(Node* node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    /* Convert List to BST */
    Node * root = createBST(0,n-1,arr);
    cout << "PreOrder Traversal of constructed BST \n";
    preOrder(root);
    return 0;
}