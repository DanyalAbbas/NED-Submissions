#include <iostream>
using namespace std;

class TollBooth
{
    int *TotalCars = new(int);
    double *CashCollected = new(double);
    public:
        TollBooth(void)
        {
            *TotalCars = 0;
            *CashCollected = 0;
        }
        void payingCar(void)
        {
            (*TotalCars)++;
            *CashCollected += 0.50;
        }
        void carPass(void) {payingCar();}

        void display(void)
        {
            cout<<"Total cars passed : "<<*TotalCars<<endl;
            cout<<"Total cash collected : "<<*CashCollected<<endl;
        }
        ~TollBooth()
        {
            delete TotalCars;
            delete CashCollected;
        }
        
};

int main()
{
    TollBooth ob1;
    ob1.display();
    ob1.carPass();
    ob1.carPass();
    ob1.carPass();
    ob1.carPass();
    ob1.display();
}