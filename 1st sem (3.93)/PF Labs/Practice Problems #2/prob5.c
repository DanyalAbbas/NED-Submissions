#include <stdio.h>
int m, n;

int main()
{
    printf("Enter the no. of rows and columns for the square matrix : ");
    scanf("%d", &m);
    n = m;

    int matrix[m][n], matrix_transpose[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter the (%d,%d) element value of matrix : ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
            matrix_transpose[j][i] = matrix[i][j];
            
        }
    }
    MatrixMaker(matrix);
    MatrixMaker(matrix_transpose);
}

int MatrixMaker(int matrix[m][n])
{
    printf("\n");
    for (int i = 0; i < m; i++)
    {
        matrix[m][n];
        printf("| ");
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("|\n");
    }
}