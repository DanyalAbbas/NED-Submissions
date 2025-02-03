#include <iostream>
using namespace std;

class EpicClash
{
    private:
        int *health = new(int);
        int *attackPower = new(int);
        int *defense = new(int);
    
    public:
        EpicClash(int h = 100, int a = 50, int d = 20)
        {
            *health = h;
            *attackPower = a;
            *defense = d;
        }
        EpicClash(const EpicClash &ob)
        {
            *health = *ob.health;
            *attackPower = *ob.attackPower;
            *defense = *ob.defense;
        }

        void setH(int h) {*health = h;}
        void setAP(int ap) {*attackPower = ap;}
        void setD(int d) {*defense = d;}

        int getH(void) {return *health;}
        int getAP(void) {return *attackPower;}
        int getD(void) {return *defense;}

        ~EpicClash()
        {
            delete health;
            delete attackPower;
            delete defense;
        }


};

int main(void)
{
    // via default constructor
    EpicClash ob0;
    cout<<ob0.getH()<<endl<<ob0.getAP()<<endl<<ob0.getD()<<endl<<endl;

    // via parameterized constructor
    EpicClash ob1(200, 69, 420);
    cout<<ob1.getH()<<endl<<ob1.getAP()<<endl<<ob1.getD()<<endl<<endl;

    // via copy constructor now
    EpicClash ob2(ob1);
    cout<<ob2.getH()<<endl<<ob2.getAP()<<endl<<ob2.getD()<<endl;

}