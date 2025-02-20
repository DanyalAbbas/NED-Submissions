#include <iostream>
using namespace std;

class ComplexNumber
{
    private:
        float real, img;
    public:
        ComplexNumber(float r=0, float i=0) : real(r), img(i)
        {
            cout<<"Default/Parameterized constructor invoked"<<endl;
        }

        ComplexNumber(const ComplexNumber &obj)
        {
            real = obj.real;
            img = obj.img;
            cout<<"Copy constructor invoked"<<endl;
        }

        ComplexNumber Add(const ComplexNumber &c1)
            {
                ComplexNumber temp;
                temp.real = real + c1.real;
                temp.img = img + c1.img;
                return temp;
            }
        ComplexNumber Add(const ComplexNumber &c1, const ComplexNumber &c2)
            {
                ComplexNumber temp;
                temp.real = real + c1.real + c2.real;
                temp.img = img + c1.img + c2.img;
                return temp;
            }
        
        ComplexNumber operator+(const ComplexNumber &ob1)
        {
            ComplexNumber temp;
            temp.real = real + ob1.real;
            temp.img = img + ob1.img;
            return temp;
        }

        float getR() {return real;}
        float getI() {return img;}

};



int main()
{
    ComplexNumber ob2(3,4), ob3(5,6);
    

    cout<<ob2.getR()<<" "<<ob2.getI()<<endl;
    
}