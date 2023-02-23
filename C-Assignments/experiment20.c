#include <stdio.h>
#include <malloc.h>

// Experiment 20: Make a menu driven program to perform various sorting techniques (insertion, shell, merge, heap, bubble, quick).

void insertionSort(int A[], int size);
void shellSort(int A[], int size);
void mergeSort(int A[], int size);
void heapSort(int A[], int size);
void bubbleSort(int A[], int size);
void quickSort(int A[], int size);

void swapAdd(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int A[], int size)
{

    if (size == 0)
    {

        printf("Array is empty\n");

        return;
    }

    printf("Array is: ");

    for (int i = 0; i < size; i++)

        printf("%d ", A[i]);

    printf("\nSize of array: %d\n", size);
}

// Insertion Sort

void insertionSort(int A[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1, x = A[i];
        while (j >= 0 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

// Shell Sort

void shellSort(int A[], int size)
{
    int gap, i, j, temp;
    for (gap = size / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < size; i++)
        {
            temp = A[i];
            j = i - gap;
            while (j >= 0 && A[j] > temp)
            {

                A[j + gap] = A[j];

                j -= gap;
            }
            A[j + gap] = temp;
        }
    }
}

// Merge Sort

void merge(int A[], int l, int mid, int h)
{

    int B[100];

    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= h)
    {

        if (A[i] < A[j])
            B[k++] = A[i++];

        else
            B[k++] = A[j++];
    }

    for (; i <= mid; i++)
        B[k++] = A[i++];

    for (; j <= h; j++)
        B[k++] = A[j++];

    for (i = l, k = 0; i <= h; i++, k++)
        A[i] = B[k];
}

void rMergeSort(int A[], int l, int h)
{

    if (l < h)
    {

        int mid = (l + h) / 2;

        rMergeSort(A, l, mid);

        rMergeSort(A, mid + 1, h);

        merge(A, l, mid, h);
    }
}

void mergeSort(int A[], int size)
{

    rMergeSort(A, 0, size - 1);
}

// Heap Sort

int heapSize = 0;

void insertHeap(int heap[], int key)
{

    heap[heapSize] = key;
    heapSize++;
    if (heapSize > 1)
    {

        int i = heapSize - 1;

        while (i > 0 && key > heap[(i - 1) / 2])
        {

            heap[i] = heap[(i - 1) / 2];

            i = (i - 1) / 2;
        }

        heap[i] = key;
    }
}

void deleteHeap(int heap[])
{

    int x = heap[0];

    heap[0] = heap[heapSize - 1];

    heapSize--;

    int i = 0, j = 2 * i + 1;

    while (j < heapSize)
    {

        if (heap[j + 1] > heap[j])
            j++;

        if (heap[i] < heap[j])
        {

            swapAdd(&heap[i], &heap[j]);

            i = j;

            j = 2 * i + 1;
        }
        else

            break;
    }

    heap[heapSize] = x;
}

void heapSort(int A[], int size)
{
    for (int i = 0; i < size; i++)
        insertHeap(A, A[i]);

    for (int i = 1; i < size; i++)
        deleteHeap(A);
}

// Bubble Sort

void bubbleSort(int A[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {

        for (int j = 0; j < size - 1 - i; j++)
        {

            if (A[j] > A[j + 1])
            {

                int temp = A[j];

                A[j] = A[j + 1];

                A[j + 1] = temp;
            }
        }
    }
}

// Quick Sort

int Partition(int A[], int l, int h)
{

    int Pivot = A[l];

    int i = l, j = h;

    do
    {

        do
        {
            i++;
        } while (A[i] <= Pivot);

        do
        {
            j--;
        } while (A[j] > Pivot);

        if (i < j)

            swapAdd(&A[i], &A[j]);

    } while (i < j);

    swapAdd(&A[l], &A[j]);

    return j;
}

void rQuickSort(int A[], int l, int h)
{

    int j;

    if (l < h)
    {

        j = Partition(A, l, h);

        rQuickSort(A, l, j);

        rQuickSort(A, j + 1, h);
    }
}

void quickSort(int A[], int size)
{

    A[size] = 32456;

    rQuickSort(A, 0, size);
}

int main()
{

    int size;

    printf("Enter size of array: ");

    scanf("%d", &size);

    int A[size + 1];

    for (int i = 0; i < size; i++)
    {

        printf("Enter %dth element: ", i + 1);

        scanf("%d", &A[i]);
    }

    int ch;

    printf("1. Insertion\n2. shell\n3. merge\n4. heap\n5. bubble\n6. quick\n7. Exit\nEnter your choice");

    scanf("%d", &ch);

    switch (ch)
    {

    case 1:

        insertionSort(A, size);

        break;

    case 2:

        shellSort(A, size);

        break;

    case 3:

        mergeSort(A, size);

        break;

    case 4:

        heapSort(A, size);

        break;

    case 5:

        bubbleSort(A, size);

        break;

    case 6:

        quickSort(A, size);

        break;

    case 7:

        break;

    default:

        break;
    }

    display(A, size);

    return 0;
}