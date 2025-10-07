#include<iostream>
using namespace std;

class Store{
    protected:
        double tot_bill;
    public:
        Store(double tot = 0): tot_bill(tot){

        }
        ~Store(){

        }
        virtual double Discounted_Bill() = 0;
};

class BinHashim_Store: public Store{
    public:
        BinHashim_Store(double tot = 0): Store(tot){

        }
        ~BinHashim_Store(){

        }
        double Discounted_Bill() override{
            tot_bill = tot_bill - (tot_bill*0.05);
            return tot_bill;
        }
};
class Imtiaz_store: public Store{
    public:
        Imtiaz_store(double tot=0) : Store(tot){

        }
        ~Imtiaz_store(){

        }
        double Discounted_Bill() override{
            tot_bill = tot_bill - (tot_bill * 0.07);
            return tot_bill;
        }

};

int main() {
   
    BinHashim_Store binStore(10000.0);
    cout << "BinHashim Store - Discounted Bill: " << binStore.Discounted_Bill() << endl;


    Imtiaz_store imtiazStore(10000.0);
    cout << "Imtiaz Store - Discounted Bill: " << imtiazStore.Discounted_Bill() << endl;

    return 0;
}