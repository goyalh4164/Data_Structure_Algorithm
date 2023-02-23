#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct SparseMatrix {
    int *row_ind;
    int *col_ind;
    int *values;
    int count;
};

void insert(struct SparseMatrix* mat, int i, int j, int val);
void display(struct SparseMatrix mat);
void deleteElement(struct SparseMatrix* mat, int i, int j);

struct SparseMatrix* create() {
    struct SparseMatrix* mat = (struct SparseMatrix *)malloc(sizeof(struct SparseMatrix));

    mat->row_ind = (int *)malloc(sizeof(int)*MAX_SIZE);
    mat->col_ind = (int *)malloc(sizeof(int)*MAX_SIZE);
    mat->values = (int *)malloc(sizeof(int)*MAX_SIZE);

    printf("Enter the number of rows: ");
    scanf("%d", &mat->row_ind[0]);
    printf("Enter the number of columns: ");
    scanf("%d", &mat->col_ind[0]);


    if (mat->row_ind[0] <= 0 || mat->col_ind[0] <= 0) {
        printf("\nInvalid size\n");
        free(mat->row_ind);
        free(mat->col_ind);
        free(mat->values);
        free(mat);
        return NULL;
    }



    int value;
    printf("Initializing matrix..\n");
    for (int i=0;i<mat->row_ind[0];i++) {
        for (int j = 0; j < mat->col_ind[0]; j++) {
            printf("Enter value of row %d and column %d: ",i,j);
            scanf("%d",&value);
            if (value !=0) insert(mat,i,j,value);
        }   
    }

    display(*mat);

    if (mat->values[0] >= mat->row_ind[0]*mat->col_ind[0]/2 + mat->row_ind[0]*mat->col_ind[0]%2) {
        printf("\nThe above matrix has majority of non zero elements and is not a sparse matrix\n");
        free(mat->row_ind);
        free(mat->col_ind);
        free(mat->values);
        free(mat);
        return NULL;
    }

    return mat;
}

void insert(struct SparseMatrix* mat, int i, int j, int val) {
    if (i < 0 || i >= mat->row_ind[0] || j < 0 || j >= mat->col_ind[0]) {
        printf("Invalid indices\n");
        return;
    }


    for (int k = 1; k <= mat->values[0]; k++) {
        if (mat->row_ind[k] == i && mat->col_ind[k] == j) {
            mat->values[k] = val;
            if (val == 0) deleteElement(mat,i,j);
            return;
        }
    }

    if (val == 0) return;

    if (mat->values[0] == 99) {
        printf("Default max size reached\n");
        return;
    }

    mat->values[0]++;
    mat->row_ind[mat->values[0]] = i;
    mat->col_ind[mat->values[0]] = j;
    mat->values[mat->values[0]] = val;
}

void deleteElement(struct SparseMatrix* mat, int i, int j) {
    if (i < 0 || i >= mat->row_ind[0] || j < 0 || j >= mat->col_ind[0]) {
        printf("Invalid indices\n");
        return;
    }

    if (mat->values[0] == 0) {
        printf("Sparse matrix has no elements\n");
        return;
    }

    for (int k = 1; k <= mat->values[0]; k++) {
        if (mat->row_ind[k] == i && mat->col_ind[k] == j) {
            int temp=mat->row_ind[k];
            mat->row_ind[k] = mat->row_ind[mat->values[0]];
            mat->row_ind[mat->values[0]] = temp;

            temp=mat->col_ind[k];
            mat->col_ind[k] = mat->col_ind[mat->values[0]];
            mat->col_ind[mat->values[0]] = temp;

            temp=0;
            mat->values[k] = mat->values[mat->values[0]];
            mat->values[mat->values[0]] = temp;

            mat->values[0]--;
            return;
        }
    }

    printf("Element not found\n");
}

void display(struct SparseMatrix mat) {
    printf("Sparse Array: \n");

    printf("Row  Col  Value\n");
    for (int k=0;k<=mat.values[0];k++) {
        printf("%d    %d    %d\n",mat.row_ind[k],mat.col_ind[k],mat.values[k]);
    }

    printf("There are %d non zero elements in matrix\n",mat.values[0]);
}

int main(){
    struct SparseMatrix *mat = create();

    if (mat == NULL) return 0;

    int choice = 1;

    while (choice != 4) {
        printf("\nMenu:\n1. Insert an element\n2. Delete an element\n3. Display the matrix\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int i, j, val;
                printf("Enter the row index: ");
                scanf("%d", &i);
                printf("Enter the column index: ");
                scanf("%d", &j);
                printf("Enter the value: ");
                scanf("%d", &val);
                insert(mat, i, j, val);
                display(*mat);
                break;
            }
            case 2:{
                int i, j;
                printf("Enter the row index: ");
                scanf("%d", &i);
                printf("Enter the column index: ");
                scanf("%d", &j);
                deleteElement(mat, i, j);
                display(*mat);
                break;
            }
            case 3:
                display(*mat);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

    }

    return 0;
}