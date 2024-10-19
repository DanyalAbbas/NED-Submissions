#include <stdio.h>

int main()
{
    int m, n, ZeroCount = 0;
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    for (int i = 0; i<m; i++)
    {
        for (int j = 0; j<n; j++)
        {
            printf("Enter element (%d,%d) of matrix : ", i+1,j+1);
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 0)
            {
                ZeroCount += 1;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        printf("| ");
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("|\n");
    }






    // check if matrix is sparse or not
    if (ZeroCount > ((m*n)/2))
        printf("matrix is sparse");
    else
        printf("nuh uh");
}