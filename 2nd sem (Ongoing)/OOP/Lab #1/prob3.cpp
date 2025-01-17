#include <iostream>
using namespace std;

float FahToCel(float f)
{
    return (f-32)/1.8;
}

int main()
{
    cout<<FahToCel(105)<<endl;
}