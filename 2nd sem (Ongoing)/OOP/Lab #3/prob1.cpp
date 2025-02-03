#include <iostream>
using namespace std;

class ComplexNumber
{
    private:
        float *real = new(float);
        float *img = new(float);
    public:
    ComplexNumber(float r = 0, float i = 0)
    {
        *real = r;
        *img = i;
    }
    ComplexNumber(const ComplexNumber &ob)
    {
        *real = *ob.real;
        *img = *ob.img;
    }

    ~ComplexNumber()
    {
        delete real;
        delete img;
    }

    void display(void)
    {
        cout<<*real;
        if(*img > 0) cout<<" + "<<*img<<"i"<<endl;
        else  cout<<" - "<<*img<<"i"<<endl;
    }
    float getR(void) {return *real;}
    float getI(void) {return *img;}
    void setR(float r) {*real = r;}
    void setI(float i) {*img = i;}

};


int main(void)
{
    ComplexNumber ob1(1,2);
    cout<<"Creating an object via parameterized constructor"<<endl;
    ob1.display();

    ComplexNumber ob2(ob1);
    cout<<"Creating an object via copy constructor"<<endl;
    ob2.display();

    ob1.setR(6);
    ob1.setI(5);
    cout<<"After changing the value of ob1"<<endl;
    cout<<"ob1 -> ";ob1.display();
    cout<<"ob2 -> ";ob2.display();
    
    

}