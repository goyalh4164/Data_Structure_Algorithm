// AIM : Implement Sparse Array.

#include <stdio.h>

void main()
{
    int i, j, m, n;
    int counter = 0;

    printf("\ntotal number of rows & Columns for 2D Matrix.\n");
    printf("Rows : ");
    scanf("%d", &m);
    printf("Cols : ");
    scanf("%d", &n);
    int array[m][n];

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

    
    if (counter > ((m * n) / 2))
    {
        printf("\nEntered matrix is a Sparse matrix.\n");
        printf("Reason : There are %d number of zeroes out of %d Elements.\n", counter,m*n);
        int s = (m*n) - counter;
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
        printf("Thanks Program By Harsh Goyal");
    }
    else
    {
        printf("not a sparse matrix \n");
        printf("There are %d number of zeroes out of %d Elements.", counter,m*n);
        printf("Thanks Program By Harsh Goyal");
    }    
}