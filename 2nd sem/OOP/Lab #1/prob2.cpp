#include <iostream>
using namespace std;

void swap(int &a, int &b, int &c)
{
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main()
{
    int x = 1, y = 2, z = 3;
    cout<<x<<" "<<y<<" "<<z<<endl;
    swap(x,y,z);
    cout<<x<<" "<<y<<" "<<z<<endl;
}