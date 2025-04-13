//A company has decided to update the salaries of the employees for which updation
//is required in the payroll system so that employees can be paid according to the
//revised budget. How can you implement the concept of friend class here? Consider
//there are 2 classes. One is “Employee” having private data members (name, id,
//designation, salary etc.) and the other is “Payroll”. The function for updating
//salaries can be made inside the “Payroll” class that can access the private member
//“salary” of the “Employee” class and allow the required updation. Implement this scenario.

#include<iostream>
using namespace std;

class Employee{
	private:
	   string name;
	   int id;
	   string designation;
	   float salary;
	public:
		
		Employee(){
			name=" ";
			id=0;
			designation=" ";
			salary=0.0;
		}
		Employee(string n,int i,string d,float s){
			name=n;
	        id=i;
	        designation=d;
	        salary=s;
		}
		
		string getname(){
			return name;
		}
		int getid(){
		    return id;
		}
		string getdesignation(){
			return designation;
		}
		float getsalary(){
			return salary;
		}
		void display(){
			cout<<"ENTER YOUR NAME:"<<endl;
			cin>>name;
			cout<<"ENTER YOUR ID:"<<endl;
			cin>>id;
			cout<<"ENTER YOUR DESIGNATION:"<<endl;
			cin>>designation;
			cout<<"ENTER YOUR SALARY:"<<endl;
			cin>>salary;
		}
};

class PayRoll{
	private:
		float updatedsalary;
	public:
		PayRoll(float us=0.0){
			updatedsalary=us;
		}
		float getupdatedsalary(){
			return updatedsalary;
		}
		void calculateupdatedsalary(Employee &e,float amount){
			updatedsalary=e.getsalary()+amount;
			cout<<"UPDATED SALARY IS:"<<updatedsalary<<endl;
		}		
};

int main(void){
    Employee s;
    s.display();
    PayRoll p;
    float amount;
    cout<<"ENTER YOUR AMOUNT:"<<endl;
    cin>>amount;
    p.calculateupdatedsalary(s,amount);
    return 0;  
}

