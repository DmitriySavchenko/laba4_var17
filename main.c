#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int ** mA(int rows, int cols);
int **Manually(int **matrix,int rows,int cols);
int **Auto(int **matrix,int rows,int cols);
void Dump(int **matrix,int rows,int cols);
void MaxMin(int **matrix,int rows,int cols);
void matrix_Transposed(int **matrix,int rows,int cols);
void matrixMulti(int **matrixA,int rowsA,int colsA,int **matrixB,int rowsB,int colsB);
void array();
void suma(int **matrixA,int rowsA,int colsA,int **matrixB,int rowsB,int colsB);
int main()
    {
    int task;
    int rowsA,colsA,rowsB,colsB;
    int **matrixA, **matrixB;
    printf("Enter size Matrix A (N x N)\n N = ");
    scanf("%d",&rowsA);
    printf("\n");
    colsA = rowsA;
    printf("Enter size Matrix B (N x M)\n M = ");
    scanf("%d",&colsB);
    rowsB=rowsA;
    printf("\n");
        matrixA = mA(rowsA,colsA);
        matrixB = mA(rowsB,colsB);
    printf("1.Anutomatically\n");
    printf("2.Manually\n");

    scanf("%d", &task);
    if(task == 1)
    {
        matrixA = Auto(matrixA,rowsA,colsA);
        matrixB = Auto(matrixB,rowsB,colsB);
    }
    else if(task == 2 )
    {
        printf("Matrix A: \n");
        matrixA = Manually(matrixA,rowsA,colsA);
        printf("Matrix B: \n");
        matrixB = Manually(matrixB,rowsB,colsB);
    }
    else
    {
       printf("Sorry, no such task to execute. Good buy!\n");
       return 0;
    }
    printf("Matrix A:\n");
    Dump(matrixA,rowsA,colsA);
    printf("Matrix B:\n");
    Dump(matrixB,rowsB,colsB);
    printf("1. Maximum element of matrix A\n");
    MaxMin(matrixA,rowsA,colsA);
    printf("2. Matrix B transposition.\n");
    matrix_Transposed(matrixB,rowsB,colsB);
    printf("3. Matrix production of A and B.\n");
    matrixMulti(matrixA,rowsA,colsA,matrixB,rowsB,colsB);
    printf("4. Sort array.\n");
    array();
    printf("5. Print sum of rows of matrix A and cols of B.\n");
    suma(matrixA,rowsA,colsA,matrixB,rowsB,colsB);


    return 0;
    }
    int ** mA(int rows, int cols)
{
    int i = 0;
    int **matrix = (int **)malloc(rows*sizeof(int *));
    for( i = 0; i < rows; i++)
    {
      matrix[i] = (int *)malloc(cols*sizeof(int));
    }
    return matrix;
}
int **Manually(int **matrix,int rows,int cols)
    {
    int i,j;
    for (i=0; i<rows; i++)
        {
        for(j=0; j<cols; j++)
            {
            printf("[%d][%d] = ",i+1,j+1);
            scanf("%d", &matrix[i][j]);
            printf("\n");
            }
        }
        return matrix;
    }

int **Auto(int **matrix,int rows,int cols)
    {
    srand(time(NULL));
    int i,j;
    for (i=0; i<rows; i++)
        {
        for(j=0; j<cols; j++)
            {
            matrix[i][j]=rand() % 101;
            }
        }
        return matrix;
    }
void Dump(int **matrix,int rows,int cols)
{
    int i ,j;
      for (i=0; i<rows; i++)
        {
        for(j=0; j<cols; j++)
            {
            printf("%d \t",matrix[i][j]);
            }
            printf("\n");
        }
}
void MaxMin(int **matrix,int rows,int cols)
    {
    int i,j,max,min;
    max=matrix[0][0];
    min=matrix[0][0];
    for(i=0; i<rows; i++)
        {
        for(j=0; j<cols; j++)
            {
            if(min<matrix[i][j])
                {
                min=matrix[i][j];
                }
            }
        }
    for(i=0; i<rows; i++)
        {
        for(j=0; j<cols; j++)
            {
            if(min>matrix[i][j])
                {
                min=matrix[i][j];
                }
            }
        }
    printf("max = %d\n", max);
    printf("min = %d\n", min);
    }

void matrix_Transposed(int **matrix,int rows,int cols)
    {
    int i = 0,j = 0;
    for (i = 0; i < cols; i++)
    {
        for (j = 0; j < rows; j++)
        {
           printf("%d ",matrix[j][i]);
           printf("\t");
        }
        printf("\n");
    }
    }

void matrixMulti(int **matrixA,int rowsA,int colsA,int **matrixB,int rowsB,int colsB)
    {
    int i,j,k,s;
    printf("Multiplication matrix A and B (A x B) : \n");
      for(i = 0;i < rowsA;i++)
        {
          for(j = 0;j < colsB;j++)
          {
             s = 0;
             for(k=0; k < rowsB; k++)
             {
                 s=s+matrixA[i][k]*matrixB[k][j];
             }
             printf("%d \t",s);
          }
          printf("\n");
        }
    }

void array()
{
    int l=5,i = 0,j,k;
    int arr[5];
    for (i = 0; i<l; i++)
    {
      printf("a[%d] = ",i+1);
      scanf("%d",&arr[i]);
    }
    printf("Standart: \n");
    for(i = 0;i<l;i++)
    {
      printf("%d ",arr[i]);
    }
    printf("\n");
    for(i = 0; i<l-1; i++)
    {
        for(j = 0; j<l-1; j++)
        {
          if(arr[j]<arr[j+1])
          {
            k=arr[j+1];
            arr[j] = arr[j];
            arr[j] = k;
          }
        }
    }
    printf("Max -> min: \n");
    for(i = 0;i<l;i++)
    {
      printf("%d ",arr[i]);
    }
}


void suma(int **matrixA,int rowsA,int colsA,int **matrixB,int rowsB,int colsB)
    {
    int i,j,x;
    printf("Sum rows A: \n");
    for( i = 0; i < rowsA; i++)
        {
        x = 0;
    for( j = 0; j <colsA; j++)
            {
            x+=matrixA[i][j];
            }
        printf("Row [%d] = %d \n",i+1,x);
        }
        printf("Sum cols B: \n");
    for( i = 0; i < colsB; i++)
        {
        x = 0;
        for( j = 0; j < rowsB; j++)
        {
            x+=matrixB[j][i];
        }
        printf("Col [%d] = %d \n",i+1,x);
        }
    }
