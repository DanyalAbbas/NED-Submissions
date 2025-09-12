#include <iostream>
using namespace std;

class Circle
{
    private:
        const float PI;
        float radius;
    public:
        Circle(float r=0) : PI(3.142), radius(r) {}

        float getPI(void) const {return PI;}
};

int main()
{
    Circle ob1(20);
    cout<<ob1.getPI()<<endl;
}