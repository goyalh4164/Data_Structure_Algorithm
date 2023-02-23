#include <stdio.h>
#include <stdbool.h>

// Experiment 1: Implement operations (traverse, insert, delete, linear search, selection sort) on an array.

void display(int A[], int size)
{
    if (size == 0)
    {
        printf("Array is empty\n");
        return;
    }

    printf("Array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\nSize of array: %d\n", size);
}

bool insertAtBegin(int A[], int size, int maxSize, int item) // Returns true if inserted successfully
{
    if (size == maxSize)
    {
        printf("Array is full\n");
        return false;
    }

    // Moving all elements forward
    for (int i = size; i > 0; i--)
    {
        A[i] = A[i - 1];
    }
    A[0] = item; // Inserting element
    printf("Inserted Successfully\n");
    return true;
}

bool insertAtPos(int A[], int size, int maxSize, int pos, int item) // Returns true if inserted successfully
{
    if (size == maxSize)
    {
        printf("Array is full\n");
        return false;
    }
    if (size < pos || pos < 0)
    {
        printf("Invalid Position");
        return false;
    }

    // Moving elements from given position to end one space forward
    for (int i = size; i > pos; i--)
    {
        A[i] = A[i - 1];
    }
    A[pos] = item; // Inserting element
    printf("Inserted Successfully\n");
    return true;
}

bool insertAtLast(int A[], int size, int maxSize, int item) // Returns true if inserted successfully
{
    if (size == maxSize)
    {
        printf("Array is full\n");
        return false;
    }

    A[size] = item; // Inserting element
    printf("Inserted Successfully\n");
    return true;
}

bool deleteAtBegin(int A[], int size, int item) // Returns true if deleted successfully
{
    if (size == 0)
    {
        printf("Array is empty\n");
        return false;
    }

    for (int i = 0; i < size - 1; i++)
    {
        A[i] = A[i + 1];
    }
    printf("Deleted Successfully\n");
    return true;
}

bool deleteAtPos(int A[], int size, int pos) // Returns true if deleted successfully
{
    if (size == 0)
    {
        printf("Array is empty\n");
        return false;
    }
    if (size < pos || pos < 0)
    {
        printf("Invalid Position");
        return false;
    }

    for (int i = pos; i < size - 1; i++)
    {
        A[i] = A[i + 1];
    }

    printf("Deleted Successfully\n");
    return true;
}

bool deleteAtLast(int A[], int size, int item) // Returns true if deleted successfully
{
    if (size == 0)
    {
        printf("Array is empty\n");
        return false;
    }

    printf("Deleted Successfully\n");
    return true;
}

int linearSearch(int A[], int size, int item)
{
    for (int i = 0; i < size; i++)
    {
        if (item == A[i])
        {
            return i; // Return index of element
        }
    }
    return -1; // Return -1 if element not found
}

void selectionSort(int A[], int size) // Modifies the array directly since call by address
{
    int i, j, k;
    for (i = 0; i < size - 1; i++)
    {
        for (j = k = i; j < size; j++)
        {
            if (A[j] < A[k])
                k = j;
        }
        int temp = A[k];
        A[k] = A[i];
        A[i] = temp;
    }
    printf("Done!\n");
}

int main()
{
    int maxSize, curSize = 0;
    printf("Enter max size of array: ");
    scanf("%d", &maxSize);

    if (maxSize <= 0)
    {
        printf("An array cant have negative or zero length");
        return 0;
    }

    bool exit = false, check;
    int A[maxSize];
    while (!exit)
    {
        int ch;
        printf("\n1.Display Array\n2.Insert\n3.Delete\n4.Search\n5.Sort\n6.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: // Display
        {
            display(A, curSize);
            break;
        }
        case 2: // Insert
        {
            int item, x;
            printf("Enter item: ");
            scanf("%d", &item);
            if (curSize == 0) // If empty array then directly insert element
            {
                check = insertAtBegin(A, curSize, maxSize, item);
                if (check) // Update size if successfully inserted
                    curSize++;
                display(A,curSize);
                break;
            }
            printf("1.Begin\n");
            printf("2.End\n");
            if (curSize != 1)
                printf("3.Locn\n");
            printf("Enter your choice: ");
            scanf("%d", &x);
            if (x == 1)
            {
                check = insertAtBegin(A, curSize, maxSize, item);
            }
            else if (x == 2)
            {
                check = insertAtLast(A, curSize, maxSize, item);
            }
            else if (curSize != 1 && x == 3)
            {
                int locn;
                printf("Enter locn: ");
                scanf("%d", &locn);
                check = insertAtPos(A, curSize, maxSize, locn, item);
            }
            else
            {
                check = false;
                printf("Invalid Choice\n");
            }
            if (check) // Update size if successfully inserted
                curSize++;
            display(A,curSize);
            break;
        }
        case 3: // Delete
        {
            int x;
            if (curSize <= 1)
            {
                check = deleteAtBegin(A, curSize, maxSize);
                if (check) // Update size if successfully deleted
                    curSize--;
                break;
            }
            printf("1.Begin\n");
            printf("2.End\n");
            if (curSize > 2)
                printf("3.Locn\n");
            printf("Enter your choice: ");
            scanf("%d", &x);
            if (x == 1)
            {
                check = deleteAtBegin(A, curSize, maxSize);
            }
            else if (x == 2)
            {
                check = deleteAtLast(A, curSize, maxSize);
            }
            else if (curSize >= 3 && x == 3)
            {
                int locn;
                printf("Enter locn: ");
                scanf("%d", &locn);
                check = deleteAtPos(A, curSize, locn);
            }
            else
            {
                check = false;
                printf("Invalid Choice\n");
            }
            if (check) // Update size if successfully deleted
                curSize--;
            display(A,curSize);
            break;
        }
        case 4: // Search
        {
            int item, x;
            printf("Enter item: ");
            scanf("%d", &item);
            int index = linearSearch(A, curSize, item);
            if (index == -1)
                printf("Element Not Found\n");
            else
                printf("Element is at index %d\n", index);
            display(A,curSize);
            break;
        }
        case 5: // Sort
        {
            selectionSort(A, curSize);
            display(A,curSize);
            break;
        }
        default: // For Invalid Choice
        {
            exit = true;
            break;
        }
        }
    }
    return 0;
}