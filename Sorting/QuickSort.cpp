#include<bits/stdc++.h>
using namespace std;
int partition(int * arr,int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            //swap
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    i++;
    int temp=arr[i];
    arr[i]=pivot;
    arr[high]=temp;
    return i;  //return 
}
void quickSort(int * arr,int low,int high){
    if(low>=high) return;
    int pidx=partition(arr,low,high);
    quickSort(arr,low,pidx-1);
    quickSort(arr,pidx+1,high);
}
int main()
{
    int arr[]={1,5,2,4,3};
    quickSort(arr,0,4);
    for(int i =0;i<5;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}
//Worst = O(n^2) --> it occurs when the given array is sorted already 
//Average =O(nlog(n)) 
//Quicksort is better then merge sort in case of space complexity