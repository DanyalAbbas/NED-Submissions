#include <iostream>
#include <cstring>
using namespace std;

class item
{
    private:
        string Name;
        int Quantity;
    public:
        item(string n="Anonymous", int q=0) : Name(n), Quantity(q)
        {}
        
        string getName() {return Name;}
        int getQuantity() {return Quantity;}

        void setName(string n) {Name = n;}
        void setQuantity(int q) {Quantity = q;}
};

class BakedGoods: public item
{
    protected:
        float Discount;
    public:
    BakedGoods(string n, int q) : item(n,q), Discount(10) {}

    float getDiscount() {return Discount;}

};

class Cakes: public BakedGoods
{
    private:
        float price;
    public:
        Cakes(string n, int q) : BakedGoods(n,q), price(600) {}

        float getPrice() {return price;}
        float getDiscountedPrice() {return price - (price *(Discount/100));}
};

class Bread: public BakedGoods
{
    private:
    float price;
    public:
        Bread(string n, int q) : BakedGoods(n,q), price(200) {}

        float getPrice() {return price;}
        float getDiscountedPrice() {return price - (price *(Discount/100));}
};

class Drinks: public item
{
    private:
        float Discount;
        float price;
    public:
        Drinks(string n, int q) : item(n,q), Discount(5), price(100) {}
    
        float getDiscount() {return Discount;}
        float getPrice() {return price;}
        float getDiscountedPrice() {return price - (price *(Discount/100));}
};

int main()
{
    Bread ob1("Milky Bread", 50);
    Drinks ob2("Prime Hydration", 20);
    Cakes ob3("Coffee Cake", 6);

    cout<<"The Discounted price for "<<ob1.getName()<<" is "<<ob1.getDiscountedPrice()<<" Rs After Discount of "<<ob1.getDiscount()<<"%"<<endl;
    cout<<"The Discounted price for "<<ob2.getName()<<" is "<<ob2.getDiscountedPrice()<<" Rs After Discount of "<<ob2.getDiscount()<<"%"<<endl;
    cout<<"The Discounted price for "<<ob3.getName()<<" is "<<ob3.getDiscountedPrice()<<" Rs After Discount of "<<ob3.getDiscount()<<"%"<<endl;

}