/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include<stdio.h>
#define MAX 100

void multiply_and_display(int r1, int c1, int r2, int c2, int A[r1][c1], int B[r2][c2])
{
	
	int C[MAX][MAX], i, j, k;
	
	printf("\n <<<<< MATRIX A >>>>> \n");
	for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
            printf(" %d  ", A[i][j]);

        printf("\n");
    }
	
	printf("\n <<<<< MATRIX B >>>>> \n");
	for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
            printf(" %d  ", B[i][j]);

        printf("\n");
    }
    
    for (i = 0; i < r1; i++) 
	{
        for (j = 0; j < c2; j++) 
		{
            C[i][j] = 0;
            for (k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
	}
	
	printf("\n <<<<< MATRIX C >>>>> \n");
	for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
            printf(" %d  ", C[i][j]);

        printf("\n");
    }
}

int main()
{
	int row_1, col_1, row_2, col_2, i, j;
	printf("\n ***** NAME - ADVAIT MARATHE *****\n");
	printf("\n ***** REG -  18BEE0164      *****\n");
	printf("\n ***** Matrix Multiplication ***** \n\n");
	input_rc:
	{
		printf(" Enter the rows for Matrix A - ");
		scanf("%d", &row_1);
		printf(" Enter the columns for Matrix A - ");
		scanf("%d", &col_1);
		printf(" Enter the rows for Matrix B - ");
		scanf("%d", &row_2);
		printf(" Enter the colums for Matrix B - ");
		scanf("%d", &col_2);		
	}
	if(col_1 != row_2)
	{
		printf("\n\n !!!!! NOT POSSIBLE !!!!! \n\n");
		goto input_rc;
	}
	
	int A[row_1][col_1], B[row_2][col_2];
	
	printf("\n Enter the elements for Matrix A - \n");
	for(i = 0; i < row_1; i++)
	{
		for(j = 0; j < col_1; j++)
		{
			printf(" Enter the element [%d][%d] - ",i+1, j+1);
			scanf("%d", &A[i][j]);
		}
	}
	
	printf("\n Enter the elements for Matrix B - \n");
	for(i = 0; i < row_2; i++)
	{
		for(j = 0; j < col_2; j++)
		{
			printf(" Enter the element [%d][%d] - ",i+1, j+1);
			scanf("%d", &B[i][j]);
		}
	}
	
	multiply_and_display(row_1, col_1, row_2, col_2, A, B);
	return(0);
} 
