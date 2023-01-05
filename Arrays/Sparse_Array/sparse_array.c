// AIM : Implement Sparse Array.

#include <stdio.h>

void main()
{
    static int array[10][10];
    int i, j, m, n;
    int counter = 0;

    printf("\nEnter the total number of rows & Columns for 2D Matrix.\n");
    printf("Rows : ");
    scanf("%d", &m);
    printf("Columns : ");
    scanf("%d", &n);

    printf("Enter %d Elements of the matix: \n",m*n);
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &array[i][j]);
            if(array[i][j] == 0)
            {
                counter++;
            }
        }
    }

    printf("\nEntered Elements are : \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // Checking the Entered Matrix is a Sparse Matrix or Not?
    if (counter > ((m * n) / 2))
    {
        printf("\nEntered matrix is a Sparse matrix.\n");
        printf("Reason : There are %d number of zeroes out of %d Elements.\n", counter,m*n);

        // Finding Non-Zero Elements, to get No. of Columns in the Sparse Array.
        int s = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (array[i][j] != 0)
                {
                    s++;
                }
            }
        }

        // Inserting Values in the Sparse Array.
        int k = 0;
        int sparseArray[3][s];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (array[i][j] != 0)
                {
                    sparseArray[0][k] = i;
                    sparseArray[1][k] = j;
                    sparseArray[2][k] = array[i][j];
                    k++;
                }
            }
        }

        printf("\nSPARSE ARRAY : \n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < s; j++)
            {
                printf("%d ", sparseArray[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("The given matrix is not a sparse matrix \n");
        printf("Reason : There are %d number of zeroes out of %d Elements.", counter,m*n);
    }    
}