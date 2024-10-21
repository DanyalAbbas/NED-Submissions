#include <stdio.h>
int m, n;
int row = NULL, column = NULL;

int main()
{
    m = 3, n = 3;
    int matrix[m][n];
    int num = 5;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter the (%d,%d) element value of matrix : ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    MatrixMaker(matrix);
    if (SearchElement(num, matrix) == 1)
        printf("\nelement found at (%d,%d)", row, column);
    else
        printf("\nNUH UH");
    
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

int SearchElement(int num, int matrix[m][n])
{
    int found = 0;
    for (int i = 0; i < m; i++)
    {
        
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == num)
            {
                row = i+1;
                column = j+1;
                found = 1;
                return found;
            }
        }
    }

    return found;

}