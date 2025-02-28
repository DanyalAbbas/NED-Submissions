#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
    private:
        char *fname = new char[20];
        string lname;
        int salary;
    public:
    void setAll(const char f[20], string l, int s)
    {
        strcpy(fname, f);
        lname = l;
        if (salary < 0)
            {salary = 0;}
        else
            {salary = s;}
    }
    char *getFname(void)
        {return fname;}
    string getLname(void)
        {return lname;}
    int getSalary(void)
        {return salary;}
    int getYearlySalary(void)
        {return salary*12;}

    void GiveRaise(float percentage)
    {
        if (percentage > 0)
        {
            float Increase = (float)(salary*12)*(float)(percentage/100);
            salary += (int)(Increase/12);
        }
        else {cout<<"Wrong Percentage input ji >:("<<endl;}
    }
};


int main()
{
    Employee emp1, emp2;
    emp1.setAll("Danyal", "Abbas", 10000);
    // emp2.setAll("Husn", "Ur Rehman", 68999);
    emp2 = emp1;

    
    emp1.setAll("smt", "hmm", 434);
    cout<<"Salary before 10% raise : "<<emp1.getSalary()<<endl;
    // emp1.GiveRaise(10);
    cout<<"Salary after 10% raise : "<<emp2.getSalary()<<endl;




}