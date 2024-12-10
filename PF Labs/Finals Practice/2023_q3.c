#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matrix[4][4];
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         printf("%d, %d : ", i+1, j+1);
    //         scanf("%d", &matrix[i][j]);
    //     }
    // }
    // MatrixMaker(matrix);

    srand(time(NULL));
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 10;
        printf("%d, ", arr[i]);
    }
}

int MatrixMaker(int matrix[4][4])
{
    printf("\n");
    for (int i = 0; i < 4; i++)
    {
        printf("| ");
        if (i % 2 == 0)
            for (int j = 0; j < 4; j++)
            {
                printf("%d ", matrix[i][j]);
            }
        else
            for (int j = 3; j >= 0; j--)
            {
                printf("%d ", matrix[i][j]);
            }
        printf("|\n");
    }
}