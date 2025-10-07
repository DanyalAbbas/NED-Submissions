#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
    private:
        char *EmployeeName = new char(10);
        int EmployeeID;
    public:
        Employee(char e[10] = "none", int id = 0) : EmployeeID(id)
        {
            strcpy(EmployeeName, e);
        }
        ~Employee()
        {
            delete[] EmployeeName;
        }

        char *getEmployeeName(void) {return EmployeeName;}
        int getEmployeeID(void) {return EmployeeID;}

        void setEmployeeName(char c[10]) {strcpy(EmployeeName, c);}
        
        void display()
        {
            cout<<"Employee Name : "<<EmployeeName<<"\nEmployee ID: "<<EmployeeID<<endl;
        }
};


int main()
{
    Employee e1("Danyal", 4332), e2("Husn", 4342), e3("Zainab", 4324);
    e1.display();e2.display();e3.display();
    e1.setEmployeeName("Salman");
    e2.setEmployeeName("Will Byers");
    e3.setEmployeeName("Johnny");
    cout<<"\nAfter Changes"<<endl;
    e1.display();e2.display();e3.display();


}