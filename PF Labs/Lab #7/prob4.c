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
    
    printf("The matrix is : ");
    MatrixMaker(matrix);
    printf("The transpose of the following matrix is : ");
    MatrixMaker(matrix_transpose);

    if (TransposeChecker(matrix,matrix_transpose) == 1)
        printf("\nThe matrix is symmetric");
    else
        printf("\nThe matrix is not symmetric");



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

int TransposeChecker(int matrix[m][n], int matrix_transpose[m][n])
{
    int transpose = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != matrix_transpose[i][j])
            {
                transpose = 0;
                break;
            }
        }
    }
    
    return transpose;
}