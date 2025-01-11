#include <iostream>
#include <cmath>
using namespace std;

class ComplexNumber
{
    private:
        float real;
        float img;

    public:
        void setIMG(float imag)
        {img = imag;}
        void setREAL(float re)
        {real = re;}
        float getIMG()
        {return img;}
        float getREAL()
        {return real;}

        void print()
        {
            cout<<real;
            if (img < 0)
                cout<<" - "<<abs(img)<<"i"<<endl;
            else
                cout<<" + "<<img<<"i"<<endl;
        }

};


int main()
{
    ComplexNumber c1;
    c1.setIMG(-5);
    c1.setREAL(10);
    c1.print();
}