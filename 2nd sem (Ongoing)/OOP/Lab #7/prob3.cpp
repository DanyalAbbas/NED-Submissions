#include <iostream>
using namespace std;

class Array2D {
private:
    int** arr;
    int row;
    int col;

public:

    Array2D(int r=0, int c=0) : row(r), col(c) {
        arr = new int*[row];
        for (int i = 0; i < row; i++) {
            arr[i] = new int[col];
            for (int j = 0; j < col; j++)
                arr[i][j] = 0;
        }
    }
    
    Array2D(const Array2D& test_ob) : row(test_ob.row), col(test_ob.col) {
        arr = new int*[row];
        for (int i = 0; i < row; i++) {
            arr[i] = new int[col];
            for (int j = 0; j < col; j++) {
                arr[i][j] = test_ob.arr[i][j];
            }
        }
    }

    Array2D& operator=(const Array2D& test_ob) {
        if (this == &test_ob)
            return *this;

        for (int i = 0; i < row; i++)
            delete[] arr[i];
        delete[] arr;

        row = test_ob.row;
        col = test_ob.col;

        arr = new int*[row];
        for (int i = 0; i < row; i++) {
            arr[i] = new int[col];
            for (int j = 0; j < col; j++) {
                arr[i][j] = test_ob.arr[i][j];
            }
        }

        return *this;
    }

    Array2D operator+(const Array2D& test_ob) {
        Array2D result(row, col);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                result.arr[i][j] = arr[i][j] + test_ob.arr[i][j];
        return result;
    }
    
    Array2D operator-(const Array2D& test_ob) {
        Array2D result(row, col);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                result.arr[i][j] = arr[i][j] - test_ob.arr[i][j];
        return result;
    }

    Array2D operator*(const Array2D& test_ob) {
        Array2D result(row, col);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                result.arr[i][j] = arr[i][j] * test_ob.arr[i][j];
        return result;
    }

    int* operator[](int index) {
        return arr[index];
    }

    ~Array2D() {
        for (int i = 0; i < row; i++)
            delete[] arr[i];
        delete[] arr;
    }

    void input() {
        cout << "Enter elements of " << row << "x" << col << " array:\n";
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                cin >> arr[i][j];
    }

    void print() const {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }
};
int main() {
    Array2D A(2, 2);
    Array2D B(2, 2);

    cout << "Input matrix A:\n";
    A.input();
    
    cout << "Input matrix B:\n";
    B.input();

    Array2D C = A + B;
    cout << "\nA + B = \n";
    C.print();

    Array2D D = A - B;
    cout << "\nA - B = \n";
    D.print();

    Array2D E = A * B;
    cout << "\nA * B (element-wise) = \n";
    E.print();

    cout << "\nAccessing A[1][1]: " << A[1][1] << endl;

    return 0;
}