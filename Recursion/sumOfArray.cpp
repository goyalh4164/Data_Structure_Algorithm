#include<bits/stdc++.h>
using namespace std;
int summer(int arr [],int n){
    if(n==0) return 0;
    int smallOutput=arr[0];
    return smallOutput+summer(arr+1,n-1);
}
int main()
{
    int arr[]={1,3,6};
    int n=sizeof(arr)/sizeof(int);
    cout<<summer(arr,n);
    return 0;
}