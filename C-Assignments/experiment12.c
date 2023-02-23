#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>


// Experiment 12: Implement binary search using recursion.

int binSearch(int A[],int l,int h,int x) {
    if (l>h) return -1;

    int mid = (l+h)/2;
    if (A[mid] == x) return mid;
    if (A[mid] < x) return binSearch(A,mid+1,h,x);
    return binSearch(A,l,mid-1,x);
}

void display(int A[], int n) {
    if (n == 0) {
        printf("Array is empty\n");
        return;
    }

    printf("Array is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);

    if (n<=0) return 0;

    int A[n];

    printf("Enter elements of array in non-decreasing order\n");
    int i=0;
    while (i<n) {
        printf("Input %d: ",i+1);
        scanf("%d",&A[i]);
        if (i>0 && A[i] < A[i-1]) {
            printf("Invalid input, pls enter in non-decreasing format\n");
            continue;
        }
        i++;
    }

    display(A,n);

    int exit = 0;
    while (exit == 0) {
        int ch;
        printf("\nMenu:\n1. Search an element\n2. Display\n3. Exit\nEnter a choice:");
        scanf("%d",&ch);
        switch (ch) {
        case 1:{
            int x;
            printf("Enter element to search: ");
            scanf("%d",&x);

            int index = binSearch(A,0,n-1,x);

            display(A,n);
            if (index == -1) printf("Element not found\n");
            else printf("Element at index %d\n",index);
            
            break;
        }
        case 2: {
            display(A,n);
            break;
        }
        case 3: {
            exit = 1;
            break;
        }
        default:{
            printf("Invalid Choice\n");
            break;
        }
        }
    }

    return 0;
}
