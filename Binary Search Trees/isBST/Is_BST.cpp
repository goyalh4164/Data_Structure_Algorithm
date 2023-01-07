#include<bits/stdc++.h>
#include <climits>

class Node{
    public:
    int data;
    Node * left;
    Node * right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

bool isBST(Node * root,int min=INT_MIN,int max=INT_MAX){
    if(root==NULL) return true;
    if(root->data <min ||  root->data >max){
        return false;
    }
    bool isLeftBST=isBST(root->left,min,root->data-1);
    bool isRightBST=isBST(root->right,root->data,max);
    return isLeftBST && isRightBST;
}
using namespace std;
int main()
{
    return 0;
}