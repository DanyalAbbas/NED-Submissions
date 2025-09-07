#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int arr2D[rows][cols];
    cout << "Enter elements of 2D array:\n";
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> arr2D[i][j];

    int arr1D[rows * cols];
    int idx = 0;
    // Column Major Order
    for (int j = 0; j < cols; ++j)
        for (int i = 0; i < rows; ++i)
            arr1D[idx++] = arr2D[i][j];

    cout << "1D array in Column Major Order:\n";
    for (int i = 0; i < rows * cols; ++i)
        cout << arr1D[i] << " ";
    cout << endl;

    return 0;
}