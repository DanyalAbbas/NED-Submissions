#include <iostream>
using namespace std;

class ArrayMultiplier {
public:
    virtual void calculate() = 0; 
};

class ArrayMultiplier1D : public ArrayMultiplier {
private:
    int arr[5];
    int result = 1;
public:
    ArrayMultiplier1D() {
        cout << "Enter 5 elements for 1D array: ";
        for (int i = 0; i < 5; i++) {
            cin >> arr[i];
        }
    }

    void calculate() override {
        for (int i = 0; i < 5; i++) {
            result *= arr[i];
        }
        cout << "Product of 1D array elements: " << result << endl;
    }
};

class ArrayMultiplier2D : public ArrayMultiplier {
private:
    int arr[2][3];
    int result = 1;
public:
    ArrayMultiplier2D() {
        cout << "Enter 6 elements for 2D array (2, 3):\n";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> arr[i][j];
            }
        }
    }

    void calculate() override {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                result *= arr[i][j];
            }
        }
        cout << "Product of 2D array elements: " << result << endl;
    }
};

int main() {
    ArrayMultiplier1D obj1D;
    obj1D.calculate();

    ArrayMultiplier2D obj2D;
    obj2D.calculate();
}
