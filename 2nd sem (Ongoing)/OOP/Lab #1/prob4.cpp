#include <iostream>
using namespace std;

int **Addition(int m1[3][3], int m2[3][3]);
int **Multiply(int m1[3][3], int m2[3][3]);
void MatrixMaker(int **matrix);

int main()
{
    int matrix1[3][3], matrix2[3][3];

    // For matrix no: 1
    cout<<"MATRIX #1"<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<"Enter the value ("<<i+1<<", "<<j+1<<") : ";
            cin>>matrix1[i][j];
        }
    }

    // For matrix no: 2
    cout<<"MATRIX #2"<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<"Enter the value ("<<i+1<<", "<<j+1<<") : ";
            cin>>matrix2[i][j];
        }
    }
    
    int **result = Addition(matrix1, matrix2);
    MatrixMaker(result);
    int **result2 = Multiply(matrix1, matrix2);
    MatrixMaker(result2); 
    
}

// double pointer (**) means pointer to a pointer :3
int **Addition(int m1[3][3], int m2[3][3])
{
    int **AddedMatrix = new int*[3];
    for (int i = 0; i < 3; i++)
    {
        AddedMatrix[i] = new int[3];
        for (int j = 0; j < 3; j++)
        {
            AddedMatrix[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return AddedMatrix;
}

int **Multiply(int m1[3][3], int m2[3][3])
{
    int **MultipliedMatrix = new int*[3];
    for (int i = 0; i < 3; i++)
    {
        MultipliedMatrix[i] = new int[3];
        for (int j = 0; j < 3; j++)
        {
            MultipliedMatrix[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                MultipliedMatrix[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return MultipliedMatrix;
}


// just for my own readibility
void MatrixMaker(int **matrix)
{
    cout<<"\n";
    for (int i = 0; i < 3; i++)
    {
        cout<<"| ";
        for (int j = 0; j < 3; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"|\n";
    }
}