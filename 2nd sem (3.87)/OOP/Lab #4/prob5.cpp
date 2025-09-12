#include <iostream>
#include <cstring>
using namespace std;

class HotelMercatoRent
{
    private:
        string CustomerName;
        float TotalRent;
        int Days;
        const float RentPerDay;
    
    public:
        HotelMercatoRent(string name="Anonymous", int d=1) : RentPerDay(1000.85), CustomerName(name), Days(d)
        {
            if (Days > 7) {TotalRent = (Days-1) * RentPerDay;}
            else {TotalRent = Days * RentPerDay;}
        }

        float getRent() {return TotalRent;}

        void display() const
        {
            cout<<"Customer Name: "<<CustomerName<<endl;
            cout<<"Days Spent: "<<Days<<endl;
            cout<<"Total Rent: "<<TotalRent<<endl;
        }

};


int main()
{
    HotelMercatoRent ob1("Danyal Abbas", 8);
    // cout<<ob1.getRent()<<endl;
    ob1.display();
}