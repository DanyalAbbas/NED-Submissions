#include <iostream>
using namespace std;

class base
{
    private:
        int privateInt;
    protected:
        int protectedInt;
    public:
        int publicInt;

    base(int pri=0 , int pro=0, int pub=0) : privateInt(pri), protectedInt(pro), publicInt(pub)
    {}

    int getPrivate(void) {return privateInt;}
    int getProtected(void) {return protectedInt;}
    int getPublic(void) {return publicInt;}

    void setPrivate(int p) {privateInt = p;}
    void setProtected(int p) {protectedInt = p;}
    void setPublic(int p) {publicInt = p;}

};

class childclass1: public base
{
    public:
        childclass1(int i, int j, int k) : base(i,j,k) {}
};

class childclass2: private base
{
    public:
        childclass2(int i, int j, int k) : base(i,j,k) {}
};

class childclass3: private base
{
    public:
        childclass3(int i, int j, int k) : base(i,j,k) {}
};


int main()
{
    childclass1 ob1(1,2,3);
    childclass2 ob2(4,5,6);
    childclass3 ob3(7,8,9);
}