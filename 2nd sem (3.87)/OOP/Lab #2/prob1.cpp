#include <iostream>
using namespace std;

class Student
{
    private:
        string name;
        int roll_no;
        int semester;
        char section;
    public:
        void set_all(string n, int r, int s, char sec)
        {
            this->name = n;
            this->roll_no = r;
            this->semester = s;
            this->section = sec;
        }

        string GetName()
        {return name;}
        int GetRollNo()
        {return roll_no;}
        int GetSemester()
        {return semester;}
        char GetSection()
        {return section;}

};


int main()
{
    Student ob[4];
    // Can input all the values via a loop too by asking user input
    ob[0].set_all("Danyal", 84, 1, 'A');
    ob[1].set_all("Moazzam", 68, 1, 'B');
    ob[2].set_all("Ali", 54, 1, 'C');
    ob[3].set_all("Husn", 70, 1, 'A');

    for (int i = 0; i < 4; i++)
    {
        if (ob[i].GetSection() == 'A')
        {
            cout<<"Name: "<<ob[i].GetName()<<endl;
            cout<<"Roll No: "<<ob[i].GetRollNo()<<endl;
            cout<<"Semester: "<<ob[i].GetSemester()<<endl;
            cout<<"Section: "<<ob[i].GetSection()<<endl;
            cout<<endl;
        }
    }

}