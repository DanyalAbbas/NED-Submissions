#include<iostream>
using namespace std;

class PayRoll{};

class Employee{
	private:
	   string name;
	   int id;
	   string designation;
	   float salary;   
	public:
		Employee(string n=" ", int i=0, string d=" ", float s=0.0){
			name=n;
	        id=i;
	        designation=d;
	        salary=s;
		}
		void display() const {
			cout << "Name: " << name << endl;
			cout << "ID: " << id << endl;
			cout << "Designation: " << designation << endl;
			cout << "Salary: $" << salary << endl;
		}
		friend class PayRoll;
};

class PayRoll{
	public:
	void updateSalary(Employee& ob, float newSalary) {
        ob.salary += newSalary;
        cout << "Salary updated successfully.\n";
    }	
};

int main(void){
    Employee ob1("Willy Wonka", 69, "Choclate Factory Manager", 70000);
	PayRoll p;
    ob1.display();

    float amount = 90000;

    p.updateSalary(ob1, amount);
	ob1.display();

    return 0;  
}

