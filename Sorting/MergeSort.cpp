#include<bits/stdc++.h>
void conquer(int arr[],int si,int mid,int ei){
    int * merged=new int[ei-si+1];
    int idx1=si;
    int idx2=mid+1;
    int x=0;
    while (idx1 <=mid && idx2 <=ei)
    {
        if(arr[idx1] <= arr[idx2]){
            merged[x++]=arr[idx1++];
        }
        else{
            merged[x++]=arr[idx2++];
        }
    }
    while (idx1<=mid)
    {
        merged[x++]=arr[idx1++];
    }
    while (idx2 <= ei)
    {
        merged[x++]=arr[idx2++];
    }
    for(int i=0,j=si ;i<(ei-si +1);i++,j++){
        arr[j]=merged[i];
    }
    delete [] merged;
}
void divide(int arr[],int si,int ei){
    if(si>=ei) return;
    int mid=si + (ei-si)/2;
    divide(arr,si,mid);
    divide(arr,mid+1,ei);
    conquer(arr,si,mid,ei);
}

using namespace std;
int main()
{
    int arr[]={5,4,3,2,1};
    divide(arr,0,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}