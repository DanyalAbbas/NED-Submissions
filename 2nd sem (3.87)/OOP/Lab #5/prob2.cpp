#include <iostream>
#include <cstring>
using namespace std;

class Teacher
{
    private:
        string Name;
        int Age;
        string Institute;
    public:
        Teacher(string n="Anonymous", int a=0, string i="ABC University")
        {
            Name = n;
            Age = a;
            Institute = i;
        }

        string getName() {return Name;}
        int getAge() {return Age;}
        string getInstitute() {return Institute;}

        void setName(string n) {Name = n;}
        void setAge(int a) {Age = a;}
        void setInstitude(string i) {Institute = i;}
};

class HumanitiesTeacher: public Teacher
{
    private:
        const string Department;
        string CourseName;
        string Designation;
    public:
        HumanitiesTeacher(string n, int a, string i, string cn, string d) : Teacher(n, a, i), Department("Humanities")
        {
            CourseName = cn;
            Designation = d;
        }
        
        string getDepartment() const {return Department;}
        string getCourseName() {return CourseName;}
        string getDesignation() {return Designation;}

        void setCourseName(string c) {CourseName = c;}
        void setDesignation(string d) {Designation = d;}
};

class ScienceTeacher: public Teacher
{
    private:
        const string Department;
        string CourseName;
        string Designation;
    public:
        ScienceTeacher(string n, int a, string i, string cn, string d) : Teacher(n, a, i), Department("Science")
        {
            CourseName = cn;
            Designation = d;
        }
        
        string getDepartment() const {return Department;}
        string getCourseName() {return CourseName;}
        string getDesignation() {return Designation;}

        void setCourseName(string c) {CourseName = c;}
        void setDesignation(string d) {Designation = d;}
};

class MathsTeacher: public Teacher
{
    private:
        const string Department;
        string CourseName;
        string Designation;
    public:
        MathsTeacher(string n, int a, string i, string cn, string d) : Teacher(n, a, i), Department("Maths")
        {
            CourseName = cn;
            Designation = d;
        }
        
        string getDepartment() const {return Department;}
        string getCourseName() {return CourseName;}
        string getDesignation() {return Designation;}

        void setCourseName(string c) {CourseName = c;}
        void setDesignation(string d) {Designation = d;}
};

int main()
{
    MathsTeacher ob1("Danyal Abbas", 20, "NEDUET", "DIC", "Lecturer");
    cout<<"Name: "<<ob1.getName()<<endl;
    cout<<"Age: "<<ob1.getAge()<<endl;
    cout<<"Institute: "<<ob1.getInstitute()<<endl;
    cout<<"Course Name: "<<ob1.getCourseName()<<endl;
    cout<<"Designation: "<<ob1.getDesignation()<<endl;

}